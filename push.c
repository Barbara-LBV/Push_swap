/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:49:35 by blefebvr          #+#    #+#             */
/*   Updated: 2022/10/20 15:10:05 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_b(t_list *a, t_list *b)
{
	t_list	*first_b;

	if (!a)
		return (NULL);
	if (!b)
		lstnew(a->content);
	else
	{
		first_b = b;
		b = lstadd_first(&b, lstnew(a->content));
		b->next = first_b;
		b->before = NULL;
	}
	write(1, "pb\n", 3);
	return (b);
}

t_list	*push_a(t_list *a, t_list *b)
{
	t_list	*first_a;

	if (!b)
		return (NULL);
	if (!a)
		lstnew(b->content);
	else
	{
		first_a = a;
		a = lstadd_first(&a, lstnew(b->content));
		a->before = NULL;
		a->next = first_a;
	}
	write(1, "pa\n", 3);
	return (a);
}

/*int main()
{
	t_list	*test1 = NULL;
	t_list	*test2 = NULL;
	int n1=0;
	int n2=4;
	if (!test1)
		test1 = lstnew(n1++);
	if (!test2)
		test2 = lstnew(n2--);
	while (n1 < 4)
		lstadd_end(&test1, lstnew(n1++));
	while (n2 > 0)
		lstadd_end(&test2, lstnew(n2--));
	printf("list A\n");
	while (test1 != NULL)
	{
		printf("%d ", test1->content);
		if (test1->next == NULL)
			break ;
		test1 = test1->next;
	}
	printf("\nlist B\n");
	while (test2 != NULL)
	{
		printf("%d ", test2->content);
		if (test2->next == NULL)
			break ;
		test2 = test2->next;
	}
	printf("\nPUSH A\nNew list A\n");
	while (test1->before != NULL)
		test1 = test1->before;
	while (test2->before != NULL)
		test2 = test2->before;
	test1 = push_a(test1, test2);
	while (test1 != NULL)
	{
		printf("%d ", test1->content);
		if (test1->next == NULL)
			break ;
		test1 = test1->next;
	}
	printf("\nlist B\n");
	while (test2->before != NULL)
		test2 = test2->before;
	while (test2 != NULL)
	{
		printf("%d ", test2->content);
		if (test2->next == NULL)
			break ;
		test2 = test2->next;
	}
	lstclear(&test1);
	lstclear(&test2);
	return (0);
}*/
