/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 07:17:23 by mel-gand          #+#    #+#             */
/*   Updated: 2023/03/31 23:26:05 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_file(char *file_ext)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".ber";
	i = 0;
	j = 0;
	while (file_ext[i] != '.')
		i++;
	while (ext[j])
	{
		if (file_ext[i] != ext[j])
		{
			write(1, "Invalid File \u274C\n", 17);
			exit(1);
		}
		i++;
		j++;
	}
	write(1, "Valid File \u2705\n", 16);
}
