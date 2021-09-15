/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_03.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:07:19 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/15 12:41:47 by mlaouedj         ###   ########.fr       */
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
	ft_get_cmd(data, &i, &curs);
	while (opt > 0)
		opt = ft_get_opt(data, &i, &curs);
	while (arg > 0)
		arg = ft_get_arg(data, &i, &curs);
	return (0);
}

int	ft_get_cmd(t_data *data, int *i, int *curs)
{

	*i = ft_space(data->buffer, 0);
	*curs = ft_word(data->buffer, *i);
	data->lexer = ft_create_first(ft_strndup(&data->buffer[*i], *curs), 'c', *i);
	*i = *curs;
	return (0);
}

int ft_get_opt(t_data *data, int *i, int *curs)
{
	*i = ft_space(data->buffer, *i);
	if (ft_is_option(data->buffer, *i) == 1)
	{
		*curs = ft_word(data->buffer, *i + 1);
		ft_create_bot(&data->lexer, ft_strndup(&data->buffer[*i], *curs - *i), 'o', *i);
		*i = *curs;
		return (1);
	}
		return (0);
}

int	ft_get_arg(t_data *data, int *i, int *curs)
{
	*i = ft_space(data->buffer, *i);
	if (ft_is_alpha(data->buffer[*i]) == 0)
	{
		*curs = ft_word(data->buffer, *i);
		ft_create_bot(&data->lexer, ft_strndup(&data->buffer[*i], *curs - *i), 'a', *i);
		*i = *curs;
		return (1);
	}
	else if (data->buffer[*i] == '"')
	{
		*curs = ft_word(data->buffer, *i);
		ft_create_bot(&data->lexer, ft_strndup(&data->buffer[*i], ft_quotes(data->buffer, *i + 1) + 2), 'q', *i);
		*i = *curs;
	}	
	return (0);
}

