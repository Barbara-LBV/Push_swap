/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:54:33 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/04 11:37:54 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **a)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!(*a) || (*a)->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	while ((*a)->next != NULL)
	{
		*a = (*a)->next;
		last = *a;
	}
	first->next = NULL;
	first->before = last;
	last->next = first;
	second->before = NULL;
	(*a) = second;
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **b)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!(*b) || (*b)->next == NULL)
		return ;
	first = *b;
	second = (*b)->next;
	while ((*b)->next != NULL)
	{
		*b = (*b)->next;
		last = *b;
	}
	first->next = NULL;
	first->before = last;
	last->next = first;
	second->before = NULL;
	(*b) = second;
	write(1, "rb\n", 3);
}

void	rotate_r(t_list **a, t_list **b)
{
	if (!(*a) || !(*b) || (*a)->next == NULL || (*b)->next == NULL)
		return ;
	rotate_a(a);
	rotate_b(b);
	write(1, "rr\n", 3);
}

/*int main()
{
	t_list	*test = NULL;
	t_list	*test1 = NULL;
	int	n = 0;
	int	n1 = 4;

	test = lstnew(n++);
	test1 = lstnew(n1--);
	while (n < 4)
		lstadd_end(&test, lstnew(n++));
	while (n1 > 0)
		lstadd_end(&test1, lstnew(n1--));
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	printf("\n");
	while (test1 != NULL)
	{
		printf("%d ", test1->content);
		if (test1->next == NULL)
			break ;
		test1 = test1->next;
	}
	printf("\nROTATE : \n");
	test = firstelement(&test);
	test = firstelement(&test1);
	rotate_b(&test);
	test = firstelement(&test);
	rotate_b(&test);
	test = firstelement(&test);
	rotate_b(&test);
	test = firstelement(&test);
	test = firstelement(&test);
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	test = firstelement(&test);
	printf("\n");
	while (test1 != NULL)
	{
		printf("%d ", test1->content);
		if (test1->next == NULL)
			break ;
		test1 = test1->next;
	}
	lstclear(&test);
	lstclear(&test1);
	return (0);
}*/
