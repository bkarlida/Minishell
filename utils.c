/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:50:31 by bkarlida          #+#    #+#             */
/*   Updated: 2023/06/01 14:59:12 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_func(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i++]);
    }
    free(str);
}

int		find_helper(char **p, char *a)
{
	int i;
	int k;
	int flag;

	i = 0;
	while (p[i])
	{
		k = 0;
		flag = 0;
		while (p[i][k])
		{
			flag = 1;
			if (p[i][k] == a[k])
			{
				k++;
			}
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			return(1);
		i++;
	}
	return(0);
}

int    strequal(char *str, char *ptr)
{
    int i;
    int len;

    i = 0;
    len = 0;
    ft_tolower(str);
   	ft_tolower(ptr);
	if (ft_strlen(str) != ft_strlen(ptr))
		return (0);
    while (str[i])
    {
        if (str[i] == ptr[i])
            len++;
        else
            break;
        i++;
    }
    if (ft_strlen(ptr) == len)
    {
        return(1);
    }
    else
        return(0);
}

int	double_len(char **str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void     ft_unset(char *str)
{
	int i;
	int k;
	int flag;
	int len;

	i = 0;
	k = 0;
	flag = 0;
	len = ft_strlen(str);
	while (g_var.env[i])
	{
		if (ft_strncmp(g_var.env[i], str, len))
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag)
	{
		while (g_var.env[i])
		{
			g_var.env[i] = g_var.env[i + 1];
			i++;
		}
		free(g_var.env[i]);
	}
}
