/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:43:15 by mel-gand          #+#    #+#             */
/*   Updated: 2023/03/31 22:31:03 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mv_left(t_mlx *p, t_check3 *pos)
{
	if (p->map[pos->i][pos->j] == 'P' && p->map[pos->i][pos->j - 1] != '1'
		&& p->map[pos->i][pos->j - 1] != 'E' && pos->j > 0)
	{
		if (p->map[pos->i][pos->j - 1] == 'C')
			p->coin_cnt++;
		p->map[pos->i][pos->j] = '0';
		p->map[pos->i][pos->j - 1] = 'P';
		p->mvs++;
	}
	else if (p->coin_cnt == pos->coin_cnt && p->map[pos->i][pos->j - 1] == 'E')
	{
		p->map[pos->i][pos->j] = '0';
		p->map[pos->i][pos->j - 1] = 'P';
		p->mvs++;
		free_map(p->map);
		mlx_destroy_window(p->mlx_ptr, p->win);
		destroy_img(p);
		exit(0);
	}
	ft_putnbr(p->mvs);
	write(1, "\n", 1);
	mlx_clear_window(p->mlx_ptr, p->win);
	img_to_win(p->map, p);
}

void	mv_right(t_mlx *p, t_check3 *pos)
{
	if (p->map[pos->i][pos->j] == 'P' && p->map[pos->i][pos->j + 1] != '1'
		&& p->map[pos->i][pos->j + 1] != 'E')
	{
		if (p->map[pos->i][pos->j + 1] == 'C')
			p->coin_cnt++;
		p->map[pos->i][pos->j] = '0';
		p->map[pos->i][pos->j + 1] = 'P';
		p->mvs++;
	}
	else if (p->coin_cnt == pos->coin_cnt && p->map[pos->i][pos->j + 1] == 'E')
	{
		p->map[pos->i][pos->j] = '0';
		p->map[pos->i][pos->j + 1] = 'P';
		p->mvs++;
		free_map(p->map);
		mlx_destroy_window(p->mlx_ptr, p->win);
		destroy_img(p);
		exit(0);
	}
	ft_putnbr(p->mvs);
	write(1, "\n", 1);
	mlx_clear_window(p->mlx_ptr, p->win);
	img_to_win(p->map, p);
}

void	mv_up(t_mlx *p, t_check3 *pos)
{
	if (p->map[pos->i - 1][pos->j] != '1' && p->map[pos->i - 1][pos->j] != 'E'
		&& p->map[pos->i])
	{
		if (p->map[pos->i - 1][pos->j] == 'C')
			p->coin_cnt++;
		p->map[pos->i][pos->j] = '0';
		p->map[pos->i - 1][pos->j] = 'P';
		p->mvs++;
	}
	else if (p->coin_cnt == pos->coin_cnt && p->map[pos->i - 1][pos->j] == 'E')
	{
		p->map[pos->i][pos->j] = '0';
		p->map[pos->i - 1][pos->j] = 'P';
		p->mvs++;
		free_map(p->map);
		mlx_destroy_window(p->mlx_ptr, p->win);
		destroy_img(p);
		exit(0);
	}
	ft_putnbr(p->mvs);
	write(1, "\n", 1);
	mlx_clear_window(p->mlx_ptr, p->win);
	img_to_win(p->map, p);
}

void	mv_down(t_mlx *p, t_check3 *pos)
{
	if (p->map[pos->i + 1][pos->j] != '1' && p->map[pos->i + 1][pos->j] != 'E'
		&& p->map[pos->i])
	{
		if (p->map[pos->i + 1][pos->j] == 'C')
			p->coin_cnt++;
		p->map[pos->i][pos->j] = '0';
		p->map[pos->i + 1][pos->j] = 'P';
		p->mvs++;
	}
	else if (p->coin_cnt == pos->coin_cnt && p->map[pos->i + 1][pos->j] == 'E')
	{
		p->map[pos->i][pos->j] = '0';
		p->map[pos->i + 1][pos->j] = 'P';
		p->mvs++;
		free_map(p->map);
		mlx_destroy_window(p->mlx_ptr, p->win);
		destroy_img(p);
		exit(0);
	}
	ft_putnbr(p->mvs);
	write(1, "\n", 1);
	mlx_clear_window(p->mlx_ptr, p->win);
	img_to_win(p->map, p);
}
