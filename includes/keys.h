/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/05/25 22:42:44 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_HANDLER
# define KEYBOARD_HANDLER


# define KILL_LINE				11 //C-k
# define UNIX_LINE_DISCARD		21 // C-u
# define UNIX_WORD_RUBOUT		23 // C-w
# define PASTE					25 // C-y
# define DELETE_CHAR			4 // C-d
# define BEGIN_OF_LINE			1 // C-a
# define BACK_DELETE_CHAR		8 // C-h
# define END_OF_LINE			5 // C-e
# define FORWARD_CHAR			6 // C-f
# define BACKWARD_CHAR			2 // C-b
# define CLEAR_SCREEN			12 // C-l
# define PREVIOUS_HISTORY		16  //C-p
# define NEXT_HISTORY			14 // C-n
# define SEARCH_HISTORY			18  //C-r

# define META_KEY				27 // ESC
# define KILL_WORD				100 // M-d
# define FORWARD_WORD			102 // M-f
# define BACKWARD_WORD			98 // M-b
# define UPCASE_WORD			117 // M-u
# define DOWNCASE_WORD			108 // M-l
# define CAPITALIZE_WORD		99  //M-c

# define LINE_UP				1096489755
# define LINE_DOWN				1113266971
# define K_ALT_RIGHT			1130044187
# define K_ALT_LEFT				1146821403
# define K_ARROW_RIGHT			4414235
# define K_ARROW_LEFT			4479771
# define K_ARROW_UP				4283163
# define K_ARROW_DOWN			4348699
# define K_HOME					4741915
# define K_END					4610843
# define K_BACKSPACE			2117294875
# define K_DELETE				127

# define K_RETURN				13

#endif