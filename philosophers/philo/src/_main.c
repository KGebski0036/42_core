/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:39:35 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/07 13:06:49 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_mediator mediator;
	
	if (!check_input(ac, av, &mediator))
		ft_printf("Invalid input.");
	if (!init_philo_forks(&mediator))
		ft_printf("Invalid input.");
	
	return (0);
}
