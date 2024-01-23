/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:55:25 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/23 14:43:31 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
void	ft_convert(char c, va_list args, int *size);

int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putbase(long long n, int base_len, char *base, int *size);
void	ft_putptr(unsigned long address, int *size, int first);

// BONUS
void	do_flag_minus(const char *s, int *i, va_list args, int *size);
void	do_flag_plus_space(const char *s, int *i, va_list args, int *size);
void	do_flag_hashtag(const char *s, int *i, va_list args, int *size);
void	do_flag_zero(const char *s, int *i, va_list args, int *size);

int		ft_max(int a, int b);
int		ft_atoi(const char *nptr);
int		ll_len(long long n, int base);
int		ft_strlen(char *str);

#endif