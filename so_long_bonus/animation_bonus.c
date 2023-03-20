/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 00:16:49 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/20 05:01:16 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <math.h>

void	ft_enemy_movements(t_vars *v)
{
	if (v->frame++ > 20)
		v->frame = 0;
	if (v->frame == 10)
	{
		v->i = 0;
		while (v->map[v->i])
		{
			v->j = 0;
			while (v->map[v->i][v->j])
			{
				if (v->map[v->i][v->j] == 'L')
				{
					if (v->map[v->i][v->j - 1] == '0' && rand() % 2 == 0)
					{
						v->enemy = 1;
						v->map[v->i][v->j] = '0';
						v->map[v->i][v->j - 1] = 'L';
					}
					else if (v->map[v->i][v->j + 1] == '0' && rand() % 2 == 0)
					{
						v->enemy = 3;
						v->map[v->i][v->j] = '0';
						v->map[v->i][v->j + 1] = 'L';
					}
					else if (v->map[v->i + 1][v->j] == '0' && rand() % 2 == 0)
					{
						v->enemy = 2;
						v->map[v->i][v->j] = '0';
						v->map[v->i + 1][v->j] = 'L';
					}
					else if ((rand() % 2 == 0 || v->map[v->i][v->j - 1] == '1'
								|| v->map[v->i][v->j - 1] == 'C') && v->map[v->i
							- 1][v->j] == '0')
					{
						v->enemy = 5;
						v->map[v->i][v->j] = '0';
						v->map[v->i - 1][v->j] = 'L';
					}
					else if (v->map[v->i][v->j - 1] == 'P')
						ft_close_window(v, 2);
				}
				v->j++;
			}
			v->i++;
		}
	}
}
