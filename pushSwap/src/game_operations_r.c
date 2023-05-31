/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_operations_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:43:26 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/31 18:18:18 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_operations.h"
#include "game_operations.h"

void	ra(t_list **A)
{
	move_node_to_end(A);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **B)
{
	move_node_to_end(B);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **A, t_list **B)
{
	move_node_to_end(A);
	move_node_to_end(B);
	ft_putstr_fd("rr\n", 1);
}
