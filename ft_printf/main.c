/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:47:43 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/23 10:50:39 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	returns[2];

	returns[0] = printf("printf:    [%-*s]\n", 42, "hi");
	returns[1] = ft_printf("ft_printf: [%-*s]\n", 42, "hi");
	printf("%d:%d\n\n", returns[0], returns[1]);
	returns[0] = printf("printf:    [%+d] [%+i] [%+d]\n", 42, -33, 0);
	returns[1] = ft_printf("ft_printf: [%+d] [%+i] [%+d]\n", 42, -33, 0);
	printf("%d:%d\n\n", returns[0], returns[1]);
	returns[0] = printf("printf:    [% d] [% i] [% d]\n", 42, -33, 0);
	returns[1] = ft_printf("ft_printf: [% d] [% i] [% d]\n", 42, -33, 0);
	printf("%d:%d\n\n", returns[0], returns[1]);
	returns[0] = printf("printf:    [%#x] [%#X]\n", 42, 66);
	returns[1] = ft_printf("ft_printf: [%#x] [%#X]\n", 42, 66);
	printf("%d:%d\n\n", returns[0], returns[1]);
	returns[0] = printf("printf:    [%0*d] [%042x]\n", 9, 10, 66);
	returns[1] = ft_printf("ft_printf: [%0*d] [%042x]\n", 9, 10, 66);
	printf("%d:%d\n", returns[0], returns[1]);
}
