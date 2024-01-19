/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:44:49 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/18 15:05:04 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"
# include <stdio.h>

typedef struct s_pipex
{
	int			cmd_amt;
	int			**pipe;
	int			pipe_here_doc[2];
	pid_t		p;
	int			here_d;
}				t_pipex;

void	do_pipex(int ac, char **av, char **envp);
char	**get_paths(char **envp);

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);

#endif