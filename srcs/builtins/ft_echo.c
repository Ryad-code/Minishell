/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:03:22 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/16 12:39:55 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print(t_word *word)
{
	write(1, word->str, ft_strlen(word->str));
}

int		ft_echo(t_data *data)
{
	t_word *tmp;

	tmp = data->lexer;
	if (tmp->next)
		tmp = tmp->next;
	while (tmp->next)
	{
		ft_print(tmp);
//		write(1, data->lexer->str, ft_strlen(data->lexer->str));
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, tmp->str, ft_strlen(tmp->str));
	write(1, "\n", 1);

	return (0);
}
