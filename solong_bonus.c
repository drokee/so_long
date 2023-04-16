/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahdiou <amahdiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 03:36:00 by amahdiou          #+#    #+#             */
/*   Updated: 2023/04/08 03:36:01 by amahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "solong_bonus.h"

void	mapreader(t_data *utils, int fd)
{
	char	*container;
	char	*container2;
	int		i;

	i = 0;
	container2 = ft_calloc(1, 1);
	container = get_next_line(fd);
	while (container)
	{
		container2 = box(container2, container);
		free(container);
		container = get_next_line(fd);
	}
	utils->map = ft_split(container2, '\n');
	utils->mapc = ft_split(container2, '\n');
	free(container2);
}

int	main(int ac, char **av)
{
	int		fd;
	int		fd1;
	t_data	utils;

	if (ac == 1)
	{
		exit(1);
	}
	fd1 = open(av[1], O_RDONLY);
	mapreader(&utils, fd1);
	checkfile(av[1]);
	fd = open(av[1], O_RDONLY);
	count(&utils.y, &utils.x, fd);
	search(&utils, utils.y, utils.x);
	playerpos(&utils);
	countchar(&utils, utils.y, utils.x);
	wallcheck(&utils);
	pathchecker(&utils, utils.y, utils.x);
	imgmanager(&utils);
}
