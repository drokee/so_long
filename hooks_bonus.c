/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahdiou <amahdiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:28:22 by amahdiou          #+#    #+#             */
/*   Updated: 2023/04/14 02:28:23 by amahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"solong_bonus.h"

int	movements(int key, t_data *utils)
{
	char	here;
	t_pos	playerloc;
	t_pos	modifier;

	here = '\0';
	playerloc = playerpos(utils);
	if (key == 13)
		up(utils, &playerloc, &modifier, here);
	if (key == 1)
		down(utils, &playerloc, &modifier, here);
	if (key == 2)
		right(utils, &playerloc, &modifier, here);
	if (key == 0)
		left(utils, &playerloc, &modifier, here);
	if (key == 53)
	{
		free_doublearr(utils->map, utils);
		destroyimg(utils);
		exit(0);
	}
	return (0);
}

void	up(t_data *utils, t_pos *playerloc, t_pos *modifier, char here)
{
	modifier->x = playerloc->x;
	modifier->y = playerloc->y -1;
	here = charposition(utils, modifier);
	if (here == '0')
	{
		charchanger(utils, playerloc, '0');
		charchanger(utils, modifier, 'P');
		putdesign(utils);
	}
	if (here == 'C')
	{
		utils->c--;
		charchanger(utils, playerloc, '0');
		charchanger(utils, modifier, 'P');
		putdesign(utils);
	}
	if (here != '1')
		movescounter(utils);
	if (here == 'E' && utils->c == 0)
	{
		ft_printf("WA RAK RB7TI\n");
		free_doublearr(utils->map, utils);
		destroyimg(utils);
		exit(0);
	}
}

void	down(t_data *utils, t_pos *playerloc, t_pos *modifier, char here)
{
	modifier->x = playerloc->x;
	modifier->y = playerloc->y + 1;
	here = charposition(utils, modifier);
	if (here == '0')
	{
		charchanger(utils, playerloc, '0');
		charchanger(utils, modifier, 'P');
		putdesign(utils);
	}
	if (here == 'C')
	{
		utils->c--;
		charchanger(utils, playerloc, '0');
		charchanger(utils, modifier, 'P');
		putdesign(utils);
	}
	if (here != '1')
		movescounter(utils);
	if (here == 'E' && utils->c == 0)
	{
		ft_printf("WA RAK RB7TI\n");
		free_doublearr(utils->map, utils);
		destroyimg(utils);
		exit(0);
	}
}

void	left(t_data *utils, t_pos *playerloc, t_pos *modifier, char here)
{
	modifier->x = playerloc->x - 1;
	modifier->y = playerloc->y;
	here = charposition(utils, modifier);
	if (here == '0')
	{
		charchanger(utils, playerloc, '0');
		charchanger(utils, modifier, 'P');
		putdesign(utils);
	}
	if (here == 'C')
	{
		utils->c--;
		charchanger(utils, playerloc, '0');
		charchanger(utils, modifier, 'P');
		putdesign(utils);
	}
	if (here != '1')
		movescounter(utils);
	if (here == 'E' && utils->c == 0)
	{
		ft_printf("WA RAK RB7TI\n");
		free_doublearr(utils->map, utils);
		destroyimg(utils);
		exit(0);
	}
}

void	right(t_data *utils, t_pos *playerloc, t_pos *modifier, char here)
{
	modifier->x = playerloc->x + 1;
	modifier->y = playerloc->y;
	here = charposition(utils, modifier);
	if (here == '0')
	{
		charchanger(utils, playerloc, '0');
		charchanger(utils, modifier, 'P');
		putdesign(utils);
	}
	if (here == 'C')
	{
		utils->c--;
		charchanger(utils, playerloc, '0');
		charchanger(utils, modifier, 'P');
		putdesign(utils);
	}
	if (here != '1')
		movescounter(utils);
	if (here == 'E' && utils->c == 0)
	{
		ft_printf("WA RAK RB7TI\n");
		free_doublearr(utils->map, utils);
		destroyimg(utils);
		exit(0);
	}
}
