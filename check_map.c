/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 03:01:51 by mel-gand          #+#    #+#             */
/*   Updated: 2023/03/31 23:25:55 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_walls(char **map, t_check3 *check)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && j < check->len - 1)
		{
			if ((map[0][j] != '1' && map[0][j] != '\n') || map[i][0] != '1'
				|| map[i][check->len - 2] != '1' || map[check->width][j] != '1')
			{
				write(1, "Invalid Map \u274C", 16);
				free_map(map);
				exit(1);
			}
			j++;
		}
		i++;
	}
	check_path(map, check);
}

void	check_map_size(char **map, t_check3 *check)
{
	while (map[0][check->len])
		check->len++;
	map++;
	while (map[check->width])
		check->width++;
	while (map[check->i])
	{
		check->j = 0;
		while (map[check->i][check->j])
			check->j++;
		if (check->width - 1 == check->i)
			check->j++;
		if (check->len != check->j)
		{
			write(1, "Invalid Map \u274C", 16);
			free_map(map);
			exit(1);
		}
		check->i++;
	}
	check->i = 0;
	check->j = 0;
	check_map_walls(--map, check);
}

void	check_map2(char **map, t_check3 *check)
{
	t_check2	chek;

	initialize(&chek);
	while (map[chek.i])
	{
		chek.j = 0;
		while (map[chek.i][chek.j])
		{
			if (map[chek.i][chek.j] == 'P')
				chek.player++;
			else if (map[chek.i][chek.j] == 'E')
				chek.exit++;
			else if (map[chek.i][chek.j] == 'C')
				chek.coin++;
			chek.j++;
		}
		chek.i++;
	}
	if (chek.coin < 1 || chek.exit != 1 || chek.player != 1)
	{
		write(1, "Invalid Map \u274C", 16);
		free_map(map);
		exit(1);
	}
	check_map_size(map, check);
}

void	check_map1(char **map, t_check3 *check)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != '\n')
			{
				write(1, "Invalid Map \u274C", 16);
				free_map(map);
				exit(1);
			}
			j++;
		}
		i++;
	}
	check_map2(map, check);
	write(1, "Valid Map \u2705\n", 15);
}
