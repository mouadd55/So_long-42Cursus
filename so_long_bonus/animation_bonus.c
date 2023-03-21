/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 00:16:49 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/20 22:11:20 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_enemy_images(t_vars *v)
{
	if (v->enemy == 1)
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->el, v->x, v->y);
	else if (v->enemy == 5)
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->eu, v->x, v->y);
	else if (v->enemy == 3)
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->er, v->x, v->y);
	else if (v->enemy == 2)
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->ed, v->x, v->y);
}

void	ft_ft_enemy_movements_util2(t_vars *v, int i, int j)
{
	if (i == 0 && j == -1)
	{
		v->enemy = 1;
		v->map[v->i][v->j] = '0';
		v->map[v->i][v->j - 1] = 'Z';
	}
	else if (i == 0 && j == 1)
	{
		v->enemy = 3;
		v->map[v->i][v->j] = '0';
		v->map[v->i][v->j + 1] = 'Z';
	}
	else if (i == 1 && j == 0)
	{
		v->enemy = 2;
		v->map[v->i][v->j] = '0';
		v->map[v->i + 1][v->j] = 'Z';
	}
	else if (i == -1 && j == 0)
	{
		v->enemy = 5;
		v->map[v->i][v->j] = '0';
		v->map[v->i - 1][v->j] = 'Z';
	}
}

void	ft_ft_enemy_movements_util1(t_vars *v)
{
	if (v->map[v->i][v->j - 1] == '0' && rand() % 2 == 0)
		ft_ft_enemy_movements_util2(v, 0, -1);
	else if (v->map[v->i][v->j + 1] == '0' && rand() % 2 == 0)
		ft_ft_enemy_movements_util2(v, 0, 1);
	else if (v->map[v->i + 1][v->j] == '0' && rand() % 2 == 0)
		ft_ft_enemy_movements_util2(v, 1, 0);
	else if ((v->map[v->i][v->j - 1] == '1' || v->map[v->i][v->j - 1] == 'C')
			&& v->map[v->i - 1][v->j] == '0' && rand() % 2 == 0)
		ft_ft_enemy_movements_util2(v, -1, 0);
	else if (v->map[v->i][v->j - 1] == 'P')
		ft_close_window(v, 2);
}

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
				if (v->map[v->i][v->j] == 'Z')
					ft_ft_enemy_movements_util1(v);
				v->j++;
			}
			v->i++;
		}
	}
}
