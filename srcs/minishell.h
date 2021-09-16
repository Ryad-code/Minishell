/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:41:39 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/09/16 12:33:18 by mlaouedj         ###   ########.fr       */
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
	int			buffer_len;
	char		**words;
	int			nb_words;
	t_word		*lexer;

}				t_data;
//.............................................Init
int		ft_init_words(t_data *data);
//............................................String_checking
int		ft_str_check(char *str);
int		ft_check_quotes(char *str);
//............................................Parsing (ft_str01.c)
int		ft_strcmp(char *sster1, char *str2);
int		ft_strncmp(char *str1, char *str2, int n);
int		ft_count_words(char *s, char c);
char	*ft_strndup(char *str, int n);
char	**ft_split(char *s, char c);
//.............................................Lexer_utils (ft_str02.c)
int		ft_is_printable(char c);
int		ft_is_spe(char c);
int		ft_is_option(char *str, int i);
int		ft_pass_space(char *str, int i);
int		ft_pass_word(char *str, int i);
int		ft_pass_quotes(char *str, int i, char c);
//.............................................Lexer (ft_str03.c)
int		ft_parser(t_data *data);
int		ft_get_cmd(t_data *data, int *i, int *curs);
int		ft_get_opt(t_data *data, int *i, int *curs);
int		ft_get_arg(t_data *data, int *i, int *curs);
int		ft_get_spe(t_data *data, int *i, int *curs);
//.............................................Router
int		ft_router(t_data *data);
//.............................................Builtins
int		ft_echo(t_data *data);
void	ft_print(t_word *word);
//............................................
int		ft_cd(t_data *data);
int		ft_pwd(void);
int		ft_export(t_data *data);
int		ft_unset(t_data *data);
int		ft_env(t_data *data);
int		ft_exit(t_data data);
//............................................................................UTILS (lists, displays)
//.............................................Lexing list
t_word	*ft_create_first(char *str, char token, int start);
int 	ft_create_top(t_word **word, char *str, char token);
int 	ft_create_bot(t_word **word, char *str, char token, int start);
int		ft_delete_top(t_word **word);
int		ft_delete_bot(t_word **word);
//.............................................Display
void    ft_display_words(char **words, int nb);
void    ft_display_list(t_word *word);

