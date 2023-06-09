/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:19:42 by bkarlida          #+#    #+#             */
/*   Updated: 2023/06/09 21:18:38 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	path_splt(void)
{
	int i;
	char **str;

	i = 0;
	str = ft_split(find_in_env("PATH") + 5, ':');
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
    g_var.path_env = NULL;
	g_var.path_env = malloc(sizeof(char *) * (splt_len(str) + 1));
	printf("splt len : %d\n", splt_len(str));
	while (str[i])
	{
		g_var.path_env[i] = ft_strjoin(str[i], "/");
		printf("str = %s\n", str[i]);
		printf("path_env = %s\n", g_var.path_env[i]);
		free(str[i]);
		i++;
	}
	g_var.path_env[i] = NULL;
	free(str);
}

char	**add_cmd(void)
{
	int i;
	int k;
	char	**str;
	link_list	*temp;

	i = 0;
	k = 0;
	temp = g_var.lst;
	str = malloc(sizeof(char *) * (g_var.lst_size + 1));
	while (g_var.str[i])
	{
		if (temp->flag == 'b')
		{
			str[k] = ft_strdup(g_var.str[i]);
			k++;
		}
		temp = temp->next;
		i++;
	}
	str[k] = NULL;
	return(str);
}



int		cmd_acces(void)
{
	int i;
	int j;
	int k;
	char	*a;

	i = 0;
	g_var.cmd = NULL;
	g_var.cmd = add_cmd();
	while (g_var.cmd[i])
	{
		j = 0;
		k = 0;
		while (g_var.path_env[k])
		{
			j = i;
			g_var.acces = ft_strjoin(g_var.path_env[k], g_var.cmd[i]);
			if (access(g_var.acces, F_OK) == 0)
			{
				return(0);
			}
			free(g_var.acces);
			j++;
			k++;
		}
		i++;
	}
	return(-1);
}


void	exec_init(void)
{
	int		i;
	int		flag;
	int		id;

	i = 0;
	flag = cmd_acces();
	id = fork();
	if (id == 0)
	{
		if (flag == 0)
		{
			execve(g_var.acces, g_var.cmd, g_var.env);
		}
		else
		{
			printf("minishell: %s: command not found\n", g_var.str[0]);
			exit(127);
		}
	}
	waitpid(id, NULL, 0);
	//free(g_var.acces);
	
}