/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:53:48 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/30 16:34:20 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "libft.h"

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

	result = (int *)malloc(sizeof(int) * (argc - 1));
	if (!result)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!isnumber(argv[i]))
		{
			free(result);
			return (0);
		}
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			free(result);
			return (0);
		}
		result[i - 1] = (int)number;
		i++;
	}
	return (result);
}
