/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahdiou <amahdiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:30:44 by amahdiou          #+#    #+#             */
/*   Updated: 2023/04/10 02:30:46 by amahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"solong.h"

void	pathchecker(t_data *utils, int y, int x)
{
	int	i;
	int	j;
	int	countdown;

	i = 0;
	j = 0;
	countdown = x * y;
	while (countdown > 0)
	{
		i = 0;
		while (i != y)
		{
			while (j != x)
			{
				if (utils->mapc[i][j] == 'P')
					player(utils, i, j);
				j++;
			}
			j = 0;
			i++;
		}
		countdown--;
	}
	coincheck(utils, y, x);
	pathvalid(utils, y, x);
}

void	player(t_data *utils, int i, int j)
{
	if (utils->mapc[i - 1][j] == 'C' || utils->mapc[i - 1][j] == '0')
					utils->mapc[i - 1][j] = 'P';
	if (utils->mapc[i + 1][j] == 'C' || utils->mapc[i + 1][j] == '0')
					utils->mapc[i + 1][j] = 'P';
	if (utils->mapc[i][j + 1] == 'C' || utils->mapc[i][j + 1] == '0')
						utils->mapc[i][j + 1] = 'P';
	if (utils->mapc[i][j - 1] == 'C' || utils->mapc[i][j - 1] == '0')
						utils->mapc[i][j - 1] = 'P';
}

void	coincheck(t_data *utils, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != y)
	{
		while (j != x)
		{
			if (utils->mapc[i][j] == 'C')
			{
				ft_printf("invalid path");
				exit(1);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	pathvalid(t_data *utils, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != y)
	{
		while (j != x)
		{
			if (utils->mapc[i][j] == 'E')
			{
				if (utils->mapc[i - 1][j] != 'P' && utils->mapc[i + 1][j] != 'P'\
				&& utils->mapc[i][j + 1] != 'P' && utils->mapc[i][j - 1] != 'P')
				{
					ft_printf("invalidpath");
					exit(1);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
}
