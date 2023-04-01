/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:38:52 by mel-gand          #+#    #+#             */
/*   Updated: 2023/03/31 23:23:05 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	initialize(t_check2 *ugh)
{
	ugh->player = 0;
	ugh->coin = 0;
	ugh->exit = 0;
	ugh->i = 0;
	ugh->j = 0;
}

void	initialize2(t_check3 *ugh)
{
	ugh->i = 0;
	ugh->j = 0;
	ugh->len = 0;
	ugh->width = 0;
	ugh->coin_cnt = 0;
	ugh->exit_cnt = 0;
}
