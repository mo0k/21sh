/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_21sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:07:38 by mo0ky             #+#    #+#             */
/*   Updated: 2017/06/17 16:27:34 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_21SH_H
# define FT_21SH_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <libft.h>
# include <get_next_line.h>
# include <ft_types.h>
# include <error.h>
# include <signals.h>
# include <parameters.h>
# include <builtins.h>
# include <tokenizer.h>
# include <parser.h>
# include <history.h>
# include <newline.h>
# include <readline.h>
# include <terms.h>

# define CWD 255
# define PROMPT "21sh"
# define SYMBOL "_$ "
# define LEN_SYMBOL 3
# define PROMPT_NEWLINE "> "
# define PROMPT_COLOR C_GREEN
# define SYMBOL_COLOR C_CYAN
# define C_PROMPT PROMPT_COLOR PROMPT SYMBOL_COLOR SYMBOL C_DFL C_DFL
# define C_PROMPT_NEWLINE PROMPT_COLOR PROMPT_NEWLINE C_DFL

void		usage(int ac, char **av);
void		init(t_shell *stock, char **env);
t_shell		*stock_data(t_shell *elem);
void		print_stock(t_shell *stock);

int			prompt(char *ptr);
void		init_winsize(t_win *winsize, t_uint row, t_uint col);
int			ft_delchar(char **str, int pos);

#endif