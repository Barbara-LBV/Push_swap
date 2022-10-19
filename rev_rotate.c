/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:56:02 by blefebvr          #+#    #+#             */
/*   Updated: 2022/10/19 15:01:56 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rev_rot_a(t_list *a)
{
	t_list	*first;
	t_list	*before_last;
	t_list	*last;

	if (!a || a->next == NULL)
		return (NULL);
	first = a;
	while (a->next != NULL)
	{
		a = a->next;
		last = a;
	}
	before_last = a->before;
	last->next = first;
	last->before = NULL;
	first->before = last;
	before_last->next = NULL;
	return(last);
}

t_list	rev_rot_b(t_list *b)
{
	t_list	*first;
	t_list	*before_last;
	t_list	*last;

	if (!b || b->next == NULL)
		return (NULL);
	first = b;
	while (b->next != NULL)
	{
		b = b->next;
		last = b;
	}
	before_last = b->before;
	last->next = first;
	last->before = NULL;
	first->before = last;
	before_last->next = NULL;
	return(last);
}

/*void	rev_rot_r(int n1, int n2)
{
}

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
	test = rev_rot_a(test);
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	lstclear(&test);
	return (0);
}*/
