/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fnc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:04:58 by rloussig          #+#    #+#             */
/*   Updated: 2023/04/24 10:05:03 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *a, size_t len)
{
	size_t	i;
	size_t	pmin;
	size_t	pnow;
	size_t	pnext;

	pmin = find_pos_smaller(a, len);
	pnow = pmin;
	i = -1;
	while (++i < len - 1)
	{
		pnext = pnow + 1;
		if (pnext >= len)
			pnext = 0;
		if (a[pnext] != a[pnow] + 1)
			return (0);
		pnow++;
		if (pnow >= len)
			pnow = 0;
	}
	return (1);
}

int	is_all_sorted(int *a, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len - 1)
	{
		if (a[i] + 1 != a[i + 1])
			return (0);
	}
	return (1);
}
