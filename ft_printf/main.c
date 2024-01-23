/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:47:43 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/23 17:05:06 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

void	check_returns(int *returns)
{
	if (returns[0] == returns[1])
		printf("return value: OK\n\n");
	else
		printf("return value: KO (%d:%d)\n\n", returns[0], returns[1]);
}

int	main(void)
{
	printf(" [%.2s] [%.1s] \n", "", "-");
	printf(" [%.3s] [%.2s] \n", " - ", "");
	printf(" [%.1s] [%.2s] [%.3s] [%.4s] \n", " - ", "", "4", "");
	printf(" [%.2d] \n", -1);
	print(" %.12d ", 4294967295);
	printf(" %.14d ", 9223372036854775807LL);

}
