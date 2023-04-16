/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahdiou <amahdiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:35:12 by amahdiou          #+#    #+#             */
/*   Updated: 2023/04/09 22:35:13 by amahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	count(int *y, int *x, int fd)
{
	char	*str;

	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (str != NULL)
		(*x) = ft_strlen(str);
		(*y)++;
		free(str);
	}
	close (fd);
}

void	wallcheck(t_data *utils)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < utils->y)
	{
		if (utils->map[j][0] != '1')
		{
			ft_printf("Error");
			exit(1);
		}
		if (utils->map[j][utils->x - 1] != '1')
		{
			ft_printf("Error");
			exit(1);
		}
		while (i < utils->x)
		{
			hilper(utils);
			i++;
		}
		i = 0;
		j++;
	}
}

void	checkfile(char *name)
{
	int	i;

	i = ft_strlen(name) - 1;
	if (name[i] != 'r')
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (name[i - 1] != 'e')
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (name[i - 2] != 'b')
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	search(t_data *utils, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != y)
	{
		while (j != x)
		{
			if (utils->map[i][j] != 'P' && utils->map[i][j] != 'E'\
			&& utils->map[i][j] != 'C' && utils->map[i][j] != '1'\
			&& utils->map[i][j] != '0')
			{
				exit(1);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	countchar(t_data *utils, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	utils->p = 0;
	utils->e = 0;
	utils->c = 0;
	while (i != y)
	{
		while (j != x)
		{
			if (utils->map[i][j] == 'P')
				utils->p++;
			if (utils->map[i][j] == 'E')
				utils->e++;
			if (utils->map[i][j] == 'C')
				utils->c++;
			j++;
		}
		i++;
		j = 0;
	}
	if (utils->p == 0 || utils->e == 0 || utils->c == 0)
		exit(1);
}
