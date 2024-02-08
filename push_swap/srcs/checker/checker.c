/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:23:43 by tgriblin          #+#    #+#             */
/*   Updated: 2024/02/08 14:56:02 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

int	ps_do_checker(char *move, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(move, "sa\n") || !ft_strcmp(move, "ss\n"))
		return (ps_swap(a), 1);
	if (!ft_strcmp(move, "sb\n") || !ft_strcmp(move, "ss\n"))
		return (ps_swap(b), 1);
	if (!ft_strcmp(move, "pa\n"))
		return (ps_push(b, a), 1);
	if (!ft_strcmp(move, "pb\n"))
		return (ps_push(a, b), 1);
	if (!ft_strcmp(move, "ra\n") || !ft_strcmp(move, "rr\n"))
		return (ps_rotate(a), 1);
	if (!ft_strcmp(move, "rb\n") || !ft_strcmp(move, "rr\n"))
		return (ps_rotate(b), 1);
	if (!ft_strcmp(move, "rra\n") || !ft_strcmp(move, "rrr\n"))
		return (ps_rrotate(a), 1);
	if (!ft_strcmp(move, "rrb\n") || !ft_strcmp(move, "rrr\n"))
		return (ps_rrotate(b), 1);
	return (0);
}

int	read_stdin(t_stack *a, t_stack *b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (!ps_do_checker(move, a, b))
			return (free(move), 0);
		free(move);
		if (is_sorted(a->array, a->size, 1) && !b->size)
			return (1);
		move = get_next_line(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack *b;

	if (ac < 2)
		return (1);
	a = fill_stack(ac - 1, av + 1, 0);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	b = malloc(sizeof(t_stack));
	b->array = NULL;
	b->size = 0;
	if (!is_sorted(a->array, a->size, 1))
	{
		ft_convert(a);
		if (read_stdin(a, b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
