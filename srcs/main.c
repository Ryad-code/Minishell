/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:01:23 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/16 12:43:57 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_data data;

	data.buffer = malloc(sizeof(char) * 1024);
	if (!data.buffer)
		return (-1);
//.................................................................
	write(1, "$> ",3);
	while (ft_strcmp(data.buffer, EXIT) < 0)	
	{
		get_next_line(STDIN_FILENO, &data.buffer);
		if (ft_str_check(data.buffer) < 0)
		{
			printf("Error\n");
			return (-1);
		}
//................................................
		ft_parser(&data);
		ft_router(&data);
		ft_display_list(data.lexer);
//		printf("buf = %s\n", data.buffer);
		printf("len = %d\n", ft_strlen(data.buffer));
		write(1, "$> ",3);
	}
	free(data.buffer);
	printf("Bye\n");
//..................................................................	
	return (0);
}
