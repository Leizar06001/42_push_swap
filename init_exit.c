/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:05:11 by rloussig          #+#    #+#             */
/*   Updated: 2023/04/24 10:05:13 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	malloc_struct(t_info *info, size_t size, char *argv[])
{
	size_t	i;
	long	tmp;

	info->a = ft_calloc(size);
	info->b = ft_calloc(size);
	info->c = ft_calloc(size);
	if (!info->a || !info->b || !info->c)
		return (2);
	i = -1;
	while (++i < size)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (8);
		info->a[i] = tmp;
	}
	simplify_numbers(info);
	return (0);
}

int	init_struct(t_info *info, size_t size)
{
	info->sa = size;
	info->sb = 0;
	info->a = NULL;
	info->b = NULL;
	info->c = NULL;
	info->pos = 0;
	if (size < 100)
		info->range = 20;
	else if (size < 300)
		info->range = 30;
	else if (size < 2000)
		info->range = 50;
	else
		info->range = 100;
	return (0);
}

void	errors(int err)
{
	if (err > 1 && err != 99)
		write(1, "Error\n", 6);
}

void	clean_exit(t_info *info)
{
	int	i;

	if (info->a)
		free(info->a);
	if (info->b)
		free(info->b);
	if (info->c)
		free(info->c);
	i = 1;
	if (info->split)
	{
		while (i < info->argc)
		{
			free(info->argv[i]);
			i++;
		}
		free(info->argv);
	}
}
