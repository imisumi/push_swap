/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:27:56 by ichiro            #+#    #+#             */
/*   Updated: 2023/03/28 18:53:45 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 8

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_list
{
	int				num;
	int				index;
	int				divide[32];
	int				group;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_data;

void	new_node(t_list **stack_a, int number);
void	error_alarm(char *str);
void	print_stacks(t_list **stack_a);
int		ft_atoi(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);
void	do_action(char *line, t_list **a, t_list **b);
int		check_sorted(t_list **stack_a, t_list **stack_b);
void	create_list(t_list **stack_a, int argc, char **argv);
void	get_input(t_list **stack_a, t_list **stack_b);

// GET NEXT LINE
char	*get_next_line(int fd);
char	*gnl_strdup(char *s);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(const char *s);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strchr(const char *s, int c);

// SWAP
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

// PUSH
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

// ROTATE
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

// REVERSE ROTATE
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif