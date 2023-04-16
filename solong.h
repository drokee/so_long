/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahdiou <amahdiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 04:15:25 by amahdiou          #+#    #+#             */
/*   Updated: 2023/04/08 04:15:27 by amahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "./getnextline/get_next_line.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_data
{
	void	*l3arbiimg;
	void	*wallimg;
	void	*floorimg;
	void	*coinimg;
	void	*doorimg;
	char	**map;
	char	**mapc;
	int		x;
	int		y;
	int		p;
	int		e;
	int		c;
	int		width;
	int		height;
	void	*mlx;
	void	*gamewin;
	char	*l3arbi;
	char	*wall;
	char	*floor;
	char	*coin;
	char	*door;
	int		moves;
}t_data;
typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

void	count(int *y, int *x, int fd);
void	search(t_data *utils, int y, int x);
void	mapreader(t_data *utils, int fd);
void	wallcheck(t_data *utils);
void	checkfile(char *name);
void	countchar(t_data *utils, int y, int x);
void	pathchecker(t_data *utils, int y, int x);
void	player(t_data *utils, int i, int j);
void	coincheck(t_data *utils, int y, int x);
void	pathvalid(t_data *utils, int y, int x);
void	imgmanager(t_data *utils);
void	putdesign(t_data *utils);
t_pos	playerpos(t_data *utils);
char	charposition(t_data *utils, t_pos *thisone);
int		movements(int key, t_data *utils);
char	charposition(t_data *utils, t_pos *thisone);
void	charchanger(t_data *utils, t_pos *whichone, char thatone);
void	up(t_data *utils, t_pos *playerloc, t_pos *modifier, char here);
void	down(t_data *utils, t_pos *playerloc, t_pos *modifier, char here);
void	left(t_data *utils, t_pos *playerloc, t_pos *modifier, char here);
void	right(t_data *utils, t_pos *playerloc, t_pos *modifier, char here);
int		quit(void);
void	movescounter(t_data *utils);
void	checknl(char *str);
void	hilper(t_data *utils);
void	dupchar(t_data *utils);
void	putdesign2(t_data *utils, int y, int x);

#endif