/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:42:25 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/31 11:00:46 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPERATIONS_H
# define STACK_OPERATIONS_H
# include "push_swap.h"

void	do_push(t_list **src, t_list **dst);
void	swap_stack(t_list **stack);
void	move_node_to_end(t_list **stack);
void	move_last_node_to_top(t_list **stack);

#endif