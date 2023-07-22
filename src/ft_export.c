/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:14:01 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/21 17:27:20 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	export_equal(char *str)
{
	int	i;

	i = -1;
	while (g_var.exports[++i])
	{
		if (len_equal(g_var.exports[i]) == len_equal(str))
			if (!ft_strncmpv2(g_var.exports[i],
					str, len_equal(g_var.exports[i])))
				return (i);
	}
	return (-1);
}

void	env_fn(char *str)
{
	char	**temp;
	int		len;
	int		i;
	int		index;

	index = export_equal(str);
	if (index == -1)
	{
		len = splt_len(g_var.env);
		temp = malloc(sizeof(char *) * (len + 2));
		i = -1;
		while (g_var.env[++i])
			temp[i] = ft_strdup(g_var.env[i]);
		temp[i] = ft_strdup(str);
		temp[++i] = 0;
		free_func(g_var.env);
		g_var.env = temp;
	}
	else
	{
		free(g_var.env[index]);
		g_var.env[index] = ft_strdup(str);
	}
}

void	export_fn(char *str)
{
	char	**temp;
	int		i;
	int		index;

	index = export_equal(str);
	if (index == -1)
	{
		temp = malloc(sizeof(char *) * (splt_len(g_var.exports) + 2));
		i = -1;
		while (g_var.exports[++i])
			temp[i] = ft_strdup(g_var.exports[i]);
		temp[i] = ft_strdup(str);
		temp[++i] = 0;
		free_func(g_var.exports);
		g_var.exports = temp;
	}
	else
	{
		if (!is_equal(str))
		{
			free(g_var.exports[index]);
			g_var.exports[index] = ft_strdup(str);
		}
	}
}

void	ft_export(void)
{
	int	i;
	int	len;

	len = splt_len(g_var.cmds[0]->str);
	i = 0;
	while (++i < len)
	{
		if (is_alphanum(g_var.cmds[0]->str[i],
				len_equal(g_var.cmds[0]->str[i])))
		{
			export_fn(g_var.cmds[0]->str[i]);
			if (!is_equal(g_var.cmds[0]->str[i]))
				env_fn(g_var.cmds[0]->str[i]);
		}
		else
			printf("minishell: export: %s: not a valid identifier\n",
				g_var.cmds[0]->str[i]);
	}
}
