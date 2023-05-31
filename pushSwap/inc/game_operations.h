/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_operations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:42:25 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/31 11:19:47 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OPERATIONS_H
# define GAME_OPERATIONS_H
# include "push_swap.h"

void	pa(t_list **A, t_list **B);
void	pb(t_list **A, t_list **B);

void	sa(t_list **A);
void	sb(t_list **A);
void	ss(t_list **A, t_list **B);

void	ra(t_list **A);
void	rb(t_list **B);
void	rr(t_list **A, t_list **B);

void	rra(t_list **A);
void	rrb(t_list **B);
void	rrr(t_list **A, t_list **B);

#endif