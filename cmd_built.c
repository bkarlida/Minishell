/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:03:30 by bkarlida          #+#    #+#             */
/*   Updated: 2023/06/01 21:31:59 by bkarlida         ###   ########.fr       */
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

int		export_equal(char *str)
{
	int i;
	int k;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	k = 0;
	g_var.ex_equal = malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		if ((str[0] >= '0' && str[0] <= '9') || str[0] == '=')
			return(0);
		if (str[i] == '=')
		{
			while (str[k])
			{
				g_var.ex_equal[j] = str[k];
				if (str[k] == '=' && flag == 0)
				{
					k++;
					j++;
					g_var.ex_equal[j] = '"';
					flag = 1;
				}
				k++;
				j++;
			}
			g_var.ex_equal[j] = '"';
			j++;
			g_var.ex_equal[j] = '\0';
			return(1);
		}
		i++;
	}
	return(0);
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
		printf("*****%s\n", g_var.export[i]);
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