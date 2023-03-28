/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:20:36 by ichiro            #+#    #+#             */
/*   Updated: 2023/03/27 04:57:25 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_stack(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*prev;

	first = *stack;
	last = *stack;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
		last->previous = prev;
	}
	*stack = first->next;
	last->next = first;
	first->next = NULL;
	return ;
}

void	ra(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	rotate_stack(stack_a);
	return ;
}

void	rb(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rotate_stack(stack_b);
	return ;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL || \
	(*stack_a)->next == NULL || (*stack_b)->next == NULL)
		return ;
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	return ;
}
