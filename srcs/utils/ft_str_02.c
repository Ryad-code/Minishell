/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:52:24 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/09 15:36:15 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_alpha(char c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
		return (-1);
	return (0);
}

int	ft_is_num(char c)
{
	if (c < '0' || c > '9')
		return (-1);
	return (0);
}

int ft_is_alphanum(char c)
{
	if (ft_is_alpha(c) < 0 && ft_is_num(c) < 0)
		return (-1);
	return (0);
}

int	ft_is_spe(char c)
{
	if (c == '|' || c == '>' || c == '<' || c == '$')
		return (0);
	return (1);
}

int	ft_is_option(char *str, int i)
{
	return (0);
}

int	ft_space(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int	ft_prefix(char *str, int i)
{
	if (str[i] == '\"' || str[i] == '\'' || str[i] == '-' || str[i] == '$')
	{
//		printf("c = %c\n", str[i]);
		return (1);
	}
	return (0);
}

int	ft_word(char *str, int i)
{
	while (str[i] && ft_is_alphanum(str[i]) == 0)
		i++;
	return (i);
}

int	ft_quotes(char *str, int i)
{
	int res;

	res = 0;
	while (str[i] && str[i] != '"')
	{
		i++;
		res++;
	}
	if (str[i] == '\0')
		return (0);
	return (res);
}
