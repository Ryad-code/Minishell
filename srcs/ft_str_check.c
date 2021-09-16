/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:40:56 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/16 11:48:33 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_str_check(char *str)
{
	if (ft_check_quotes(str) < 0)
		return (-1);
	return (0);
}

int	ft_check_quotes(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '"')
			res++;
		i++;
	}
	if (res % 2 == 0)
		return (0);
	else
		return (-1);
}
