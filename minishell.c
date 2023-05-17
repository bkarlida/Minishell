/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:31:42 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/05/17 04:18:30 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quot_parser(char *line, int *i)
{
	int k;
	int len;
	int v_flag;
	int j;

	j = 0;
	v_flag = 0;
	k = *i;
	len = k;
	g_var.quot_flag = 'b';
	while ((line[len] != '<' || line[len] != '>' || line[len] != '|') && line[len])
		len++;
	g_var.cont = malloc(sizeof(char) * (len + 3));
	while (line[k] && (line[k] != ' ' && line[k] != '\t'))
	{
		if (line[k] != '|' && line[k] != '>' && line[k] != '<')
		{
			if (line[k] == 34 || line[k] == 39)
			{
				g_var.quot_flag = line[k];
				k++;
				while ((line[k] != g_var.quot_flag) && line[k])
				{
					g_var.cont[j++] = line[k++];
					v_flag = 1;
				}
				if (v_flag)
					k++;
				v_flag = 0;		
			}
			else
			{
				g_var.cont[j++] = line[k++];			
			}
		}
		else
		{
			break;
		}
			//perror("aaaaaaaaaaaaaaaaaaaaaaa\n");
	}
	//printf("*****%c****\n", line[k]);
	g_var.cont[j] = 0;
	*i = k;
	link_lstadd_back(&g_var.lst, link_lstnew(g_var.cont, g_var.quot_flag));
	//g_var.lst->flag = g_var.quot_flag;
}

int		consecutive_rdr_parser(char *line, int *i)
{
	int k;
	
	k = *i;
	//perror("-----------------------");
	while (line[k])
	{
		if (line[k] == '|')
		{
			g_var.cont = malloc(sizeof(char) * 2);
			g_var.cont[0] = line[k];
			g_var.cont[1] = 0;
			g_var.rdr_flag = line[k];
			k++;
			break;
		}
		else if (line[k] == '>')
		{
			if (line[k + 1] == '>')
			{
				if (line[k + 2] == '|' || line[k + 2] == '>' || line[k + 2] == '<')
				{
					printf("syntax error\n");
					return(0);
				}
				else
				{
					g_var.extra_rdr_flag = 2;
					g_var.cont = malloc(sizeof(char) * 3);
					g_var.cont[0] = line[k];
					g_var.cont[1] = line[k + 1];
					g_var.cont[2] = 0;
					g_var.rdr_flag = line[k];
					k++;
					k++;
					break;
				}
			}
			else
			{
				g_var.cont = malloc(sizeof(char) * 2);
				g_var.cont[0] = line[k];
				g_var.cont[1] = 0;
				g_var.rdr_flag = line[k];
				k++;
				break;
			}
			
		}
		else if (line[k] == '<')
		{
			if (line[k + 1] == '<')
			{
				if (line[k + 2] == '|' || line[k + 2] == '>' || line[k] != '<')
				{
					printf("syntax error\n");
					return(0);
				}
				else
				{
					g_var.extra_rdr_flag = 2;
					g_var.cont = malloc(sizeof(char) * 3);
					g_var.cont[0] = line[k];
					g_var.cont[1] = line[k + 1];
					g_var.cont[2] = 0;
					g_var.rdr_flag = line[k];
					k++;
					k++;
					break;
				}
			}
			else
			{
				g_var.cont = malloc(sizeof(char) * 2);
				g_var.cont[0] = line[k];
				g_var.cont[1] = 0;
				g_var.rdr_flag = line[k];
				k++;
				break;
			}
		}
		k++;
	}
	*i = k;
	return(1);
}

int		rdr_parser(char *line, int *i)
{
	int k;
	int len;
	int j;
	
	k = *i;
	j = 0;
	g_var.rdr_flag = 'b';
	g_var.error_flag = 1;
	g_var.cont = 0;
	if (line[k] == '|' || line[k] == '>' || line[k] == '<')
	{
		if (line[k + 1] == '|' || line[k + 1] == '>' || line[k + 1] == '<')
		{
			g_var.error_flag = consecutive_rdr_parser(line, &k);

		}
		else
		{
			printf("--------------\n");
			g_var.cont = malloc(sizeof(char) * 3);
			g_var.cont[j] = line[k];
			g_var.cont[j + 1] = 0;
			g_var.rdr_flag = line[k];
			k++;
		}
		
	}
	else
	{
		len = k;
		while (line[len] != '|' && line[len] != '>' && line[len] != '<' && line[len])
		{
			if (line[len] == ' ' || line[len] == '\t')
				len++;
			len++;
		}
		g_var.cont = malloc(sizeof(char) * (len - k + 2));
		while (line[k] != '|' && line[k] != '>' && line[k] != '<' && line[k] && line[k] != 34 && line[k] != 39)
		{
			if (line[k] == ' ' || line[k] == '\t')
			{
				k++;
				break;
			}
			g_var.cont[j++] = line[k];
			k++;
		}
		g_var.cont[j] = 0;
	}
	if(!g_var.error_flag)
	{
		*i = k;
		link_lstadd_back(&g_var.lst, link_lstnew(g_var.cont, g_var.rdr_flag));
		g_var.lst->extra_flag = g_var.extra_rdr_flag;
		return(0);
	}
	g_var.cont = ft_strtrim(g_var.cont, " ");
	*i = k;
	link_lstadd_back(&g_var.lst, link_lstnew(g_var.cont, g_var.rdr_flag));
	g_var.lst->extra_flag = g_var.extra_rdr_flag;
	return(1);
}

int	start_parser(char *line)
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
				g_var.error_flag = rdr_parser(line, &i);
					if (!g_var.error_flag)
						break;
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
	if (g_var.error_flag)
	{
		while (tmp)
		{
			printf("%s    ", tmp->content);
			//printf("  **%d**    ", tmp->extra_flag);
			printf("----%c----\n", tmp->flag);
			tmp = tmp->next;
		}
	}
	
	return(1);
}

int main (int ac , char **av, char **envp)
{
	g_var.error_flag = 0;
    while (1)
    {
        char *mshell;
        
        mshell = readline("minishell$ ");
		if(mshell == NULL)
		break;
        add_history(mshell);
        start_parser(mshell);
    }
}