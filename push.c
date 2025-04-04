/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:49:35 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/10 10:50:33 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list **a, t_list **b)
{
	t_list	*first_b;
	t_list	*second_a;

	if (!(*a))
		return ;
	second_a = (*a)->next;
	if (!(*b))
		*b = lstnew_node(*a);
	else
	{
		first_b = *b;
		(*b) = lstadd_first(b, lstnew_node(*a));
		(*b)->next = first_b;
		(*b)->before = NULL;
	}
	if (second_a != NULL)
	{
		free(*a);
		second_a->before = NULL;
		*a = second_a;
	}
	else
		lstclear(a);
	write(1, "pb\n", 3);
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*first_a;
	t_list	*second_b;

	if (!(*b))
		return ;
	second_b = (*b)->next;
	if (!(*a))
		lstnew_node(*b);
	else
	{
		first_a = *a;
		*a = lstadd_first(a, lstnew_node(*b));
		(*a)->next = first_a;
		(*a)->before = NULL;
	}
	if (second_b != NULL)
	{
		free(*b);
		second_b->before = NULL;
		*b = second_b;
	}
	else
		lstclear(b);
	write(1, "pa\n", 3);
}

/*int main()
{
	t_list	*test1 = NULL;
	t_list	*test2 = NULL;
	int n1=0;
	int n2=2;
	if (!test1)
		test1 = lstnew(n1++);
	if (!test2)
		test2 = lstnew(n2--);
	while (n1 < 2)
		lstadd_end(&test1, lstnew(n1++));
	while (n2 > 0)
		lstadd_end(&test2, lstnew(n2--));
	printf("list A\n");
	if (test1 == NULL)
		printf("la liste A est vide");
	while (test1 != NULL)
	{
		printf("%d ", test1->content);
		if (test1->next == NULL)
			break ;
		test1 = test1->next;
	}
	printf("\nlist B\n");
	if (test2 == NULL)
		printf("la liste B est vide");
	while (test2 != NULL)
	{
		printf("%d ", test2->content);
		if (test2->next == NULL)
			break ;
		test2 = test2->next;
	}
	printf("\nPUSH A\nNew list A\n");
	test1 = firstelement(&test1);
	test2 = firstelement(&test2);
	push_b(&test1, &test2);
	//test1 = firstelement(&test1);
	//test2 = firstelement(&test2);
	push_b(&test1, &test2);
	//test1 = firstelement(&test1);
	//test2 = firstelement(&test2);
	//push_a(&test1, &test2);
	//test1 = firstelement(&test1);
	//test2 = firstelement(&test2);
	while (test1 != NULL)
	{
		printf("%d ", test1->content);
		if (test1->next == NULL)
			break ;
		test1 = test1->next;
	}
	printf("\nNew list B\n");
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
