/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burakkarlidag <burakkarlidag@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:37:26 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/05/13 07:39:18 by burakkarlid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "LIBFT/libft.h"

typedef struct z_list
{
	char			*content;
	char			flag;
	int				extra_flag;
	struct z_list	*next;
}					link_list;

struct s_var
{
	int		lparse_int_value;
	link_list	*lst;
	char	quot_flag;
	char	*cont;
	char	rdr_flag;
	int		extra_rdr_flag;
	int		error_flag;
}	g_var;

int	start_parser(char *line);
char	**ft_split(char const *s, char c);
void	link_lstadd_back(link_list **lst, link_list *new);
void	link_lstclear(link_list **lst);
void	link_lstdelone(link_list *lst);
link_list	*link_lstlast(link_list *lst);
link_list	*link_lstnew(char *content, char flag);
int	link_lstsize(link_list *lst);

#endif