/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:25:01 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/23 16:56:19 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_treat(const char *s, int *i, va_list args, int *size)
{
	*i += 1;
	if (s[*i] == '-')
		do_flag_minus(s, i, args, size);
	else if (s[*i] == '+' || s[*i] == ' ')
		do_flag_plus_space(s, i, args, size);
	else if (s[*i] == '#')
		do_flag_hashtag(s, i, args, size);
	else if (s[*i] == '0')
		do_flag_zero(s, i, args, size);
	else if (s[*i] == '.')
		do_flag_point(s, i, args, size);
	else
	{
		if (s[*i] == '1')
		{
			*size += ft_putchar(' ');
			*i += 1;
		}
		ft_convert(s[*i], args, size);
	}
}

int	ft_printf(const char *s, ...)
{
	int		size;
	int		i;
	va_list	args;

	size = 0;
	i = -1;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%')
			ft_treat(s, &i, args, &size);
		else
			size += ft_putchar(s[i]);
	}
	va_end(args);
	return (size);
}
