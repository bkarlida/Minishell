/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:09:05 by bkarlida          #+#    #+#             */
/*   Updated: 2023/05/31 17:46:30 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char a)
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')
		|| (a >= '0' && a <= '9'))
		return (1);
	return (0);
}
