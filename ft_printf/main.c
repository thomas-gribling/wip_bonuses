/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:47:43 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/23 16:17:49 by tgriblin         ###   ########.fr       */
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
	printf("[%1s]\n", "");
	printf("[%-s]\n", "-");
	ft_printf("[%1s]\n", "");
	ft_printf("[%-s]\n", "-");
	//printf(" %2p \n", -1);

}
