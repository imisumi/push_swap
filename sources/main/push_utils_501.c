/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils_501.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:24:02 by ichiro            #+#    #+#             */
/*   Updated: 2023/05/08 13:43:35 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end(t_list **a, t_list **b)
{
	if (check_sorted_a(a) == 0 && size_of(b) == 0)
	{
		free_list(a);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

void	sort_final(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	fast;

	max = 0;
	fast = 0;
	max = size_of(stack_b) - 1;
	while (*stack_b)
	{
		if ((*stack_b)->index == max)
		{
			pa(stack_a, stack_b);
			max--;
		}
		else
		{
			fast = fastest_push(stack_b, max);
			if (fast == 1)
				sb(stack_b);
			else if (fast == 2)
				rb(stack_b);
			else if (fast == 3)
				rrb(stack_b);
		}
	}
	end(stack_a, stack_b);
}

void	last_chunk_two(t_list **a, t_list **b, int tmp, int tmp2)
{
	int	i;

	while (*b)
	{
		pa(a, b);
		tmp2++;
	}
	i = tmp2;
	while (i != 0)
	{
		pb(a, b);
		if ((*b)->index < tmp2 / 2)
			rb(b);
		i--;
	}
	i = tmp;
	while (i != 0)
	{
		pb(a, b);
		if ((*b)->index < tmp2 + (tmp / 2))
			rb(b);
		i--;
	}
	sort_final(a, b);
}

void	last_chunk_one(t_list **a, t_list **b)
{
	int	tmp;
	int	tmp2;
	int	size;
	int	i;

	tmp = 0;
	tmp2 = 0;
	size = size_of(b);
	i = size;
	while (i != 0)
	{
		if ((*b)->index > (size / 2))
		{
			pa(a, b);
			tmp++;
		}
		else
			rb(b);
		i--;
	}
	last_chunk_two(a, b, tmp, tmp2);
}
