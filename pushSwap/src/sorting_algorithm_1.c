/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:26:43 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/31 21:17:01 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list *lst)
{
	if (lst)
		while (lst->next)
		{
			if (lst->content > lst->next->content)
				return (0);
			lst = lst->next;
		}
	return (1);
}

//! TOO MANY LINES
void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	max;

	min = find_minimum_val(*stack_a);
	max = find_maximum_val(*stack_a);

	if (is_sorted(*stack_a))
		return ;

	if (ft_lstsize(*stack_a) > 50)
		create_part(stack_a, stack_b, min, max, 5);
	else if (ft_lstsize(*stack_a) > 300)
		create_part(stack_a, stack_b, min, max, 11);
	else
	{
		while (!is_sorted(*stack_a) || ft_lstsize(*stack_b) != 0)
		{
			if (ft_lstsize(*stack_a) == 2)
				sa(stack_a);
			else if (ft_lstsize(*stack_a) < 4)
			{
				sort_three(stack_a);
				while (ft_lstsize(*stack_b) > 0)
					pa(stack_a, stack_b);
			}
			else
				sort_n(stack_a, stack_b, ft_lstsize(*stack_a));
		}
	}
}

//! TOO MANY LINES
void	create_part(t_list **stack_a, t_list **stack_b, int min, int max, int parts)
{
	int	range;
	int first_n;
	int last_n;
	int i;
	int j;
	
	i = 0;
	range = ft_abs(min - max) / parts + ft_abs(min - max) % parts;
	while (i < parts)
	{
		first_n = index_first_node(*stack_a, min + i * range, min + (i + 1) * range);
		while (first_n != -1)
		{
			j = 0;
			last_n = index_last_node(*stack_a, min + i * range, min + (i + 1) * range);
			if (first_n < ft_lstsize(*stack_a) - last_n)
			{
				while (first_n--)
					ra(stack_a);
			}
			else
			{
				while (j++ < ft_lstsize(*stack_a) - last_n)
					rra(stack_a);
			}	
			pb(stack_a, stack_b);
			last_n = index_last_node(*stack_a, min + i * range, min + (i + 1) * range);
			first_n = index_first_node(*stack_a, min + i * range, min + (i + 1) * range);
		}
		i++;
	}
	while (ft_lstsize(*stack_b) != 0)
	{
		sort_n2(stack_a, stack_b);
	}
}
