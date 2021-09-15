/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_03.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:07:19 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/15 11:55:07 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_cmd(t_data *data)
{
	int i;
	int curs;

	i = ft_space(data->buffer, 0);
	curs = ft_word(data->buffer, i);
	data->lexer = ft_create_first(ft_strndup(&data->buffer[i], curs), 'c', i);
	i = curs;
	ft_get_opt(data, i, curs);
	return (0);
}

int ft_get_opt(t_data *data, int i, int curs)
{
	i = ft_space(data->buffer, i);
	if (data->buffer[i] == '-')
		printf("bonjour");
/*	while ()
	{
		
	}*/
	return (0);
}



