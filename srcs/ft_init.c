/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:36:12 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/07 15:07:27 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_words(t_data *data)
{
	data->nb_words = ft_count_words(data->buffer, ' ');
	data->words = ft_split(data->buffer, ' ');
	if (data->words == NULL)
	{
		printf("NON");
		return (-1);
	}
	return (0);
}

int	ft_init_lexer(t_data *data)
{
	int i;

	i = 0;
	data->lexer = ft_create_first(data->words[i], 'c');
	ft_display_list(data->lexer);
	return (0);
}
