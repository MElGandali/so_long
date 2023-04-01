/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:22:50 by mel-gand          #+#    #+#             */
/*   Updated: 2023/03/31 22:48:05 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct checkmap3
{
	int			i;
	int			j;
	int			len;
	int			width;
	int			coin_cnt;
	int			exit_cnt;
}				t_check3;

typedef struct minilibx
{
	void		*mlx_ptr;
	void		*win;
	void		*img[4];
	int			width;
	int			height;
	int			coin_cnt;
	int			mvs;
	char		**map;
	t_check3	*ptr;
}				t_mlx;

typedef struct checkmap2
{
	int			player;
	int			coin;
	int			exit;
	int			i;
	int			j;
}				t_check2;

void			check_file(char *file_ext);
void			check_map1(char **map, t_check3 *check);
void			check_map2(char **map, t_check3 *check);
void			check_map_size(char **map, t_check3 *check);
void			check_map_walls(char **map, t_check3 *check);
void			check_path(char **map, t_check3 *size);
int				coin_count(char **map);
void			xpm_to_img(char **map, t_mlx *p);
void			img_to_win(char **map, t_mlx *p);
void			mv_left(t_mlx *p, t_check3 *pos);
void			mv_right(t_mlx *p, t_check3 *pos);
void			mv_up(t_mlx *p, t_check3 *pos);
void			mv_down(t_mlx *p, t_check3 *pos);
void			free_map(char **map);
void			destroy_img(t_mlx *p);
void			ft_putchar(int c);
void			ft_putnbr(int nbr);
void			initialize(t_check2 *ugh);
void			initialize2(t_check3 *ugh);

#endif
