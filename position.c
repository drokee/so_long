/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahdiou <amahdiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:37:36 by amahdiou          #+#    #+#             */
/*   Updated: 2023/04/14 04:37:38 by amahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_pos	playerpos(t_data *utils)
{
	t_pos	playerp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	playerp.x = -1;
	playerp.y = -1;
	while (utils->map[i])
	{
		while (utils->map[i][j])
		{
			if (utils->map[i][j] == 'P')
			{
				playerp.y = i;
				playerp.x = j;
				return (playerp);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (playerp);
}

char	charposition(t_data *utils, t_pos *thisone)
{
	int			i;
	int			j;
	char		here;

	i = 0;
	j = 0;
	here = '\0';
	while (utils->map[i])
	{
		while (utils->map[i][j])
		{
			if (i == thisone->y && j == thisone->x)
				return (utils->map[i][j]);
				j++;
		}
		i++;
		j = 0;
	}
	return (here);
}

void	charchanger(t_data *utils, t_pos *whichone, char thatone)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (utils->map[i])
	{
		while (utils->map[i][j])
		{
			if (i == whichone->y && j == whichone->x)
				utils->map[i][j] = thatone;
			j++;
		}
		i++;
		j = 0;
	}
}
