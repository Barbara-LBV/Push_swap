/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:07:52 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/11 17:18:58 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstclear(t_list **lst)
{
	t_list	*tmp;

	if ((*lst) == NULL)
		return ;
	while ((*lst)->before != NULL)
		(*lst) = (*lst)->before;
	while (*lst)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
	}
	free(*lst);
}

char	*to_bin(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 33);
	while (i < 32)
	{
		str[i] = (n >> (31 - i) & 1) + '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_list	*get_list(t_list **a, int content)
{
	if (!(*a))
		*a = lstnew(content);
	else
		lstadd_end(a, lstnew(content));
	return (*a);
}

/*int main(int ac, char **av)
{
	(void)ac;
	int nb = ft_atoi(av[1]);
	char *s;
	int i = 0;

	s = to_bin(nb);
	printf("valeur binaire de nb : %s\n", s);
	printf("valeur binaire de nb : nb<<1 = %d\n", nb<<=1);
	printf("valeur binaire de nb : nb>>1 = %d\n", nb>>1);
	while (i++ < 32)
	{
		printf("valeur binaire de nb : nb>>i & 1 = %d\n", (nb>>i)&1);
		//i++;
		//printf("valeur binaire de nb : nb>>i & 0 = %d\n", nb>>i&0);
	}
	return (0);
}*/
