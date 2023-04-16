/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahdiou <amahdiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:20:31 by amahdiou          #+#    #+#             */
/*   Updated: 2023/04/15 23:20:34 by amahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"solong_bonus.h"

void	movescounter(t_data *utils)
{
	utils->moves++;
}

int	quit(void)
{
	exit(0);
}

void	checknl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
}

void	hilper(t_data *utils)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < utils->y)
	{
		while (i < utils->x)
		{
			if (utils->map[0][i] != '1')
			{
				ft_printf("Error\n");
				exit (1);
			}
			if (utils->map[utils->y - 1][i] != '1')
			{
				ft_printf("Error\n");
				exit (1);
			}
			i++;
		}
		j++;
		i = 0;
	}
}
