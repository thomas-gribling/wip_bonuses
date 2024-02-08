/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:59:36 by tgriblin          #+#    #+#             */
/*   Updated: 2024/02/08 11:33:00 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 1000

# include "push_swap.h"
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	*free_null(void *ptr1, void *ptr2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);

int		ps_swap(t_stack *stack);
int		ps_rotate(t_stack *stack);
int		ps_rrotate(t_stack *stack);
int		ps_push(t_stack *from, t_stack *to);

#endif