/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:05:49 by rloussig          #+#    #+#             */
/*   Updated: 2023/04/24 10:05:50 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_info *dt, int li)
{
	int	tmp;
	int	*list;
	int	size;

	size = dt->sa;
	list = dt->c;
	if (li == 1)
	{
		size = dt->sb;
		list = dt->b;
		dt->instr[dt->pos] = 0;
	}
	else
		dt->instr[dt->pos] = 1;
	dt->pos++;
	if (size < 2)
		return ;
	if (list[0] == 0 || list[1] == 0)
		return ;
	tmp = list[0];
	list[0] = list[1];
	list[1] = tmp;
}

void	pushab(t_info *dt)
{
	size_t	i;

	if (dt->sa < 1)
		return ;
	dt->sb++;
	i = dt->sb;
	while (--i > 0)
		dt->b[i] = dt->b[i - 1];
	dt->b[0] = dt->c[0];
	i = -1;
	while (++i < dt->sa - 1)
		dt->c[i] = dt->c[i + 1];
	dt->sa--;
	dt->instr[dt->pos] = 2;
	dt->pos++;
}

void	pushba(t_info *dt)
{
	size_t	i;

	if (dt->sb < 1)
		return ;
	dt->sa++;
	i = dt->sa;
	while (--i > 0)
		dt->c[i] = dt->c[i - 1];
	dt->c[0] = dt->b[0];
	i = -1;
	while (++i < dt->sb - 1)
		dt->b[i] = dt->b[i + 1];
	dt->sb--;
	dt->instr[dt->pos] = 3;
	dt->pos++;
}

void	rot(t_info *dt, int li)
{
	int	i;
	int	len;
	int	tmp;
	int	*list;
	int	size;

	size = dt->sa;
	list = dt->c;
	if (li == 1)
	{
		size = dt->sb;
		list = dt->b;
		dt->instr[dt->pos] = 4;
	}
	else
		dt->instr[dt->pos] = 5;
	dt->pos++;
	len = size;
	tmp = list[0];
	i = -1;
	while (++i < len - 1)
		list[i] = list[i + 1];
	list[--len] = tmp;
}

void	revrot(t_info *dt, int li)
{
	int	i;
	int	len;
	int	tmp;
	int	*list;
	int	size;

	size = dt->sa;
	list = dt->c;
	if (li == 1)
	{
		size = dt->sb;
		list = dt->b;
		dt->instr[dt->pos] = 6;
	}
	else
		dt->instr[dt->pos] = 7;
	dt->pos++;
	len = size;
	tmp = list[len - 1];
	i = len;
	while (--i > 0)
		list[i] = list[i - 1];
	list[0] = tmp;
}
