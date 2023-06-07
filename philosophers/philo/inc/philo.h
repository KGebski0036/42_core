/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:40:52 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/07 13:37:34 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_philosopher
{
	int					id;
	int					left_fork;
	int					right_fork;
	long long			last_eat;
	int					meals;
	struct s_rules		*mediator;
	pthread_t			thread;
} t_philosopher;

typedef struct s_mediator
{
	int	philo_couter;
	int	time_to_death;
	int	time_to_eat;
	int	time_to_sleep;
	
	int notepme;
	int curent_eat;
	
	int deaths;
	
	pthread_mutex_t mutex_print;
	pthread_mutex_t meal_check;
	pthread_mutex_t *forks;

	t_philosopher		*philos;
	
} t_mediator;

//       --=[ init.c ]=--       //
int	check_input_init(int ac, char **av, t_mediator *med);
int	init_philo_forks(t_mediator *med);

#endif