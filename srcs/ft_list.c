/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 02:46:08 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/09 13:04:14 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_word	*ft_create_first(char *str, char token, int start)
{
	t_word	*obj;

	obj = malloc(sizeof(t_word));
	obj->str = ft_strndup(str, ft_strlen(str));
	obj->token = token;
	obj->start = start;
	obj->next = NULL;
	obj->prev = NULL;
	return (obj);
}

int ft_create_top(t_word **word, char *str, char token)
{
	t_word  *obj;

	obj = malloc(sizeof(t_word));
	obj->str = ft_strndup(str, ft_strlen(str));
	obj->token = token;
	obj->next = *word;
	obj->prev = NULL;
	(*word)->prev = obj;
	*word = obj;
	return (0);
}

int ft_create_bot(t_word **word, char *str, char token, int start)
{
	t_word  *obj;
	void	*tmp;

	obj = malloc(sizeof(t_word));
	tmp = *word;
	while ((*word)->next)
		*word = (*word)->next;
	obj->str = ft_strndup(str, ft_strlen(str));
	obj->token = token;
	obj->start =  start;
	obj->next = NULL;
	obj->prev = *word;
	(*word)->next = obj;
	*word = tmp;
	return (0);
}

int	ft_delete_top(t_word **word)
{
	t_word *tmp;

	tmp = (*word)->next;
	(*word)->next->prev = NULL;
	free(*word);
	*word = tmp;
	return (0);
}

int	ft_delete_bot(t_word **word)
{
	t_word *tmp;

	tmp = *word;
	while ((*word)->next)
		*word = (*word)->next;
	(*word)->prev->next = NULL;
	free(*word);
	*word = tmp;
	return (0);
}
