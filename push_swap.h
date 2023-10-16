/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:06:11 by rloussig          #+#    #+#             */
/*   Updated: 2023/04/24 10:06:13 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_info
{
	int		argc;
	int		split;
	char	**argv;
	size_t	sa;
	size_t	sb;
	int		*a;
	int		*b;
	int		*c;
	size_t	range;
	int		instr[500000];
	int		pos;
}				t_info;

typedef struct s_opti
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	p_lock;
}				t_opti;

int		malloc_struct(t_info *info, size_t size, char *argv[]);
int		init_struct(t_info *info, size_t size);
void	clean_exit(t_info *info);
void	errors(int err);

void	sort_2(t_info *dt, int ab, int rev);
void	sort_3(t_info *dt);
void	sort_5(t_info *dt);

void	sort_big(t_info *dt);

char	**ft_split(char const *s, char c, t_info *info);

int		is_sorted(int *a, size_t len);
int		is_all_sorted(int *a, size_t len);

void	opti_rrr(int *li, int len);

size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str);
int		*ft_calloc(size_t size);
int		ft_strcmp(char *s1, char *s2);

void	loop(t_info *dt);

void	swap(t_info *dt, int li);
void	pushab(t_info *dt);
void	pushba(t_info *dt);
void	rot(t_info *dt, int li);
void	revrot(t_info *dt, int li);

int		find_min(int *a, size_t size);
int		find_max(int *a, size_t size);
int		find_pos_smaller(int *a, size_t size);
int		find_pos_bigger(int *a, size_t size);
void	simplify_numbers(t_info *dt);

void	prt_rot(t_opti *op);
void	prt_revrot(t_opti *op);
int		count_rr(t_opti *op, int *li, int len);
int		count_rrr(t_opti *op, int *li, int len);

void	rewind_and_return(t_info *dt);
int		valid_pos(int to_push, int pos0, int pos1);
int		check_push_ab(t_info *dt);

#endif
