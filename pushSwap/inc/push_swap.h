/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:50:52 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/31 12:55:33 by kgebski          ###   ########.fr       */
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
void	sort_stack(t_list **stack_a, t_list **stack_b, size_t size);

int		is_sorted(t_list *lst);
void	sort_three(t_list **stack_a);
#endif