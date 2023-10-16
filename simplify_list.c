/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:06:23 by rloussig          #+#    #+#             */
/*   Updated: 2023/04/24 10:06:24 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *a, size_t size)
{
	size_t	i;
	int		min;

	i = 0;
	min = (unsigned int)(-1) / 2;
	while (i < size)
	{
		if (a[i] < min)
			min = a[i];
		i++;
	}
	return (min);
}

int	find_max(int *a, size_t size)
{
	size_t	i;
	int		max;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	return (max);
}

int	find_pos_smaller(int *a, size_t size)
{
	int		pmin;
	size_t	i;

	i = 0;
	pmin = 0;
	while (++i < size)
	{
		if (a[i] < a[pmin])
			pmin = i;
	}
	return (pmin);
}

int	find_pos_bigger(int *a, size_t size)
{
	int		pmax;
	size_t	i;

	i = 0;
	pmax = 0;
	while (++i < size)
	{
		if (a[i] > a[pmax])
			pmax = i;
	}
	return (pmax);
}

void	simplify_numbers(t_info *dt)
{
	size_t	i;
	size_t	j;
	int		min;
	int		pmin;
	int		prec;

	prec = find_pos_smaller(dt->a, dt->sa);
	dt->c[prec] = 1;
	i = 0;
	while (i < dt->sa - 1)
	{
		j = 0;
		min = (unsigned int)(-1) / 2;
		while (j < dt->sa)
		{
			if (dt->a[j] < min && dt->a[j] > dt->a[prec])
			{
				min = dt->a[j];
				pmin = j;
			}
			j++;
		}
		prec = pmin;
		dt->c[pmin] = ++i + 1;
	}
}
