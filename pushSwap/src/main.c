/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:47:02 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/30 17:12:37 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	print_stacks(t_list *a, t_list *b)
{
	t_list	*tmpa;
	t_list	*tmpb;

	tmpa = a;
	tmpb = b;
	ft_putstr_fd("__A__     __B__\n", 1);
	while (!(tmpa == 0 && tmpb == 0))
	{
		if (tmpa != 0)
		{
			ft_putnbr_fd(tmpa->content, 1);
			tmpa = tmpa->next;
		}
		ft_putstr_fd("         ", 1);
		if (tmpb != 0)
		{
			ft_putnbr_fd(tmpb->content, 1);
			tmpb = tmpb->next;
		}
		ft_putendl_fd("", 1);
	}
}

int	main(int argc, char *argv[])
{
	int		*tab_of_numbers;
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc == 1)
	{
		ft_putstr_fd("No arguments provided!\n", 1);
		return (0);
	}
	tab_of_numbers = parser(argc, argv);
	if (tab_of_numbers == 0 || not_unique(tab_of_numbers, argc - 1))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	initialize_list(tab_of_numbers, argc - 1, stack_a);
	print_stacks(*stack_a, *stack_b);
	free(tab_of_numbers);
	return (0);
}
