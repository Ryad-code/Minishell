/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_03.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:07:19 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/15 12:28:44 by mlaouedj         ###   ########.fr       */
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
	while (i < ft_strlen(data->buffer))
	{
		i = ft_space(data->buffer, i);
		curs = ft_word(data->buffer, i + ft_prefix(data->buffer, i));
		if (ft_prefix(data->buffer, i) == 1)// Si il y a un prefixe :
		{
			if (data->buffer[i] == '"')//prefix = "
			{
//				if (ft_quotes(data->buffer, i + 1) > 0)//--------> ""
//				{
					ft_create_bot(&data->lexer, ft_strndup(&data->buffer[i], ft_quotes(data->buffer, i + 1) + 2), 'q', i);
					curs = i + ft_quotes(data->buffer, i + 1) + 2;
//				}
				else if (ft_quotes(data->buffer, i + 1) == 0)//-----> "
				{
					printf("error(unclosed quotes)\n");//-----------> remplacer par une gestion d'erreur
					return (-1);
				}
			}
			else if (data->buffer[i] == '-')//prefix = -
				ft_create_bot(&data->lexer, ft_strndup(&data->buffer[i], curs - i), 'o', i);
			else if (data->buffer[i] == '$')//prefix = $
				ft_create_bot(&data->lexer, ft_strndup(&data->buffer[i], curs - i), 'd', i);
		}
		else if (ft_is_alpha(data->buffer[i]) == 0)//no prefix
			ft_create_bot(&data->lexer, ft_strndup(&data->buffer[i], curs - i), 'a', i);
		i = curs;
	}
	return (0);
}

int ft_parser2(t_data *data)
{
	int i;
	int curs;
	
	i = ft_space(data->buffer, 0);
	curs = ft_word(data->buffer, i);
	data->lexer = ft_create_first(ft_strndup(&data->buffer[i], curs), 'c', i);
	i = curs;
//	while ()
//	{
		
//	}
	return (0);
}



