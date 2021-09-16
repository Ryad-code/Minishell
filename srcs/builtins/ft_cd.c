/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:03:43 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/16 12:07:02 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cd(t_data *data)
{
	int res;

	res = chdir(data->parser.words[1]);
	if (res < 0)
	{
		perror(data->parser.words[1]);
		return (-1);
	}
	return (0);
}
