/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:27:09 by mel-gand          #+#    #+#             */
/*   Updated: 2023/03/31 23:10:15 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	map_len(char *map)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(map, O_RDWR | O_CREAT);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	load_map(char *argv, char **map, t_check3 *check)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv, O_RDWR | O_CREAT);
	if (fd == -1)
	{
		perror("Error opening file");
		free_map(map);
		exit(1);
	}
	while (1)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	check_map1(map, check);
	close(fd);
}

void	find_player(t_check3 *pos, t_mlx *p)
{
	pos->i = 0;
	pos->j = 0;
	while (p->map[pos->i])
	{
		pos->j = 0;
		while (p->map[pos->i][pos->j])
		{
			if (p->map[pos->i][pos->j] == 'P')
				return ;
			pos->j++;
		}
		pos->i++;
	}
}

int	callback(int keycode, t_mlx *p)
{
	t_check3	*pos;

	pos = p->ptr;
	find_player(pos, p);
	if (keycode == 53)
	{
		free_map(p->map);
		mlx_destroy_window(p->mlx_ptr, p->win);
		destroy_img(p);
		exit(0);
	}
	if (keycode == 0)
		mv_left(p, pos);
	else if (keycode == 2)
		mv_right(p, pos);
	else if (keycode == 1)
		mv_down(p, pos);
	else if (keycode == 13)
		mv_up(p, pos);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx		p;
	t_check3	dimm;

	initialize2(&dimm);
	if (argc == 2)
	{
		check_file(argv[1]);
		p.map = malloc(sizeof(char *) * (map_len(argv[1]) + 1));
		if (!p.map)
			return (0);
		load_map(argv[1], p.map, &dimm);
		p.mlx_ptr = mlx_init();
		p.ptr = &dimm;
		p.win = mlx_new_window(p.mlx_ptr, (dimm.len - 1) * 63, (dimm.width + 1)
				* 63, "so_long");
		xpm_to_img(p.map, &p);
		img_to_win(p.map, &p);
		dimm.coin_cnt = coin_count(p.map);
		mlx_key_hook(p.win, &callback, &p);
		mlx_loop(p.mlx_ptr);
	}
}
