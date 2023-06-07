/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:49:36 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/07 13:36:30 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input_init(int ac, char **av, t_mediator *med)
{
	if (ac < 5 || ac > 6)
		return 0;
	
	med->philo_couter = ft_atoi(av[1]);
	med->time_to_death = ft_atoi(av[2]);
	med->time_to_eat = ft_atoi(av[3]);
	med->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		med->notepme = ft_atoi(av[5]);
	else
		med->notepme = 0;
	med->curent_eat = 0;
	med->deaths = 0;
	if (med->philo_couter < 1 || med->time_to_death < 0 || med->time_to_eat < 0
		|| med->time_to_sleep < 0)
		return (0);
	if (av[5] && med->notepme < 1)
		return (0);
	return (1);
}

int init_philo_forks(t_mediator *med)
{
	int i;

	i = 0;
	med->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * med->philo_couter);
	med->philos = (t_philosopher *)malloc(sizeof(t_philosopher) * med->philo_couter);
	while (i < med->philo_couter)
	{
		if (pthread_mutex_init(&(med->forks[i]), NULL))
			return (0);
			
		med->philos[i].id = i;
		med->philos[i].left_fork = i;
		med->philos[i].right_fork = (i + 1) % med->philo_couter;
		med->philos[i].last_eat = 0;
		med->philos[i].meals = 0;
		med->philos[i].mediator = med;
	}
	if (pthread_mutex_init(&(med->mutex_print), NULL))
		return (0);
	if (pthread_mutex_init(&(med->meal_check), NULL))
		return (0);
}