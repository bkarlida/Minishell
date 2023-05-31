/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:03:30 by bkarlida          #+#    #+#             */
/*   Updated: 2023/05/31 19:30:54 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		splt_len(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

void	ft_export(void)
{
	int len;
	int j;
	int k;
	int i;
	char	**tmp;

	i = 1;
	k = 0;
	len = 0;
	while (g_var.str[i])
	{
		if (!ft_isalpha(g_var.str[i]) || g_var.str[i][0] == '>' || g_var.str[i][0] == '<' ||
			g_var.str[i][0] == '|')
		{
			i++;
			continue;
		}
		i++;
		len++;
	}
	i = 0;
	tmp = malloc(sizeof(char *) * (g_var.export_size + len + 1));
	while (g_var.export[i])
	{
		tmp[i] = ft_strdup(g_var.export[i]);
		i++;
	}
	k = 1;
	len++;
	while (k < len)
	{
		if (ft_isalpha(g_var.str[k]) && g_var.str[k][0] != '>' && g_var.str[k][0] != '<'
			&& g_var.str[k][0] != '|')
		{
			tmp[i] = ft_strdup(g_var.str[k]);
			i++;
			k++;
			continue;
		}
		k++;
	}
	tmp[i] = NULL;
	k = 0;
	i = 0;
	free(g_var.export);
	g_var.export = tmp;
	while (g_var.export[i])
	{
		printf("declare -x %s\n", g_var.export[i]);
		i++;
	}
}



int		command_built(void)
{
	int i;
	static int flag;

	i = 0;
	flag = 0;
	while (g_var.str[i])
	{
		if (strequal(g_var.str[i], "echo"))
		{
			ft_echo(i); // echo bitimşşşşşşşşş
			return(0);
		}
		else if (strequal(g_var.str[i], "cd"))
		{
			cd_func(i);
			return(0);
		}
		else if (strequal(g_var.str[i], "env"))
		{
			ft_env();
			return(0);
		}
        else if (strequal(g_var.str[i], "pwd"))
		{
			ft_pwd();
			return(0);
		}
    	else if (strequal(g_var.str[i], "unset"))
		{
			while (g_var.str[i])
			{
				if (g_var.str[i + 1] != NULL)
					ft_unset(g_var.str[i + 1]);
				i++;
			}
			return(0);
		}
		else if (strequal(g_var.str[i], "exit"))
		{
			if (i == 0)
			{
				ft_exit();
				return(0);
			}
		}
		else if (strequal(g_var.str[i], "export"))
		{
			
			ft_export();
			return(0);
		}
		i++;
	}
	return(1);
}