/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:26:43 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/31 14:54:10 by kgebski          ###   ########.fr       */
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
			while(ft_lstsize(*stack_b) > 0)
				pa(stack_a, stack_b);
		}
		else
		{
			sort_n(stack_a, stack_b, ft_lstsize(*stack_a));
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
	//ft_putstr_fd("sorted!!!\n", 1);
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

void sort_n(t_list **stack_a, t_list **stack_b, size_t n)
{
	size_t	index;
	int		i;
	
	i = 0;
	index = find_minimum(*stack_a, n);
	if (index < n / 2)
	{
		while(i++ < index)
			ra(stack_a);
	}
	else
	{
		while(i++ < n - index)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

int find_minimum(t_list *lst, size_t n)
{
	size_t	index_min;
	size_t	i;
	int		min;
	
	index_min = 0;
	i = 0;
	if (lst)
		min = lst->content;
	while(lst)
	{
		if (lst->content < min)
		{
			index_min = i;
			min = lst->content;
		}
		i++;
		lst = lst->next;
	}
	return (index_min);
}