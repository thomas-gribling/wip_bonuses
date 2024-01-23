/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:43:51 by tgriblin          #+#    #+#             */
/*   Updated: 2023/11/22 10:46:12 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
			ft_convert(s[++i], args, &size);
		else
			size += ft_putchar(s[i]);
	}
	va_end(args);
	return (size);
}
