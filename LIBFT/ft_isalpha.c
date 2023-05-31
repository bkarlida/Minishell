/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:36:14 by bkarlida          #+#    #+#             */
/*   Updated: 2023/05/31 17:54:13 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(char *a)
{
	int i;

	i = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
			i++;
		else if (i != 0 && ft_isalnum(a[i]))
		{
			i++;
			continue;
		}
		else
			return(0);
	}
	return (1);
}
