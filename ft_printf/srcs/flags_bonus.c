/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:27:25 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/23 17:00:02 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_width(const char *s, int *i, va_list args)
{
	char	c;
	int		width;

	c = s[*i];
	if (c == '*')
	{
		width = va_arg(args, int);
		*i += 1;
	}
	else
	{
		width = ft_atoi(s + *i);
		while (s[*i] >= '0' && s[*i] <= '9')
			*i += 1;
	}
	return (width);
}

int	get_size(char c, va_list args, long *n, unsigned int *u)
{
	if (c == 'd' || c == 'i')
	{
		*n = va_arg(args, int);
		return (ll_len(*n, 10));
	}
	if (c == 'u')
	{
		*u = va_arg(args, unsigned int);
		return (ll_len(*u, 10));
	}
	if (c == 'x' || c == 'X')
	{
		*u = va_arg(args, unsigned int);
		return (ll_len(*u, 16));
	}
	return (0);
}

void	write_val(char c, long n, unsigned int u, int *size)
{
	if (c == 'd' || c == 'i')
		ft_putbase(n, 10, "0123456789", size);
	if (c == 'u')
		ft_putbase(u, 10, "0123456789", size);
	if (c == 'x')
		ft_putbase(u, 16, "0123456789abcdef", size);
	if (c == 'X')
		ft_putbase(u, 16, "0123456789ABCDEF", size);
}

void	do_flag_point(const char *s, int *i, va_list args, int *size)
{
	do_flag_zero(s, i, args, size);
}

void	do_flag_minus(const char *s, int *i, va_list args, int *size)
{
	int	width;
	int	tmp;
	int	j;

	*i += 1;
	if (s[*i] == '*')
		width = va_arg(args, int);
	else if (s[*i] >= '0' && s[*i] <= '9')
		width = ft_atoi(s + *i);
	else
		return ;
	while (s[*i] == '*' || (s[*i] >= '0' && s[*i] <= '9'))
		*i += 1;
	tmp = 0;
	ft_convert(s[*i], args, &tmp);
	*size += tmp;
	width = ft_max(0, width - tmp);
	j = -1;
	while (++j < width)
		*size += ft_putchar(' ');
}

void	do_flag_plus_space(const char *s, int *i, va_list args, int *size)
{
	int		val;
	char	*str;
	char	c;

	*i += 1;
	c = s[*i];
	if (c != 'd' && c != 'i' && c != 's')
		return ;
	if (c == 's' && s[*i - 1] != ' ')
		return ;
	if (c == 's')
	{
		str = va_arg(args, char *);
		*size += ft_putstr(str);
	}
	else
	{
		val = va_arg(args, int);
		if (val >= 0)
			*size += ft_putchar(s[*i - 1]);
		ft_putbase(val, 10, "0123456789", size);
	}
}

void	do_flag_hashtag(const char *s, int *i, va_list args, int *size)
{
	unsigned int	val;
	char			c;

	*i += 1;
	c = s[*i];
	if (c != 'x' && c != 'X')
		return ;
	val = va_arg(args, unsigned int);
	if (val > 0)
	{
		*size += ft_putchar('0');
		*size += ft_putchar(c);
	}
	if (c == 'x')
		ft_putbase(val, 16, "0123456789abcdef", size);
	else
		ft_putbase(val, 16, "0123456789ABCDEF", size);
}

void	do_flag_zero(const char *s, int *i, va_list args, int *size)
{
	int				width;
	int				len;
	int				j;
	long			n;
	unsigned int	u;

	*i += 1;
	if (s[*i] != '*' && s[*i] < '0' && s[*i] > '9')
		return ;
	width = get_width(s, i, args);
	if (s[*i] != 'd' && s[*i] != 'i' && s[*i] != 'u')
		if (s[*i] != 'x' && s[*i] != 'X')
			return ;
	n = 0;
	u = 0;
	len = get_size(s[*i], args, &n, &u);
	j = -1;
	if (n < 0)
	{
		*size += ft_putchar('-');
		n = -n;
	}
	while (++j < width - len)
		*size += ft_putchar('0');
	write_val(s[*i], n, u, size);
}
