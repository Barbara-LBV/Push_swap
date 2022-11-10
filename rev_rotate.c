/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:56:02 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/10 10:50:08 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot_a(t_list **a)
{
	t_list	*first;
	t_list	*before_last;
	t_list	*last;

	if (!(*a) || (*a)->next == NULL)
		return ;
	first = *a;
	while ((*a)->next != NULL)
	{
		*a = (*a)->next;
		last = *a;
	}
	before_last = (*a)->before;
	last->next = first;
	last->before = NULL;
	first->before = last;
	before_last->next = NULL;
	*a = last;
}

void	rra(t_list **a)
{
	rev_rot_a(a);
	write(1, "rra\n", 4);
}

void	rev_rot_b(t_list **b)
{
	t_list	*first;
	t_list	*before_last;
	t_list	*last;

	if (!(*b) || (*b)->next == NULL)
		return ;
	first = *b;
	while ((*b)->next != NULL)
	{
		*b = (*b)->next;
		last = *b;
	}
	before_last = (*b)->before;
	last->next = first;
	last->before = NULL;
	first->before = last;
	before_last->next = NULL;
	*b = last;
}

void	rrb(t_list **b)
{
	rev_rot_b(b);
	write(1, "rrb\n", 4);
}

void	rev_rot_r(t_list **a, t_list **b)
{
	if (!(*a) || !(*b) || (*a)->next == NULL || (*b)->next == NULL)
		return ;
	rev_rot_a(a);
	rev_rot_b(b);
	write(1, "rrr\n", 4);
}

/*
//   MAIN TEST RRR

int main()
{
	t_list	*test = NULL;
	t_list	*test1 = NULL;
	int	n = 0;
	int	n1 = 3;

	if (!test)
		test = lstnew(n++);
	while (n < 4)
		lstadd_end(&test, lstnew(n++));
	if (!test1)
		test1 = lstnew(n1--);
	printf("\nlist a : ");
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	while (n1 >= 0)
		lstadd_end(&test1, lstnew(n1--));
	printf("\nlist b : ");
	while (test1 != NULL)
	{
		printf("%d ", test1->content);
		if (test1->next == NULL)
			break ;
		test1 = test1->next;
	}
	printf("\nREVERSE ROTATE : ");
	while (test->before != NULL)
		test = test->before;
	while (test1->before != NULL)
		test1 = test1->before;
	rev_rot_r(test, test1);
	printf("\nlist a : ");
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	//lstclear(&test);
	printf("\nlist b : ");
	while (test1 != NULL)
	{
		printf("%d ", test1->content);
		if (test1->next == NULL)
			break ;
		test1 = test1->next;
	}
	//lstclear(&test1);
	return (0);
}

//   MAIN TEST RRA & RRB

int main()
{
	t_list	*test = NULL;
	int	n = 0;

	if (!test)
		test = lstnew(n++);
	while (n < 2)
		lstadd_end(&test, lstnew(n++));
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	printf("\nREVERSE ROTATE : \n");
	test = firstelement(&test);
	rev_rot_a(&test);
	test = firstelement(&test);
	rev_rot_a(&test);
	test = firstelement(&test);
	rev_rot_a(&test);
	test = firstelement(&test);
	rev_rot_a(&test);
	test = firstelement(&test);
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
*/
