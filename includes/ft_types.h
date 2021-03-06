/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:33:44 by mo0ky             #+#    #+#             */
/*   Updated: 2017/07/03 13:01:37 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

typedef unsigned int t_uint;

typedef struct		s_delimiter
{
	char			*begin;
	char	 		*end;
}					t_delimiter;

typedef enum		e_token_types
{
					WORD,
					PIPELINE,
					CTRL_OP,
					REDIR_OP,
					IO_NUMBER
}					t_token_types;

typedef struct		s_token
{
	char			*val;
	t_token_types	type;
	int				flag_inhibitor;
}					t_token;

typedef struct 		s_tokenizer
{
	t_list			*token;
	t_delimiter		delimiter;
}					t_tokenizer;

typedef struct		s_history_elem
{
	char			*val;
	char			*save;
	int				flag_new;
	int				flag_modif;
}					t_history_elem;

typedef struct		s_history
{
	t_list			*history_root;
	t_list			*history_cur;
	int 			ret;
	int 			in;
}					t_history;

typedef struct		termios t_termios;

typedef struct		s_term
{
	t_termios		*new;
	t_termios		*origin;
}					t_term;

enum				e_cut
{
					key_u = 1,
					key_k,
					key_w
};

typedef struct 		s_win
{
	t_uint			col;
	t_uint			row;
}					t_win;

typedef struct 		s_prompt
{
	char			*val;
	size_t			len;
}					t_prompt;


typedef struct		s_readline
{
	char			*line;
	char			**temp;
	char			*strcpy;
	t_prompt		prompt;
	t_win			win;
	int 			pos;
	enum e_cut		cut;
	int				in_newline;
}					t_readline;

typedef struct		s_parameter
{
	char			*key;
	char			*val;
}					t_param;

typedef struct		s_parameters
{
	t_list			*environment;
	t_list			*temporary;
}					t_params;

typedef struct		s_shell
{
	t_readline		readline;
	t_term			termios;
	t_history		history;
	t_tokenizer		tokenizer;
	t_params		parameters;
}					t_shell;


#endif 