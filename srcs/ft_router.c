/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_router.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 00:45:28 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/16 12:23:30 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_router(t_data *data)
{
	if (ft_strcmp("echo", data->lexer->str) == 0)
		ft_echo(data);
/*	else if (ft_strcmp(CD, data->lexer->str) == 0)
		ft_cd(data);
	else if (ft_strcmp(PWD, data->lexer->str) == 0)
		ft_pwd();
	else if (ft_strcmp(EXPORT, data->lexer->str) == 0)
		ft_export(data);
	else if (ft_strcmp(UNSET, data->lexer->str) == 0)
		ft_unset(data);
	else if (ft_strcmp(ENV, data->lexer->str) == 0)
		ft_env(data);*/
//	else
//		ft_exec(data);
	return (0);
}
