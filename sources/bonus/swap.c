/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:20:06 by ichiro            #+#    #+#             */
/*   Updated: 2023/03/27 05:00:54 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*sec;
	t_list	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	sec = first->next;
	temp = sec->next;
	*stack_a = sec;
	sec->next = first;
	first->next = temp;
	return ;
}

void	sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*sec;
	t_list	*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	sec = first->next;
	temp = sec->next;
	*stack_b = sec;
	sec->next = first;
	first->next = temp;
	return ;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
