/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hilper25line_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahdiou <amahdiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 04:33:34 by amahdiou          #+#    #+#             */
/*   Updated: 2023/04/17 04:33:36 by amahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"solong_bonus.h"

void	free_doublearr(char **tab, t_data *utils)
{
	int	i;

	(void)utils;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	hilper2(t_data *utils, int i)
{
	if (utils->map[0][i] != '1')
	{
		ft_printf("Error\n");
		free_doublearr(utils->map, utils);
		exit (1);
	}
	if (utils->map[utils->y - 1][i] != '1')
	{
		ft_printf("Error\n");
		free_doublearr(utils->map, utils);
		exit (1);
	}
}
