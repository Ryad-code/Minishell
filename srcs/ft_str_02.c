/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:52:24 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/08 18:25:34 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_alpha(char c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
		return (-1);
	return (0);
}

int	ft_is_spe(char c)
{
	if (c == '&' || c == '|' || c == '>' || c == '<' || c == '$')
		return (0);
	return (1);
}

int	ft_space(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int	ft_prefix(char *str, int i)
{
	if (str[i] == '-' || str[i] == '\"' || str[i] == '\'' || str[i] == '$')
		return (1);
	return (0);
}

int	ft_word(char *str, int i)
{
	while (str[i] && ft_is_alpha(str[i]) == 0)
		i++;
	return (i);
}

int	ft_quotes(char *str, int i)
{
	int res;

	res = 0;
	while (str[i] && str[i] != '\"')
	{
		i++;
		res++;
	}
	if (str[i] == '\0')
		return (0);
	return (res);
}

void	ft_parser(t_data *data)
{
	int i;
	int curs;

	i = 0;
	i = ft_space(data->buffer, i);
	curs = ft_word(data->buffer, i);
	data->lexer = ft_create_first(ft_strndup(&data->buffer[i], curs), 'c');
	i = curs;
	while (i < ft_strlen(data->buffer))
	{
//		printf("i = %d\n", i);
		i = ft_space(data->buffer, i);
		curs = ft_word(data->buffer, i + ft_prefix(data->buffer, i));
		if (data->buffer[i] == '-')
			ft_create_bot(&data->lexer, ft_strndup(&data->buffer[i], curs - i), 'o');
		else if (ft_is_alpha(data->buffer[i]) == 0)
			ft_create_bot(&data->lexer, ft_strndup(&data->buffer[i], curs - i), 'a');
		else if (ft_prefix(data->buffer, i) == 1)
		{
			if (ft_quotes(data->buffer, i + 1) > 0)
			{
				ft_create_bot(&data->lexer, ft_strndup(&data->buffer[i], ft_quotes(data->buffer, i + 1) + 2), 'q');
				curs = i + ft_quotes(data->buffer, i + 1) + 2;
			}
			else
				ft_create_bot(&data->lexer, ft_strndup(&data->buffer[i], curs - i), 'a');
		}
		i = curs;
}
}
