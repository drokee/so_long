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

int	quit(t_data *utils)
{
	destroyimg(utils);
	exit(0);
}

void	checknl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			ft_printf("Error\n");
			free(str);
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
			hilper2(utils, i);
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
		free_doublearr(utils->map, utils);
		exit(1);
	}
}
