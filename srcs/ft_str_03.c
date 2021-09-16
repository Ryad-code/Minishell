/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_03.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:07:19 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/16 12:06:02 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_parser(t_data *data)
{
	int	i;
	int	curs;
	int	opt;
	int	arg;

	i = 0;
	curs = 0;
	opt = 1;
	arg = 1;
	data->buffer_len = ft_strlen(data->buffer);
	ft_get_cmd(data, &i, &curs);
	while (opt > 0)
		opt = ft_get_opt(data, &i, &curs);
	while (arg > 0)
		arg = ft_get_arg(data, &i, &curs);
	return (0);
}

int	ft_get_cmd(t_data *data, int *i, int *curs)
{

	*i = ft_pass_space(data->buffer, 0);
	*curs = ft_pass_word(data->buffer, *i);
	data->lexer = ft_create_first(ft_strndup(&data->buffer[*i], *curs), 'c', *i);
	*i = *curs;
	return (0);
}

int ft_get_opt(t_data *data, int *i, int *curs)
{
	if (*i < data->buffer_len)
	{
		*i = ft_pass_space(data->buffer, *i);
		if (ft_is_option(data->buffer, *i) == 1)
		{
			*curs = ft_pass_word(data->buffer, *i + 1);
			ft_create_bot(&data->lexer, ft_strndup(&data->buffer[*i], *curs - *i), 'o', *i);
			*i = *curs;
			return (1);
		}
	}
	return (0);
}

int	ft_get_arg(t_data *data, int *i, int *curs)
{
	if (*i < data->buffer_len)
	{
		*i = ft_pass_space(data->buffer, *i);
		if (data->buffer[*i] == '"' || data->buffer[*i] == '\'')
		{
			ft_create_bot(&data->lexer, ft_strndup(&data->buffer[*i + 1],
					ft_pass_quotes(data->buffer, *i + 1, data->buffer[*i])), 'q', *i);
			*i = *i + ft_pass_quotes(data->buffer, *i + 1, data->buffer[*i]) + 3;
			return (1);
		}
		else if (ft_is_spe(data->buffer[*i]) == 0)
		{
			*curs = ft_pass_word(data->buffer, *i);
			ft_create_bot(&data->lexer, ft_strndup(&data->buffer[*i], *curs - *i), 's', *i);
			*i = *curs;
			return (1);
		}
		else if (ft_is_printable(data->buffer[*i]) == 0)
		{
			*curs = ft_pass_word(data->buffer, *i);
			ft_create_bot(&data->lexer, ft_strndup(&data->buffer[*i], *curs - *i), 'a', *i);
			*i = *curs;
			return (1);
		}
	}
	return (0);
}
