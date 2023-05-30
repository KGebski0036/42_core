/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:47:02 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/30 13:28:39 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	int	*tab_of_numbers;

	if (argc == 1)
	{
		ft_putstr_fd("No arguments provided!\n", 1);
		return (0);
	}
	tab_of_numbers = parser(argc, argv);
	if (tab_of_numbers == 0 || not_unique(tab_of_numbers, argc - 1))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	//Test
	ft_putstr_fd("tab: ", 1);
	for (int i = 0; i < argc - 1; i++)
	{
		ft_putnbr_fd(tab_of_numbers[i], 1);
		ft_putstr_fd(" ", 1);
	}
	//Test
	free(tab_of_numbers);
	return (0);
}
