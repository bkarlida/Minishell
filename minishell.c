/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:31:42 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/05/31 19:22:10 by bkarlida         ###   ########.fr       */
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

void	env_malloc(char **envp)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (envp[i])
	{
		i++;
		len++;
	}
	g_var.env_size = len;
	i = 0;
	g_var.env = malloc(sizeof(char *) * (g_var.env_size + 2));
	while (envp[i])
	{
		g_var.env[i] = ft_strdup(envp[i]);
		//printf("<<<<<<<<  %s  >>>>>>\n", g_var.env[i]);
		i++;
	}
	g_var.env[i] = NULL;
}

void	handle_signal(int sig)
{
	(void)sig;
	exit(0);// eksik tam çalışmıyor
}

void	env_export(char **envp)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (envp[len])
	{
		len++;
	}
	g_var.export_size = len;
	g_var.export = malloc(sizeof(char *) * (g_var.env_size + 1));
	while (envp[i])
	{
		g_var.export[i] = ft_strdup(envp[i]);
		//printf("declare -x %s\n", g_var.export[i]);
		i++;
	}
	g_var.export[i] = NULL;
}

int main (int ac , char **av, char **envp)
{
	env_malloc(envp);
	env_export(envp);
	g_var.pwd_new = NULL;
    while (1)
    {
        char *mshell;
        mshell = readline("\033[32mminishell  $ \033[0m");
		if(mshell == NULL)
		break;
        add_history(mshell);
        start_parser(mshell);
		command_prepare();
		command_built();
		signal(SIGINT, handle_signal);
    }
}