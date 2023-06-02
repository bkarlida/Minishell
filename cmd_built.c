/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:03:30 by bkarlida          #+#    #+#             */
/*   Updated: 2023/06/02 22:00:17 by bkarlida         ###   ########.fr       */
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

int		is_equal(char *str)
{
	int i;

	i = 0;
	perror("zooooooooort");
	while (str[i])
	{
		if (str[0] == '=')
			return(0);
		else if (str[i] == '=')
		{
			return(1);
		}
		else
			i++;
	}
	return(0);
}

char	*export_equal(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * ft_strlen(str));
	while (str[i] != '=')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	printf("-----%s**************************************\n", new);
	return(new);
}

int		find_equal(char **str, char *new)
{
	int i;
	int flag;
	int j;
	int k;
	int c;

	i = 0;
	flag = 0;
	while (str[i])
	{
		k = 0;
		flag = 0;
		c = 0;
		j = 0;
		while (str[i][k])
		{
			if (str[i][k] == new[c])
			{
				flag++;
			}
			k++;
			if (str[i][k] == '=')
			{
				break;
			}
			c++;
		}
		printf("%duuuu\n", flag);
		printf("%duuuu\n", c);
		if (flag == c)
		{
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
	printf("ldkasdikasdsf\n");
	while (g_var.str[i])
	{
		if (g_var.str[i][0] == '>' || g_var.str[i][0] == '<' ||
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
		if (g_var.str[k][0] != '>' && g_var.str[k][0] != '<'
			&& g_var.str[k][0] != '|')
		{
			if (!find_helper(g_var.export, g_var.str[k]) && ft_isalpha(g_var.str[k][0]))
			{
				perror("sjuhgkjsdhajdfsohjalfdjhlkajdhflkjadflkhjalkfdhf");
				if (is_equal(g_var.str[k]))
				{
					perror("wwwwwwwwwwwwwwwwwwwwwwwwwww");
					if (find_equal(g_var.export, export_equal(g_var.str[k])))
					{
						perror("aaaaaaaaaaaaaaaaaaaaa");
						k++;
						continue;
					}
				}
				tmp[i] = ft_strdup(g_var.str[k]);
				i++;
			}
		}
		k++;
		// == ksımıları yapılacak
	}
	tmp[i] = NULL;
	free(g_var.export);
	g_var.export = tmp;
}

void	export_print(void)
{
	int i;

	i = 0;
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
			if (g_var.lst_size > 1)
			{
				ft_export();
			}
			else
				export_print();
			return(0);
		}
		i++;
	}
	return(1);
}