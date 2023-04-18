/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataerror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahdiou <amahdiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:15:19 by amahdiou          #+#    #+#             */
/*   Updated: 2023/04/18 13:15:21 by amahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long.h"

void	errorfile(t_data *utils)
{
	utils->marioimg = mlx_xpm_file_to_image(utils->mlx, \
	utils->mario, &utils->width, &utils->height);
	if (!utils->marioimg)
	{
		ft_printf("Lost files mario!\n");
		exit(1);
	}
	utils->coinimg = mlx_xpm_file_to_image(utils->mlx, utils->coin, \
	&utils->width, &utils->height);
	if (!utils->coinimg)
	{
		ft_printf("Lost files coin!\n");
		des_coin(utils);
		exit(1);
	}
	utils->wallimg = mlx_xpm_file_to_image(utils->mlx, utils->wall, \
	&utils->width, &utils->height);
	if (!utils->wallimg)
	{
		ft_printf("Lost files wall!\n");
		des_wall(utils);
		exit(1);
	}
	second_erfile(utils);
}

void	second_erfile(t_data *utils)
{
	utils->floorimg = mlx_xpm_file_to_image(utils->mlx, utils->floor, \
	&utils->width, &utils->height);
	if (!utils->floorimg)
	{
		ft_printf("Lost files floor!\n");
		des_floor(utils);
		exit(1);
	}
	utils->doorimg = mlx_xpm_file_to_image(utils->mlx, utils->door, \
	&utils->width, &utils->height);
	if (!utils->doorimg)
	{
		ft_printf("Lost files door!\n");
		des_door(utils);
		exit(1);
	}
}
