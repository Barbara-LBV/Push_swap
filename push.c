/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:49:35 by blefebvr          #+#    #+#             */
/*   Updated: 2022/10/19 16:38:49 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_a(t_list *a, t_list *b)
{
	t_list	*first_b;
	t_list	*new_first_b;

	if (!a || !b || a->next == NULL || b->next == NULL)
		return (NULL);
	first_b = b;
	new_first_b = lstnew(a->content);
	new_first_b->index = a->index;
	new_first_b->before = NULL;
	new_first_b->next = first_b;
	return (new_first_b);
}

t_list	*push_b(t_list *a, t_list *b)
{
	t_list	*first_a;
	t_list	*new_first_a;

	if (!a || !b || a->next == NULL || b->next == NULL)
		return (NULL);
	first_a = a;
	new_first_a = lstnew(b->content);
	new_first_a->index = b->index;
	new_first_a->before = NULL;
	new_first_a->next = first_a;
	return (new_first_a);
}

/*void	pop(t_stack *pile, int new_n)
{
	s_stack *new = malloc(sizeof(*new));

	if (pile == NULL || new == NULL)
		exit();

	new->value = new_n;
	new->next = pile-> first;
	pile->first = new;
}*/

int main()
{
	t_list	*test1 = NULL;
	t_list	*test2 = NULL;
	int	n1 = 0;
	int	n2 = 3;

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
	printf("\nPUSH B\nNew list A\n");
	while (test1->before != NULL)
		test1 = test1->before;
	while (test2->before != NULL)
		test2 = test2->before;
	test2 = push_b(test1, test2);
	while (test2 != NULL)
	{
		printf("%d ", test2->content);
		if (test2->next == NULL)
			break ;
		test2 = test2->next;
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

//	lstclear(&test1);
//	lstclear(&test2);
	return (0);
}
