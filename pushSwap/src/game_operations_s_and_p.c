/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_operations_s_and_p.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:43:26 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/31 11:30:50 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_operations.h"
#include "game_operations.h"

void	pa(t_list **A, t_list **B)
{
	do_push(A, B);
	ft_putstr_fd("PA\n", 1);
}

void	pb(t_list **A, t_list **B)
{
	do_push(B, A);
	ft_putstr_fd("PB\n", 1);
}

void	sa(t_list **A)
{
	swap_stack(A);
	ft_putstr_fd("SA\n", 1);
}

void	sb(t_list **B)
{
	swap_stack(B);
	ft_putstr_fd("SB\n", 1);
}

void	ss(t_list **A, t_list **B)
{
	swap_stack(A);
	swap_stack(B);
	ft_putstr_fd("SS\n", 1);
}
