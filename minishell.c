/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:31:42 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/05/17 19:43:53 by bkarlida         ###   ########.fr       */
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


void	Command_Prepare(void)
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
	g_var.str[i] = 0;
	i = 0;
	while (g_var.str[i])
	{	printf("--------\n");
		printf("%s\n", g_var.str[i++]);
		printf("--------\n");
	}
	
}

int	ft_echo_is_null(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	else
		return(0);	
	while (str[i])
	{
		if (str[i] != 'n' && !str[i])
		{
			return(0);
		}
		i++;
	}
	return(1);
}

void	ft_echo(int	k)
{
	int flag;

	flag = 1;
	k++;
	printf("-------Echo_komutu_çalıştı!------\n");
	while (g_var.str[k])
	{
		if (ft_echo_is_null(g_var.str[k]))
					flag = 0;
		if (g_var.str[k][0] != '|' && g_var.str[k][0] != '<' && g_var.str[k][0] != '>')
		{
			printf("%s", g_var.str[k]);
			printf(" ");
			k++;
		}
		else
		{
			// henüz rdirect ve pipe yapılmadı onları atlayarak echo yazdırılıyor;
			if (g_var.str[k][0] == '|')
			{
				printf("--Pipe_Yapılmadı_Henüz--\n");
			}
			k++;
		}
	}
	if (flag)
		printf("\n");
}
void	Command_Building(void)
{
	int i;

	i = 0;
	while (g_var.str[i])
	{
		if (strequal(g_var.str[i], "echo"))
			ft_echo(i);
		i++;
	}
	
}

/*void	rdrirect_upper(void)
{
	int i;
	int fd;

	i = 0;
	g_var.b_str = g_var.str;
	while (g_var.b_str[i])
	{
		if (g_var.b_str[i] == '>')
		{
			fd = open(g_var.b_str[i + 1], O_CREAT | O_RDWR, 0777);
		}
		
	}
	
}*/

int main (int ac , char **av, char **envp)
{
    while (1)
    {
        char *mshell;
        
        mshell = readline("minishell$ ");
		if(mshell == NULL)
		break;
        add_history(mshell);
        start_parser(mshell);
		Command_Prepare();
		Command_Building();
    }
}