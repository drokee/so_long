/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desimg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahdiou <amahdiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:04:58 by amahdiou          #+#    #+#             */
/*   Updated: 2023/04/18 13:05:00 by amahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long.h"

void	des_mario(t_data *utils)
{
	mlx_destroy_image(utils->mlx, utils->marioimg);
	exit(1);
}

void	des_coin(t_data *utils)
{
	des_mario(utils);
	mlx_destroy_image(utils->mlx, utils->coinimg);
	exit(1);
}

void	des_wall(t_data *utils)
{
	des_coin(utils);
	mlx_destroy_image(utils->mlx, utils->wallimg);
	exit(1);
}

void	des_floor(t_data *utils)
{
	des_wall(utils);
	mlx_destroy_image(utils->mlx, utils->floorimg);
	exit(1);
}

void	des_door(t_data *utils)
{
	des_floor(utils);
	mlx_destroy_image(utils->mlx, utils->doorimg);
	exit(1);
}
