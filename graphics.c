/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahdiou <amahdiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:35:28 by amahdiou          #+#    #+#             */
/*   Updated: 2023/04/13 01:35:30 by amahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long.h"

void	imgmanager(t_data *utils)
{
	utils->mlx = mlx_init();
	utils->gamewin = mlx_new_window(utils->mlx, utils->x * 50, \
	utils->y * 50, "So long!");
	utils->mario = "./textures/supermario.xpm";
	utils->coin = "./textures/coin.xpm";
	utils->wall = "./textures/wall.xpm";
	utils->floor = "./textures/sky.xpm";
	utils->door = "./textures/door.xpm";
	utils->marioimg = mlx_xpm_file_to_image(utils->mlx, \
	utils->mario, &utils->width, &utils->height);
	utils->coinimg = mlx_xpm_file_to_image(utils->mlx, utils->coin, \
	&utils->width, &utils->height);
	utils->wallimg = mlx_xpm_file_to_image(utils->mlx, utils->wall, \
	&utils->width, &utils->height);
	utils->floorimg = mlx_xpm_file_to_image(utils->mlx, utils->floor, \
	&utils->width, &utils->height);
	utils->doorimg = mlx_xpm_file_to_image(utils->mlx, utils->door, \
	&utils->width, &utils->height);
	errorfile(utils);
	mlx_hook(utils->gamewin, 2, 0, movements, utils);
	mlx_hook(utils->gamewin, 17, 0, quit, utils);
	putdesign(utils);
	mlx_loop(utils->mlx);
}

void	destroyimg(t_data *utils)
{
	if (utils->gamewin)
	{
		mlx_destroy_image(utils->mlx, utils->floorimg);
		mlx_destroy_image(utils->mlx, utils->marioimg);
		mlx_destroy_image(utils->mlx, utils->coinimg);
		mlx_destroy_image(utils->mlx, utils->wallimg);
		mlx_destroy_image(utils->mlx, utils->doorimg);
		mlx_destroy_window(utils->mlx, utils->gamewin);
	}
}

void	putdesign(t_data *utils)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < utils->y)
	{
		while (x < utils->x)
		{
			putdesign2(utils, y, x);
			x++;
		}
		y++;
		x = 0;
	}
}

void	putdesign2(t_data *utils, int y, int x)
{
	if (utils->map[y][x] == '0' || utils->map[y][x] == 'E'
		|| utils->map[y][x] == 'P' || utils->map[y][x] == 'C'
		|| utils->map[y][x] == '1')
		mlx_put_image_to_window(utils->mlx, utils->gamewin, \
			utils->floorimg, x * 50, y * 50);
	if (utils->map[y][x] == '1')
		mlx_put_image_to_window(utils->mlx, utils->gamewin, \
			utils->wallimg, x * 50, y * 50);
	if (utils->map[y][x] == 'E')
		mlx_put_image_to_window(utils->mlx, utils->gamewin, \
			utils->doorimg, x * 50, y * 50);
	if (utils->map[y][x] == 'C')
		mlx_put_image_to_window(utils->mlx, utils->gamewin, \
			utils->coinimg, x * 50, y * 50);
	if (utils->map[y][x] == 'P')
		mlx_put_image_to_window(utils->mlx, utils->gamewin, \
				utils->marioimg, x * 50, y * 50);
}
