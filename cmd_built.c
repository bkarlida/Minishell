/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:03:30 by bkarlida          #+#    #+#             */
/*   Updated: 2023/05/25 02:54:40 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(void)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (g_var.env[i])
    {
		len++;
		printf("%s\n", g_var.env[i++]);
    }
	g_var.env_size = len;
	printf("%d\n", g_var.env_size);
	
}

void    ft_pwd(void)
{
   	int i;
   	int k;
    char *a;

	i = 0;
	k = 4;
	printf("-------Pwd_komutu_çalıştı!------\n");
	while (g_var.env[i])
    {
        if (g_var.env[i][0] == 'P' && g_var.env[i][1] == 'W' && g_var.env[i][2] == 'D')
        {
				
            while (g_var.env[i][k])
            {
                printf("%c", g_var.env[i][k++]);
            }
            printf("\n");
            break;
        }
        i++;
    }
}

int	arg_isdigit(char *a)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(a);
	while (a[i] >= '0' && a[i] <= '9')
	{
		i++;
	}
	if (len == i)
	{
		return (1);
		
	}
	else
		return (0);
}

void	ft_exit(void)
{
	int i;

	i = 0;
	if (g_var.str[i + 1] == NULL)
	{
		printf("exit\n");
		exit(0);
	}
	else if(arg_isdigit(g_var.str[i + 1]) && g_var.str[i + 2] != NULL)
	{
		printf("exit\n");
		printf("minishell$: exit: too many arguments\n");
	}
	else if (arg_isdigit(g_var.str[i + 1]) && g_var.str[i + 2] == NULL)
	{
		printf("exit\n");
		exit(0);
	}
	else
	{
		printf("exit\n");
		printf("minishell$: exit: %s: numeric argument required", g_var.str[i + 1]);
		exit(0);
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
		i++;
	}
	return(1);
}