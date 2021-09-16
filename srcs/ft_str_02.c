/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:52:24 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/16 11:12:12 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_is_printable(char c)
{
	if (c < '!' || c > '~')
		return (-1);
	return (0);
}

int	ft_is_spe(char c)
{
	if (c == '|' || c == '>' || c == '<' || c == '$' || c == '&' || c == '#')
		return (0);
	return (1);
}

int	ft_is_option(char *str, int i)
{
	if (str[i] == '-' && str[i + 1] != '-')
		return (1);
	return (0);
}

int	ft_pass_space(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int	ft_pass_word(char *str, int i)
{
	while (str[i] && ft_is_printable(str[i]) == 0)
		i++;
	return (i);
}

int	ft_pass_quotes(char *str, int i, char c)
{
	int res;

	res = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		res++;
	}
	if (str[i] == '\0')
		return (0);
	return (res);
}
