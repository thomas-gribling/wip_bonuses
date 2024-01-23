/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:56:22 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/23 08:46:59 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

void	ft_putbase(long long n, int base_len, char *base, int *size)
{
	if (n < 0)
	{
		*size += ft_putchar('-');
		n = -n;
	}
	if (n > base_len - 1)
		ft_putbase(n / base_len, base_len, base, size);
	*size += ft_putchar(base[n % base_len]);
}

void	ft_putptr(unsigned long address, int *size, int first)
{
	if (first)
		*size += ft_putstr("0x");
	if (address > 15)
		ft_putptr(address / 16, size, 0);
	*size += ft_putchar("0123456789abcdef"[address % 16]);
}

void	ft_convert(char c, va_list args, int *size)
{
	unsigned long	address;

	if (c == 'c')
		*size += ft_putchar(va_arg(args, int));
	if (c == 's')
		*size += ft_putstr(va_arg(args, char *));
	if (c == 'p')
	{
		address = va_arg(args, unsigned long);
		if (!address)
			*size += ft_putstr("(nil)");
		else
			ft_putptr(address, size, 1);
	}
	if (c == 'd' || c == 'i')
		ft_putbase(va_arg(args, int), 10, "0123456789", size);
	if (c == 'u')
		ft_putbase(va_arg(args, unsigned int), 10, "0123456789", size);
	if (c == 'x')
		ft_putbase(va_arg(args, unsigned int), 16, "0123456789abcdef", size);
	if (c == 'X')
		ft_putbase(va_arg(args, unsigned int), 16, "0123456789ABCDEF", size);
	if (c == '%')
		*size += ft_putchar('%');
}
