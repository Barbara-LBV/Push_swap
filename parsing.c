/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:40:55 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/03 14:18:42 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_list **a)
{
	t_list	*tmp;

	if (!(*a) || (*a)->next == NULL)
		return (0);
	tmp = (*a)->next;
	while ((*a)->next != NULL)
	{
		while (tmp->next != NULL && tmp->content != (*a)->content)
			tmp = tmp->next;
		if (tmp->content == (*a)->content)
			return (1);
		*a = (*a)->next;
	}
	return (0);
}

int	check_nb(char *s)
{
	if (*s == '\0')
		return (1);
	while (*s != '\0')
	{
		if (*s < 48 || *s > 57)
			return (1);
		s++;
	}
	return (0);
}

int	check_flow(long int n)
{
	int	nb;

	nb = n;
	if (nb != n)
		return (1);
	return (0);
}

t_list	*get_list(t_list **a, int content)
{
	if (!a)
		(*a) = lstnew(content);
	else
		lstadd_end(a, lstnew(content));
	return (*a);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	if (*str == '-')
	{
		neg *= -1;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i++] - '0';
	}
	nb *= neg;
	return (nb);
}

/*int main(int ac, char **av)
{
	t_list	*test = NULL;
	int	i = 1;

	(void)ac;
	while (av[i] != NULL && check_arg(av[i]) == 0)
	{
		if (!test)
			test = lstnew(ft_atoi(av[i++]));
		else
			lstadd_end(&test, lstnew(ft_atoi(av[i++])));
	}
	if (av[i] != NULL && check_arg(av[i]) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	printf("\nCHECK DOUBLE : \n");
	while (test->before != NULL)
		test = test->before;
	if (check_double(test) == 1)
		printf("double !");
	else if (check_double(test) == 0)
		printf("no double !");
	lstclear(&test);
	return (0);
}*/
