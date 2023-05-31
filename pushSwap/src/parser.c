/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:53:48 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/31 18:10:16 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../inc/push_swap.h"
#include "../libft/libft.h"

int	isnumber(char *s)
{
	int	j;

	j = 0;
	while (s[j])
	{
		if (!ft_isdigit(s[j]) && s[j] != '-' && s[j] != '+')
			return (0);
		j++;
	}
	return (1);
}

int	*parser(int argc, char **argv)
{
	int		*result;
	long	number;
	int		i;
	int		j;
	char	**input;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		result = (int *)malloc(sizeof(int) * get_number_of_words(argv[1], ' ') + 1);
		if (!result)
			return (0);
		input = ft_split(argv[1], ' ');
	}
	else
	{
		result = (int *)malloc(sizeof(int) * (argc - 1));
		if (!result)
			return (0);
		input = argv;
		i = 1;
	}
	while (input[i])
	{
		if (!isnumber(input[i]))
		{
			free(result);
			return (0);
		}
		number = ft_atoi(input[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			free(result);
			return (0);
		}
		result[j] = (int)number;
		j++;
		i++;
	}
	if (argc == 2)
		free(input);
	return (result);
}
