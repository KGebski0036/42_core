/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:43:26 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/30 19:58:55 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_operations.h"

// void	operation_sa(t_list **stack_a)
// {
	
// }

/**
 * @brief Push first element from "stack" src to dst. 
 */
void	do_push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	tmp = *dst;
	if (*src == 0)
	{
		ft_putstr_fd("Stack SRC is empty, nothing to push\n", 1);
		return ;
	}
	*dst = *src;
	(*src) = (*src)->next;
	(*dst)->next = tmp;
}

void	swap_stack(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		ft_putstr_fd("Stack is empty or has too little nodes\n", 1);
		return;
	}
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}
