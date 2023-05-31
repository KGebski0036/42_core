/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:26:43 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/31 13:07:20 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "game_operations.h"

void	sort_stack(t_list **stack_a, t_list **stack_b, size_t size)
{
	while(!is_sorted(*stack_a) || size != ft_lstsize(*stack_a))
	{
		if (ft_lstsize(*stack_a) < 4)
		{
			sort_three(stack_a);
			if (is_sorted(*stack_a) && size == ft_lstsize(*stack_a))
				return ;
		}
	}
}

int	is_sorted(t_list *lst)
{
	while(lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	ft_putstr_fd("sorted!!!\n", 1);
	return (1);
}

void sort_three(t_list **stack_a)
{
	t_list	*tmp;

	if (tmp->next->next->content > tmp->next->content 
		&& tmp->next->next->content > tmp->content)
	{
		sa(stack_a);
	}
	else if (tmp->next->content > tmp->next->next->content 
		&& tmp->next->content > tmp->content)
	{
		if (tmp->content > tmp->next->next->content)
			rra(stack_a);
		else
		{
			sa(stack_a);
			ra(stack_a);
		}
	}
	else if (tmp->next->content > tmp->next->next->content)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else
		ra(stack_a);
}