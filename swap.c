/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:52:48 by blefebvr          #+#    #+#             */
/*   Updated: 2022/10/19 14:35:38 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap_a(t_list *a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!a || a->next == NULL)
		return (NULL);
	first = a;
	second = a->next;
	if ((a->next)->next != NULL)
		third = (a->next)->next;
	first->before = second;
	first->next = third;
	second->before = NULL;
	second->next = first;
	third->before = first;
	return (second);
}

t_list	*swap_b(t_list *b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!b)
		return (NULL);
	first = b;
	second = b->next;
	if ((b->next)->next != NULL)
		third = (b->next)->next;
	first->before = second;
	first->next = third;
	second->before = NULL;
	second->next = first;
	third->before = first;
	return (second);
}

/*void	swap_s(t_list *a,t_list *b) // A VERIFIER !!!!
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!a && !b)
		return ;
	tmp1 = swap_a(a);
	tmp2 = swap_b(b);
}*/

int main()
{
	t_list	*test = NULL;
	int	n = 3;

	if (!test)
		test = lstnew(n--);
	while (n > 0)
		lstadd_end(&test, lstnew(n--));
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	printf("\nSWAP A!! : \n");
	while (test->before != NULL)
		test = test->before;
	test = swap_a(test);
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
