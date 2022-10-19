/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:39:10 by blefebvr          #+#    #+#             */
/*   Updated: 2022/10/19 15:57:36 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

/*typedef struct s_stack
{
	int		value; // le nb to sort
	int		index; //son index dans la liste de tousles nb a trier
	int		pos; // sa pos actuelle dans la pile dans laquelle ce nb se trouve
	int		target_pos;// la pos. cibledan sla pile A où l'element de la pile B devrait se trouver
	int		cost_a; //cb d'actions cela couterait de faire pivoter la pile A pour que l’él. à la position ciblée arrive au sommet de la pile A,
	int		cost_b; //cb d’actions cela coûterait de faire pivoter la pile B pour que cet él. arrive au sommet de la pile B,
	struct s_stack	*next; //pointeur vers le prochain élément de la liste.
}	t_stack;*/

typedef struct s_list
{
	int		content;
	int		index;
	char		*binary;
	struct s_list	*before;
	struct s_list	*next;
}	t_list;

t_list	*firstelement(t_list *lst);
t_list	*lstnew(int content);
void	lstadd_end(t_list **lst, t_list *new);
t_list	*lstadd_first(t_list **lst, t_list *new);
void	lstclear(t_list **lst);
t_list	*rotate_a(t_list *a);
t_list	*rotate_b(t_list *b);
void	rotate_r(t_list *a, t_list *b);
t_list	*rev_rot_a(t_list *a);
t_list	*rev_rot_b(t_list *b);
void	rev_rot_r(t_list *a,t_list *b);
t_list	*push_a(t_list *a, t_list *b);
t_list	*push_b(t_list *a, t_list *b);
t_list	*swap_a(t_list *a);
t_list	*swap_b(t_list *b);
void	swap_s(t_list *a, t_list *b);

#endif
