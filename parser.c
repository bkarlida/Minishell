/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 04:35:25 by bkarlida          #+#    #+#             */
/*   Updated: 2023/05/17 19:39:47 by bkarlida         ###   ########.fr       */
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
                    //printf("**%c**\n", line[k]); // tırnak karakterler yazdırma
                
					g_var.cont[j++] = line[k++];
					v_flag = 1;
				}
				if (v_flag)
					k++;
				v_flag = 0;		
			}
			else
				g_var.cont[j++] = line[k++];			
		}
		else
			break;
	}
	g_var.cont[j] = 0;
	*i = k;
	link_lstadd_back(&g_var.lst, link_lstnew(g_var.cont, g_var.quot_flag));
}

void		consecutive_rdr_parser(char *line, int *i)
{
	int k;
	
	k = *i;
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
				/*if (line[k + 2] == '|' || line[k + 2] == '>' || line[k + 2] == '<')
				{
					printf("syntax error\n");
					return(0);
				}*/
				
				
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
}

void	rdr_parser(char *line, int *i)
{
	int k;
	int len;
	int j;
	
	k = *i;
	j = 0;
	g_var.rdr_flag = 'b';
	g_var.cont = 0;
	if (line[k] == '|' || line[k] == '>' || line[k] == '<')
	{
		if (line[k + 1] == '|' || line[k + 1] == '>' || line[k + 1] == '<')
			consecutive_rdr_parser(line, &k);
		else
		{
			g_var.cont = malloc(sizeof(char) * 3);
			g_var.cont[j] = line[k];
			g_var.cont[j + 1] = 0;
			g_var.rdr_flag = line[k];
			k++;
		}
	}
	else
	{
        //perror("-----------------------------------------------\n");
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
	g_var.cont = ft_strtrim(g_var.cont, " ");
	*i = k;
	link_lstadd_back(&g_var.lst, link_lstnew(g_var.cont, g_var.rdr_flag));
	g_var.lst->extra_flag = g_var.extra_rdr_flag;
}
