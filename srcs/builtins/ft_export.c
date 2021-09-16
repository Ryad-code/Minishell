/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:04:27 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/16 12:07:42 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_export(t_data *data)
{
	if (data->parser.nb_words == 1)
		ft_display_list(data->parser.exp);
	else
	{
		ft_create_in(&data->parser.env, data->parser.words[1] ,data->parser.len_env - 1);
		ft_create_bot(&data->parser.exp, data->parser.words[1]);
	}
	return (0);
}
