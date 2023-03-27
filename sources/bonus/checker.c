/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:26:02 by ichiro            #+#    #+#             */
/*   Updated: 2023/03/27 02:39:52 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// void	do_action(char *line)
// {
// 	printf("%s", line);
// }

int	main(int argc, char *argv[])
{
	char	*line;
	t_data	data;

	data.stack_a = NULL;
	data.stack_b = NULL;
	if (argc == 1)
		return 0;
	// while (1)
	// {
	// 	line = get_next_line(STDIN_FILENO);
	// 	if (line == NULL)
	// 		break ;
	// 	// do_action (line);
	// 	free(line);
	// 	// printf("%s", line);
	// }
	return (0);
}