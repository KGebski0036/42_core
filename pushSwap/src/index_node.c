/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:56:26 by cjackows          #+#    #+#             */
/*   Updated: 2023/05/31 14:38:52 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

int	index_node(t_list **stack, int value)
{
	int	i;

	i = 0;
	while ((*stack)->next && (*stack)->content != value)
	{
		*stack = (*stack)->next;
		i++;
	}
	if ((*stack)->content != value)
		return(-1);
	return(i);
}
