/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:06:40 by rloussig          #+#    #+#             */
/*   Updated: 2023/04/24 10:06:42 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_push_back(t_info *dt)
{
	size_t	i;
	int		maxa;
	int		push;

	if (dt->sb == 0)
		return (0);
	push = 0;
	i = 0;
	maxa = 0;
	while (i++ < dt->sa)
	{
		if (dt->c[i] > maxa)
			maxa = dt->c[i];
	}
	if ((dt->b[0] < dt->c[0] && dt->b[0] > dt->c[dt->sa - 1]))
		push = 1;
	else if (dt->b[0] > maxa && dt->c[0] == find_min(dt->c, dt->sa))
		push = 1;
	else if (dt->b[0] < dt->c[0] && !find_pos_smaller(dt->c, dt->sa))
		push = 1;
	if (push)
		pushba(dt);
	return (push);
}

void	rerot(t_info *dt)
{
	size_t	i;
	int		min;

	check_push_back(dt);
	min = find_min(dt->c, dt->sa);
	while (dt->c[0] != min)
	{
		i = 0;
		while (dt->c[i] != min)
			i++;
		if (i == 0)
			return ;
		if (i * 2 < dt->sa)
		{
			rot(dt, 0);
			while (check_push_back(dt))
				min = find_min(dt->c, dt->sa);
		}
		else
		{
			revrot(dt, 0);
			while (check_push_back(dt))
				min = find_min(dt->c, dt->sa);
		}
	}
}

void	sort_2(t_info *dt, int ab, int rev)
{
	int	one;
	int	two;

	if (ab == 0)
	{
		one = dt->c[0];
		two = dt->c[1];
	}
	else
	{
		one = dt->b[0];
		two = dt->b[1];
	}
	if ((!rev && one > two) || (rev && one < two))
		swap(dt, ab);
}

void	sort_3(t_info *dt)
{
	int	*a;

	a = dt->c;
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		swap(dt, 0);
	if (a[0] > a[1] && a[1] > a[2] && a[0] > a[2])
		swap(dt, 0);
	if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
		swap(dt, 0);
	if (dt->sb > 0)
		check_push_back(dt);
	rerot(dt);
}

void	sort_5(t_info *dt)
{
	size_t	i;

	if (!is_sorted(dt->c, dt->sa))
	{
		pushab(dt);
		if (dt->sa > 3)
			pushab(dt);
		sort_3(dt);
		while (dt->sb > 0)
		{
			if (!check_push_back(dt))
			{
				i = 0;
				while (dt->b[0] > dt->c[i])
					i++;
				if (i * 2 <= dt->sa)
					rot(dt, 0);
				else
					revrot(dt, 0);
			}
		}
	}
	rerot(dt);
}
