/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:31:42 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/05/24 16:55:02 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_parser(char *line)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(line);
	g_var.extra_rdr_flag = 1;
	link_lstclear(&g_var.lst);
	while (i < len)
	{
		if ((line[i] == ' ' || line[i] == '\t') && line[i])
			i++;
		else if (line[i] == '|' || line[i] == '>' || line[i] == '<')
		{
			if ((line[i] != ' ' || line[i] != '\t') && line[i])
			{
				rdr_parser(line, &i);
			}
			else
				if(!line[i])
					i++;
		}
		else
			quot_parser(line, &i);
	}
	// sil ekrana yazdırma bölümü
	link_list *tmp;
	tmp = g_var.lst;
	printf("----------Liste_Ekrana_Bastırılıyor!---------\n");
	while (tmp)
	{
		printf("%s    ", tmp->content);
		//printf("  **%d**    ", tmp->extra_flag);
		printf("----%c----\n", tmp->flag);
		tmp = tmp->next;
	}
	printf("----------Liste_Ekrana_Bastırıldı!---------\n");
}


void	command_prepare(void)
{
	link_list	*tmp;
	int i;

	i = 0;
	tmp = g_var.lst;
	g_var.lst_size = link_lstsize(g_var.lst);
	g_var.str = malloc(sizeof(char *) * (g_var.lst_size + 1));
	while (tmp)
	{
		g_var.str[i++] = tmp->content;
		tmp = tmp->next;
	}
	g_var.str[i] = NULL;
	i = 0;
	while (g_var.str[i])
	{	
		printf("******%s******\n", g_var.str[i++]);
	}
	
}


int main (int ac , char **av, char **envp)
{
	//char location[256];
	
	
    while (1)
    {
		g_var.env = envp;
        char *mshell;
       // getcwd(location, sizeof(location));
        mshell = readline("\033[32mminishell$ \033[0m");
		if(mshell == NULL)
		break;
        add_history(mshell);
        start_parser(mshell);
		command_prepare();
		command_built();
    }
}