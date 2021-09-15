/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:41:39 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/15 12:38:51 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include "gnl/get_next_line.h"

#define EXIT "exit"

typedef struct s_word
{
	char			*str;
	char			token;
	int				start;
	struct s_word	*next;
	struct s_word	*prev;
}					t_word;

typedef struct s_data
{
	char		*buffer;
	char		**words;
	int			nb_words;
	t_word		*lexer;

}				t_data;
//.............................................Init
int		ft_init_words(t_data *data);
//............................................Parsing
int		ft_strcmp(char *sster1, char *str2);
int		ft_strncmp(char *str1, char *str2, int n);
int		ft_count_words(char *s, char c);
char	*ft_strndup(char *str, int n);
char	**ft_split(char *s, char c);
//.............................................Lexing
int		ft_is_alpha(char c);
int		ft_is_num(char c);
int		ft_is_alphanum(char c);
int		ft_is_spe(char c);
int		ft_is_option(char *str, int i);
int		ft_space(char *str, int i);
int		ft_prefix(char *str, int i);
int		ft_word(char *str, int i);
int		ft_quotes(char *str, int i);
//.............................................Init parser
int		ft_parser(t_data *data);
int		ft_get_cmd(t_data *data, int *i, int *curs);
int		ft_get_opt(t_data *data, int *i, int *curs);
int		ft_get_arg(t_data *data, int *i, int *curs);
//.............................................Lexing list
t_word	*ft_create_first(char *str, char token, int start);
int ft_create_top(t_word **word, char *str, char token);
int ft_create_bot(t_word **word, char *str, char token, int start);
int	ft_delete_top(t_word **word);
int	ft_delete_bot(t_word **word);
//.............................................Display
void    ft_display_words(char **words, int nb);
void    ft_display_list(t_word *word);

