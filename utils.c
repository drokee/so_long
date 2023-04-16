/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahdiou <amahdiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:19:11 by amahdiou          #+#    #+#             */
/*   Updated: 2023/04/15 23:19:12 by amahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"solong.h"

void	movescounter(t_data *utils)
{
	utils->moves++;
	ft_printf("moves : %d\n", utils->moves);
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

void	dupchar(t_data *utils)
{
	if (utils->p != 1 || utils->e != 1 || utils->c < 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
}
