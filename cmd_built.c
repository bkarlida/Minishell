/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:03:30 by bkarlida          #+#    #+#             */
/*   Updated: 2023/05/29 21:32:47 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_export(void)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (g_var.env[i])
	{
		while (g_var.env[i][k])
		{
			
		}
		
	}
	
}



int		command_built(void)
{
	int i;

	i = 0;
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
			ft_pwd();
			return(0);
		}
		i++;
	}
	return(1);
}