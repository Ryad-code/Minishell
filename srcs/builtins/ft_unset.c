/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:04:39 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/16 12:08:15 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_unset(t_data *data)
{
	int curs;

	curs = ft_find_var(data, data->parser.env);
	ft_delete_in(data, &data->parser.env, curs);
	return (0);
}
