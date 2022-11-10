/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:24:57 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/10 11:10:20 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*firstelement(t_list **lst)
{
	t_list	*tmp;

	if (!(*lst))
		return (NULL);
	tmp = *lst;
	while (tmp != NULL && tmp->before != NULL)
	{
		tmp = tmp->before;
		if (tmp->before == NULL)
			break ;
	}
	return (tmp);
}

t_list	*lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->before = NULL;
	return (new);
}

t_list	*lstnew_node(t_list *lst)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = lst->content;
	new->index = lst->index;
	new->next = NULL;
	new->before = NULL;
	return (new);
}

void	lstadd_end(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (!lst || !new)
		return ;
	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->before = last;
}

t_list	*lstadd_first(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	new->next = tmp;
	tmp->before = new;
	return (new);
}
/*int main()
{
	t_list	*test = NULL;
	//t_list	*last;
	int	n = 0;

	if (!test)
		test = lstnew(n++);
	while (n < 10)
		lstadd_end(&test, lstnew(n++));
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	printf("\nREVERSE !! : \n");
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->before == NULL)
			break ;
		test = test->before;
	}
	lstclear(&test);
	return (0);
}*/
