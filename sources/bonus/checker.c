/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:26:02 by ichiro            #+#    #+#             */
/*   Updated: 2023/03/28 18:26:02 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
// #include "../../includes/checker.h"

void	do_action(char *line, t_list **a, t_list **b)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
}

int	check_sorted(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	current = *stack_a;
	if (*stack_b)
		return (1);
	while (current->next != NULL)
	{
		if (current->num > current->next->num)
			return (1);
		current = current->next;
	}
	return (0);
}

void	create_list(t_list **stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	if (!ft_strcmp(argv[1], "-p"))
		i++;
	while (i < argc)
	{
		new_node(stack_a, ft_atoi(argv[i]));
		i++;
	}
}

void	get_input(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		do_action (line, stack_a, stack_b);
		free(line);
	}
}

int	main(int argc, char *argv[])
{
	int		p_flag;
	char	*line;
	t_data	data;

	data.stack_a = NULL;
	data.stack_b = NULL;
	if (argc == 1)
		return (0);
	if (!ft_strcmp(argv[1], "-p"))
		p_flag = 1;
	else
		p_flag = 0;
	create_list(&data.stack_a, argc, argv);
	get_input(&data.stack_a, &data.stack_b);
	if (p_flag)
		print_stacks(&data.stack_a);
	if (check_sorted(&data.stack_a, &data.stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
