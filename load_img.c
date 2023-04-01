/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:04:22 by mel-gand          #+#    #+#             */
/*   Updated: 2023/03/31 23:22:30 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_to_win(char **map, t_mlx *p)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				mlx_put_image_to_window(p->mlx_ptr, p->win, p->img[0], j * 63, i
					* 63);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(p->mlx_ptr, p->win, p->img[1], j * 63, i
					* 63);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(p->mlx_ptr, p->win, p->img[2], j * 63, i
					* 63);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(p->mlx_ptr, p->win, p->img[3], j * 63, i
					* 63);
			j++;
		}
		i++;
	}
}

void	xpm_to_img_utils(char **map, int i, int j, t_mlx *p)
{
	if (map[i][j] == 'C')
		p->img[0] = mlx_xpm_file_to_image(p->mlx_ptr,
				"textures/coin.xpm",
				&p->width, &p->height);
	else if (map[i][j] == 'P')
		p->img[1] = mlx_xpm_file_to_image(p->mlx_ptr,
				"textures/player.xpm",
				&p->width, &p->height);
	else if (map[i][j] == '1')
		p->img[2] = mlx_xpm_file_to_image(p->mlx_ptr,
				"textures/wall.xpm",
				&p->width, &p->height);
	else if (map[i][j] == 'E')
		p->img[3] = mlx_xpm_file_to_image(p->mlx_ptr,
				"textures/exit.xpm",
				&p->width, &p->height);
}

void	xpm_to_img(char **map, t_mlx *p)
{
	int	i;
	int	j;

	p->width = 60;
	p->height = 60;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			xpm_to_img_utils(map, i, j, p);
			j++;
		}
		i++;
	}
}
