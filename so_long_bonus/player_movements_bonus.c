/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:50:16 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/18 05:29:23 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_swap_characters(t_vars *v, int i, int j)
{
	if (v->map[v->i + i][v->j + j] == '0')
	{
		v->map[v->i][v->j] = '0';
		v->map[v->i + i][v->j + j] = 'P';
		v->moves++;
	}
	else if (v->map[v->i + i][v->j + j] == 'C')
	{
		v->map[v->i][v->j] = '0';
		v->map[v->i + i][v->j + j] = 'P';
		v->moves++;
		v->count++;
	}
	else if (v->map[v->i + i][v->j + j] == 'E' && v->count == v->c)
		ft_close_window(v, 1);
	else if (v->map[v->i + i][v->j + j] == 'Z')
		ft_close_window(v, 2);
}

int	ft_move_player(t_vars *v, int keycode, int i, int j)
{
	v->i = 0;
	v->keycode = keycode;
	while (v->map[v->i])
	{
		v->j = 0;
		while (v->map[v->i][v->j])
		{
			if (v->map[v->i][v->j] == 'P')
			{
				ft_swap_characters(v, i, j);
				return (0);
			}
			v->j++;
		}
		v->i++;
	}
	return (0);
}

int	key_press(int keycode, t_vars *v)
{
	int	moves;

	moves = v->moves;
	if (keycode == 53)
		ft_close_window(v, 0);
	else if (keycode == 13 || keycode == 126)
		ft_move_player(v, keycode, -1, 0);
	else if (keycode == 1 || keycode == 125)
		ft_move_player(v, keycode, 1, 0);
	else if (keycode == 0 || keycode == 123)
		ft_move_player(v, keycode, 0, -1);
	else if (keycode == 2 || keycode == 124)
		ft_move_player(v, keycode, 0, 1);
	mlx_clear_window(v->mlx, v->mlx_win);
	ft_fill_window(v);
	return (0);
}
