/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:48:56 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/09 15:39:43 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_display_words(char **words, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		printf("%s\n", words[i]);
		i++;
	}

}

void	ft_display_list(t_word *word)
{
	t_word	*tmp;

	tmp = word;
	printf("word = %15s | token = %1c | start = %4d\n", tmp->str, tmp->token, tmp->start);
	while (tmp->next)
	{
		tmp = tmp->next;
		printf("word = %15s | token = %1c | start = %4d\n", tmp->str, tmp->token, tmp->start);
	}
}
