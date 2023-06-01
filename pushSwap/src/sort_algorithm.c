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
#include "game_operations.h"

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
			if((*stack_b)->content < ((min + i * range) + (min + (i + 1) * range))/2 && ft_lstsize(*stack_b) > 2)
				rb(stack_b);
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

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	max;

	min = find_minimum_val(*stack_a);
	max = find_maximum_val(*stack_a);

	if (is_sorted(*stack_a))
		return ;

	if (ft_lstsize(*stack_a) > 150)
		create_part(stack_a, stack_b, min, max, ft_lstsize(*stack_a)/50);
	else if (ft_lstsize(*stack_a) > 50)
		create_part(stack_a, stack_b, min, max, ft_lstsize(*stack_a)/10);
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

int	is_sorted(t_list *lst)
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

void	sort_three(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp->next->next->content > tmp->next->content 
		&& tmp->next->next->content > tmp->content)
		sa(stack_a);
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

void	sort_n(t_list **stack_a, t_list **stack_b, size_t n)
{
	size_t	index;
	size_t	i;

	i = 0;
	index = find_minimum_index(*stack_a, n);
	if (index < n / 2)
	{
		while (i++ < index)
			ra(stack_a);
	}
	else
	{
		while (i++ < n - index)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_n2(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int val;

	index = find_maximum_index(*stack_b);
	val = find_maximum_val(*stack_b);
	if (index < (ft_lstsize(*stack_b) / 2))
	{
		while ((*stack_b)->content != val)
			rb(stack_b);
	}
	else
	{
		while ((*stack_b)->content != val)
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
}

int	find_minimum_index(t_list *lst, size_t n)
{
	size_t	index_min;
	size_t	i;
	int		min;

	index_min = 0;
	i = 0;
	if (lst)
		min = lst->content;
	while (lst && i < n)
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

int	find_maximum_index(t_list *lst)
{
	size_t	index_max;
	size_t	i;
	int		max;

	index_max = 0;
	i = 0;
	if (lst)
		max = lst->content;
	while (lst)
	{
		if (lst->content > max)
		{
			index_max = i;
			max = lst->content;
		}
		i++;
		lst = lst->next;
	}
	return (index_max);
}

int	find_minimum_val(t_list *lst)
{
	int		min;

	if (lst)
		min = lst->content;
	while (lst)
	{
		if (lst->content < min)
		{
			min = lst->content;
		}
		lst = lst->next;
	}
	return (min);
}

int	find_maximum_val(t_list *lst)
{
	int		max;

	if (lst)
		max = lst->content;
	while (lst)
	{
		if (lst->content > max)
		{
			max = lst->content;
		}
		lst = lst->next;
	}
	return (max);
}

