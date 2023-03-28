/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:52:48 by ichiro            #+#    #+#             */
/*   Updated: 2023/03/28 18:25:13 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_alarm(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write (1, &str[i], 1);
			i++;
		}
	}
	exit(1);
}

void	print_stacks(t_list **stack_a)
{
	t_list	*a;

	a = *stack_a;
	printf("\nA\n-\n");
	while (a != NULL)
	{
		if (a)
		{
			printf("%d\n", a->num);
			a = a->next;
		}
	}
	printf("\n");
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			neg;
	long long	res;

	i = 0;
	res = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		neg = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			res = res * 10 + nptr[i] - 48;
		else
			error_alarm("Error1\n");
		i++;
	}
	res = res * neg;
	if (res > 2147483647 || res < -2147483648)
		error_alarm("Error2\n");
	return (res);
}
