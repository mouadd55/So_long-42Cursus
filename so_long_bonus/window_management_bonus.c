/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:56:07 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/21 18:05:05 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close_window(t_vars *v, int i)
{
	mlx_destroy_window(v->mlx, v->mlx_win);
	ft_free_arr(v->map);
	ft_free_arr(v->tmp);
	if (i == 1)
		ft_putstr("            \e[1m\e[43m\e[30mYou Win!!\e[0m\n");
	else if (i == 2)
		ft_putstr("        \e[1m\e[43m\e[30m GAME OVER: You Lose! \e[0m\n");
	exit(0);
}

void	ft_initialize_pointers(t_vars *v)
{
	int	x;
	int	y;

	v->bg = mlx_xpm_file_to_image(v->mlx, "./images/bg.xpm", &x, &y);
	v->pu = mlx_xpm_file_to_image(v->mlx, "./images/pu.xpm", &x, &y);
	v->pd = mlx_xpm_file_to_image(v->mlx, "./images/pd.xpm", &x, &y);
	v->pl = mlx_xpm_file_to_image(v->mlx, "./images/pl.xpm", &x, &y);
	v->pr = mlx_xpm_file_to_image(v->mlx, "./images/pr.xpm", &x, &y);
	v->cl = mlx_xpm_file_to_image(v->mlx, "./images/cl.xpm", &x, &y);
	v->el = mlx_xpm_file_to_image(v->mlx, "./images/el.xpm", &x, &y);
	v->ed = mlx_xpm_file_to_image(v->mlx, "./images/ed.xpm", &x, &y);
	v->er = mlx_xpm_file_to_image(v->mlx, "./images/er.xpm", &x, &y);
	v->eu = mlx_xpm_file_to_image(v->mlx, "./images/eu.xpm", &x, &y);
	v->wl1 = mlx_xpm_file_to_image(v->mlx, "./images/wl1.xpm", &x, &y);
	v->wl2 = mlx_xpm_file_to_image(v->mlx, "./images/wl2.xpm", &x, &y);
	v->ex1 = mlx_xpm_file_to_image(v->mlx, "./images/ex1.xpm", &x, &y);
	v->ex2 = mlx_xpm_file_to_image(v->mlx, "./images/ex2.xpm", &x, &y);
	if (!v->bg || !v->pu || !v->pd || !v->pl || !v->pr || !v->cl || !v->wl1
		|| !v->wl2 || !v->ex1 || !v->ex2 || !v->el || !v->ed || !v->er
		|| !v->eu)
		exit (1);
}

void	ft_fill_util(char c, t_vars *v)
{
	if (c == '1' && (v->j == 0 || v->i == 0 || v->i == v->lines - 1
			|| v->j == v->length_of_line - 1))
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->wl1, v->x, v->y);
	else if (c == '1')
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->wl2, v->x, v->y);
	else if (c == 'P' && (v->keycode == 13 || v->keycode == 126))
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->pu, v->x, v->y);
	else if (c == 'P' && (v->keycode == 1 || v->keycode == 125))
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->pd, v->x, v->y);
	else if (c == 'P' && (v->keycode == 0 || v->keycode == 123))
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->pl, v->x, v->y);
	else if (c == 'P' && (v->keycode == 2 || v->keycode == 124))
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->pr, v->x, v->y);
	else if (c == 'C')
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->cl, v->x, v->y);
	else if (c == 'Z')
		ft_put_enemy_images(v);
	else if (c == 'E' && v->count < v->c)
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->ex1, v->x, v->y);
	else if (c == 'E' && v->count == v->c)
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->ex2, v->x, v->y);
}

int	ft_fill_window(t_vars *v)
{
	v->y = 0;
	v->i = 0;
	while (v->map[v->i])
	{
		v->j = 0;
		v->x = 0;
		while (v->map[v->i][v->j])
		{
			mlx_put_image_to_window(v->mlx, v->mlx_win, v->bg, v->x, v->y);
			ft_fill_util(v->map[v->i][v->j], v);
			v->j++;
			v->x += 50;
		}
		v->i++;
		v->y += 50;
	}
	ft_enemy_movements(v);
	ft_print_moves_in_window(v);
	return (0);
}

void	ft_open_window(t_vars *v)
{
	v->mlx = mlx_init();
	if (!v->mlx)
		exit(1);
	ft_initialize_pointers(v);
	if (v->lines > 29 || v->length_of_line > 57)
		exit(1);
	v->mlx_win = mlx_new_window(v->mlx, (v->length_of_line * 50), ((v->lines
					+ 1) * 50), "So Long");
	if (!v->mlx_win)
		exit(1);
	v->count = 0;
	v->moves = 0;
	v->frame = 0;
	v->keycode = 13;
	ft_fill_window(v);
}
