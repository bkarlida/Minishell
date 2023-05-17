/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:50:31 by bkarlida          #+#    #+#             */
/*   Updated: 2023/05/17 09:23:31 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    strequal(char *str, char *ptr)
{
    int i;
    int len;

    i = 0;
    len = 0;
    str = ft_tolower(str);
    ptr = ft_tolower(ptr);
    while (str[i])
    {
        if (str[i] == ptr[i])
            len++;
        else
            break;
        i++;
    }
    if (ft_strlen(str) == len)
        return(1);
    else
        return(0);
}