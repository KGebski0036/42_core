/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:50:52 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/31 21:11:55 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "../libft/libft.h"
# include "stack_operations.h"

# include <stdio.h>

int		*parser(int argc, char *argv[]);
int		not_unique(int *tab, size_t size);
void	initialize_list(int *tab, size_t size, t_list **lst);
void	sort_stack(t_list **stack_a, t_list **stack_b);

int		is_sorted(t_list *lst);
void	sort_three(t_list **stack_a);
void 	sort_n(t_list **stack_a, t_list **stack_b, size_t n);

int		find_minimum_index(t_list *lst, size_t n);
int		find_maximum_index(t_list *lst);

int		find_minimum_val(t_list *lst);
int		find_maximum_val(t_list *lst);

void	create_part(t_list **stack_a, t_list **stack_b, int min, int max, int parts);

//*		--=[ utils.c ]=--
int		ft_abs(int	num);

//*		--=[ index_node.c ]=--
int	index_first_node(t_list *stack, int range_start, int range_end);
int	index_last_node(t_list *stack, int range_start, int range_end);

void	sort_n2(t_list **stack_a, t_list **stack_b);
#endif