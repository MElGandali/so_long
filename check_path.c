/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 03:06:58 by mel-gand          #+#    #+#             */
/*   Updated: 2023/03/31 23:25:02 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	coin_count(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	**dup_map(char **map, t_check3 *size)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	new = malloc(sizeof(char *) * size->width + 1);
	if (!new)
		return (NULL);
	while (i < size->width)
	{
		j = 0;
		new[i] = malloc(size->len);
		if (!new[i])
			return (0);
		while (j < size->len)
		{
			new[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	new[size->width] = NULL;
	return (new);
}

void	flood_fill(char **new, int i, int j, t_check3 *size)
{
	if (i < 0 || j < 0 || i >= size->width || j >= size->len - 1
		|| new[i][j] == 'V' || new[i][j] == '1')
		return ;
	if (new[i][j] == 'C')
		size->coin_cnt--;
	if (size->coin_cnt == 0 && new[i][j] == 'E')
		size->exit_cnt++;
	new[i][j] = 'V';
	flood_fill(new, i, j + 1, size);
	flood_fill(new, i, j - 1, size);
	flood_fill(new, i - 1, j, size);
	flood_fill(new, i + 1, j, size);
}

void	check_path_utils(char **map, char **new, t_check3 *size)
{
	if (size->exit_cnt == 1)
	{
		write(1, "Valid Path \u2705\n", 16);
		free_map(new);
	}
	else
	{
		write(1, "Invalid Path \u274C", 19);
		free_map(map);
		free_map(new);
		exit(1);
	}
}

void	check_path(char **map, t_check3 *size)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	size->coin_cnt = coin_count(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				new = dup_map(map, size);
				flood_fill(new, i, j, size);
			}
			j++;
		}
		i++;
	}
	check_path_utils(map, new, size);
}
