/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:08:26 by tgriblin          #+#    #+#             */
/*   Updated: 2024/02/08 15:02:01 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>

int	is_bound(t_stack *stack, int val, int change, int total)
{
	if (val == total - 1 && change == 1)
		return (1);
	if (!val && change == -1)
		return (1);
	val += change;
	while (val >= 0 && val < total)
	{
		if (stack_scan(stack, val, val))
			return (0);
		val += change;
	}
	return (1);
}

int	get_nearest(t_stack *a, int val, int total)
{
	int	near[2];
	int	i;

	near[0] = -1;
	near[1] = -1;
	i = val + 1;
	while (i-- && i >= 0 && near[0] < 0)
		if (stack_scan(a, i, i))
			near[0] = i;
	i = val - 1;
	while (i++ && i < total && near[1] < 0)
		if (stack_scan(a, i, i))
			near[1] = i;
	if (near[0] < 0)
		return (near[1]);
	if (near[1] < 0)
		return (near[0]);
	if (val - near[0] > near[1] - val)
		return (near[1]);
	return (near[0]);
}

void	push_back(t_stack *a, t_stack *b)
{
	while (b->size > 0 && a->size > 0)
	{
		return ;
	}
}

void	ft_sort(t_stack *a)
{
	t_stack	*b;
	size_t	size;

	b = malloc(sizeof(t_stack));
	b->size = 0;
	b->array = NULL;
	ft_convert(a);
	size = a->size - 1;
	while (a->size > 3)
	{
		if (a->array[0] > (int)size / 2)
		{
			ps_do("pb", a, b);
			ps_do("rb", NULL, b);
		}
		else
			ps_do("pb", a, b);
	}
	ft_sort_three(a);
	push_back(a, b);
	free_stack(&b);
}
