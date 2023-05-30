/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:42:25 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/30 19:26:33 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPERATIONS_H
# define STACK_OPERATIONS_H
# include "push_swap.h"

void	operation_sa(t_list **stack_a);
void	do_push(t_list **src, t_list **dst);
void	swap_stack(t_list **stack);

#endif