/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:37:40 by kgebski           #+#    #+#             */
/*   Updated: 2023/05/23 14:39:13 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	count_spaces(const char *c)
{
	unsigned int	i;

	i = 0;
	while (*c == '\f' || *c == '\n' || *c == '\r'
		|| *c == '\t' || *c == '\v' || *c == ' ')
	{
		c++;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	result_sign;
	int	result;
	int	lenght_of_ws;

	if (!*nptr)
		return (0);
	lenght_of_ws = count_spaces(nptr);
	nptr += lenght_of_ws;
	result_sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
			result_sign = -1;
	}
	result = 0;
	while (*nptr)
	{
		if (*nptr < '0' || *nptr > '9')
			break ;
		result *= 10;
		result += *nptr - '0';
		nptr++;
	}
	return (result * result_sign);
}
