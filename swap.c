/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:52:48 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/03 14:55:06 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!(*a) || ((*a)->next == NULL))
		return ;
	first = *a;
	second = (*a)->next;
	if ((*a)->next->next != NULL)
		third = (*a)->next->next;
	else
		third = NULL;
	first->before = second;
	first->next = third;
	second->before = NULL;
	second->next = first;
	third->before = first;
	*a = second;
	write(1, "sa\n", 3);
}

void	swap_b(t_list **b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!(*b))
		return ;
	first = *b;
	second = (*b)->next;
	if ((*b)->next->next != NULL)
		third = (*b)->next->next;
	first->before = second;
	first->next = third;
	second->before = NULL;
	second->next = first;
	third->before = first;
	*b = second;
	write(1, "sb\n", 3);
}

void	swap_s(t_list **a, t_list **b)
{
	if ((!(*a) && !(*b)) || (*a)->next == NULL || (*b)->next == NULL)
		return ;
	swap_a(a);
	swap_b(b);
	write(1, "ss\n", 3);
}

/*int main()
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
	swap_a(&test);
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
