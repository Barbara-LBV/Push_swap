/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:54:33 by blefebvr          #+#    #+#             */
/*   Updated: 2022/10/19 14:14:29 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rotate_a(t_list *a)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!a || a->next == NULL)
		return (NULL);
	first = a;
	second = a->next;
	while (a->next != NULL)
	{
		a = a->next;
		last = a;
	}
	first->next = NULL;
	first->before = last;
	last->next = first;
	second->before = NULL;
	return(second);
}

t_list	*rotate_b(t_list *b)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!b || b->next == NULL)
		return (NULL);
	first = b;
	second = b->next;
	while (b->next != NULL)
	{
		b = b->next;
		last = b;
	}
	first->next = NULL;
	first->before = last;
	last->next = first;
	second->before = NULL;
	return(second);
}

/*void	rotate_r(t_list *a, t_list *b)
{
	t_list	
}*/

int main()
{
	t_list	*test = NULL;
	int	n = 0;

	if (!test)
		test = lstnew(n++);
	while (n < 4)
		lstadd_end(&test, lstnew(n++));
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	printf("\nROTATE : \n");
	while (test->before != NULL)
		test = test->before;
	test = rotate_a(test);
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	lstclear(&test);
	return (0);
}
