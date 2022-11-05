/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:39:10 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/04 17:24:21 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int		content;
	int		index;
	int		position;
	struct s_list	*before;
	struct s_list	*next;
}	t_list;

t_list	*firstelement(t_list **lst);
t_list	*lstnew(int content);
t_list	*lstadd_first(t_list **lst, t_list *new);
t_list	*get_list(t_list **a, int n);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rev_rot_a(t_list **a);
void	rev_rot_b(t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	print_list(t_list **a, t_list **b);
void	lstadd_end(t_list **lst, t_list *new);
void	lstclear(t_list **lst);
void	rotate_r(t_list **a, t_list **b);
void	rev_rot_r(t_list **a, t_list **b);
void	swap_s(t_list **a, t_list **b);
void	sort_three_nb(t_list **a);
void	sort_five_nb(t_list **a, t_list **b);
void	sort_nb(t_list **a, t_list **b);
void	get_index(t_list *a);
int	check_sorting(t_list **lst);
int	check_double(t_list **a);
int	get_sizelst(t_list **a);
int	check_parsing(t_list *a, char *s);
int	check_nb(char *s);
int	check_flow(long int n);
int	ft_atoi(const char *str);

#endif
