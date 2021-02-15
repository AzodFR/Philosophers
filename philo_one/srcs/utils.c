/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:10:05 by thjacque          #+#    #+#             */
/*   Updated: 2021/02/15 15:24:26 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philone.h"

int		print_error(char *s, t_params *p)
{
	prefix(p);
	printf("\033[91m%s\033[0m\n", s);
	free(p);
	return (1);
}

int			ft_atoi(const char *nbtr)
{
	long int	nb;
	int			neg;
	int			i;

	i = 0;
	neg = 0;
	nb = 0;
	while (nbtr[i] && ((nbtr[i] >= 9 && nbtr[i] <= 13) || nbtr[i] == ' '))
		i++;
	if (nbtr[i] == '+' || nbtr[i] == '-')
	{
		if (nbtr[i] == '-')
			neg++;
		i++;
	}
	while (nbtr[i] && (nbtr[i] >= '0' && nbtr[i] <= '9'))
	{
		nb *= 10;
		nb += nbtr[i++] - 48;
	}
	if (i > 20)
		return (neg ? 0 : -1);
	return (neg ? -nb : nb);
}

void	prefix(t_params *p)
{
	struct timeval	actual;
	gettimeofday(&actual, NULL);
	printf("%.0f [\033[93mPhilosophers\033[0m] ", (double)
	(actual.tv_usec - p->start.tv_usec) / 1000 + (double)
	(actual.tv_sec - p->start.tv_sec) * 1000);
}