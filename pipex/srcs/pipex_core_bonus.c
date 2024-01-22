/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_core_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:01:08 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/22 09:01:22 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	call_pipex(t_pipex *px, char **av, char **envp, int curr)
{
	if (curr == 0)
		first(px, av, envp);
	else
		middle(px, av, envp, curr);
}
