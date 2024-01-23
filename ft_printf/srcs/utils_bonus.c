/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:31:25 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/23 14:43:04 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	sign_count;
	int	out;

	i = 0;
	sign = 1;
	sign_count = 0;
	out = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
		sign_count++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && sign_count < 2)
	{
		out = 10 * out + nptr[i] - '0';
		i++;
	}
	return (sign * out);
}

int	ll_len(long long n, int base)
{
	int	size;
	
	size = 1;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > base - 1)
	{
		n /= base;
		size++;
	}
	return (size);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
