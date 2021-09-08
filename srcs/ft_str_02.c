/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:52:24 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/08 12:27:39 by mlaouedj         ###   ########.fr       */
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

int	ft_get_word(char *str, int i)
{
	while (str[i] && ft_is_alpha(str[i]) == 0)
		i++;
	return (i);
}

void	ft_parser(t_data *data)
{
	int i;
	int curs;

	i = 0;
	i = ft_space(data->buffer, i);
	curs = ft_get_word(data->buffer, i);
	data->lexer = ft_create_first(ft_strndup(&data->buffer[i], curs), 'c');
//	printf("len=%d\n", ft_strlen(data->buffer));
	printf("s1=%s\n", ft_strndup(&data->buffer[i], curs));
	i = curs;
	while (i < ft_strlen(data->buffer))
	{
		i = ft_space(data->buffer, i);
		curs = ft_get_word(data->buffer, i);
		printf("i=%d, curs=%d\n", i, curs);
		ft_create_bot(&data->lexer, ft_strndup(&data->buffer[i], curs - i), 'c');
//		printf("s=%s\n", ft_strndup(&data->buffer[i], curs - i));
		i = curs;
	}
}



