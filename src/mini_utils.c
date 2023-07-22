/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:40:45 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/21 17:28:42 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	command_prepare(void)
{
	t_ink_list	*tmp;
	int			i;

	i = 0;
	tmp = g_var.lst;
	g_var.lst_size = link_lstsize(g_var.lst);
	g_var.str = malloc(sizeof(char *) * (g_var.lst_size + 1));
	while (tmp)
	{
		g_var.str[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	g_var.str[i] = NULL;
}

void	env_malloc(char **envp)
{
	int	i;
	int	len;

	len = 0;
	while (envp[len])
		len++;
	g_var.env_size = len;
	i = 0;
	g_var.env = malloc(sizeof(char *) * (g_var.env_size + 2));
	while (envp[i])
	{
		g_var.env[i] = ft_strdup(envp[i]);
		i++;
	}
	g_var.env[i] = NULL;
}

void	env_export(char **envp)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (envp[len])
		len++;
	g_var.export_size = len;
	g_var.exports = malloc(sizeof(char *) * (g_var.export_size + 2));
	while (envp[i])
	{
		g_var.exports[i] = ft_strdup(envp[i]);
		i++;
	}
	g_var.exports[i] = NULL;
}

void	null_init(int ac, char **av, char **envp)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigint_handler);
	(void)ac;
	(void)av;
	g_var.exit_status = 0;
	g_var.str = NULL;
	g_var.env = NULL;
	g_var.exports = NULL;
	g_var.cmd = NULL;
	g_var.cmds = NULL;
	g_var.pipe = NULL;
	g_var.pid = NULL;
	g_var.help = NULL;
	g_var.path_env = NULL;
	g_var.rdr_left = 1;
	env_malloc(envp);
	env_export(envp);
}
