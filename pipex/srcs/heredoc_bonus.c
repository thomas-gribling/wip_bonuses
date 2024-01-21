/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:40:59 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/21 19:30:44 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/pipex_bonus.h"
#include "../include/gnl.h"

void	first_heredoc(t_pipex *px, char **av, char **envp)
{
	t_cmd	*cmd;
	char	**paths;

	dup2(px->pipe_here_doc[0], 0); // crashes
	dup2(px->pipe[0][1], 1);
	close(px->pipe_here_doc[0]);
	close(px->pipe[0][0]);
	paths = get_paths(envp);
	cmd = cmd_get(paths, av[3]);
	tab_free(paths);
	if (!cmd)
	{
		close(px->pipe_here_doc[0]);
		close(px->pipe[0][1]);
		ft_initferror("pipex: command not found: %s", av[3]);
	}
	execve(cmd->path, cmd->args, envp);
}

void	middle_heredoc(t_pipex *px, char **av, char **envp, int curr)
{
	t_cmd	*cmd;
	char	**paths;
	int		i;

	dup2(px->pipe[curr - 1][0], 0);
	dup2(px->pipe[curr][1], 1);
	i = -1;
	while (++i < curr - 1)
	{
		close(px->pipe[i][0]);
		close(px->pipe[i][1]);
	}
	close(px->pipe[curr - 1][1]);
	close(px->pipe[curr][0]);
	paths = get_paths(envp);
	cmd = cmd_get(paths, av[3 + curr]);
	tab_free(paths);
	if (!cmd)
	{
		close(px->pipe[curr - 1][0]);
		close(px->pipe[curr][1]);
		ft_initferror("pipex: command not found: %s", av[3 + curr]);
	}
	execve(cmd->path, cmd->args, envp);
}

void	last_heredoc(t_pipex *px, char **av, char **envp)
{
	t_cmd	*cmd;
	char	**paths;
	int		fd;
	int		i;

	fd = open(av[px->cmd_amt + 3], O_CREAT | O_TRUNC | O_WRONLY, 0000644);
	if (fd < 0)
		ft_initferror("pipex: permission denied: %s", av[px->cmd_amt + 3]);
	dup2(fd, 1);
	dup2(px->pipe[px->cmd_amt - 2][0], 0);
	i = -1;
	while (++i < px->cmd_amt - 2)
	{
		close(px->pipe[i][0]);
		close(px->pipe[i][1]);
	}
	close(px->pipe[px->cmd_amt - 2][1]);
	paths = get_paths(envp);
	cmd = cmd_get(paths, av[px->cmd_amt + 2]);
	tab_free(paths);
	if (!cmd)
	{
		close(fd);
		close(px->pipe[px->cmd_amt - 2][0]);
		ft_initferror("pipex: command not found: %s", av[px->cmd_amt + 2]);
	}
	execve(cmd->path, cmd->args, envp);
}

void	call_heredoc(t_pipex *px, char **av, char **envp, int curr)
{
	if (curr == 0)
		first_heredoc(px, av, envp);
	else
		middle_heredoc(px, av, envp, curr);
}

void	read_heredoc(t_pipex *px, char **av)
{
	char	*line;
	char	*limiter;

	dup2(0, px->pipe_here_doc[1]);
	close(px->pipe_here_doc[0]);
	limiter = ft_strjoin(av[2], "\n", 0);
	write(0, "pipex heredoc> ", 16);
	line = get_next_line(0);
	while (ft_strcmp(line, limiter))
	{
		free(line);
		write(0, "pipex heredoc> ", 15);
		line = get_next_line(0);
	}
	free(limiter);
}

void	do_heredoc(int ac, char **av, char **envp)
{
	t_pipex	*px;
	int		i;

	px = malloc(sizeof(t_pipex));
	px->cmd_amt = ac - 4;
	px->pipe = malloc((px->cmd_amt - 1) * sizeof(int *));
	if (pipe(px->pipe_here_doc))
		ft_initerror("pipex: pipe error");
	read_heredoc(px, av);
	i = -1;
	while (++i < px->cmd_amt - 1)
	{
		px->pipe[i] = malloc(2 * sizeof(int));
		if (pipe(px->pipe[i]))
			ft_initerror("pipex: pipe error");
		px->p = fork();
		if (px->p < 0)
			ft_initerror("pipex: fork error");
		if (px->p == 0)
			call_heredoc(px, av, envp, i);
	}
	last_heredoc(px, av, envp);
}
