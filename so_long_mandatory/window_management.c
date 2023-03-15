/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:58:11 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/15 04:42:07 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close_window(t_vars *v)
{
	mlx_destroy_window(v->mlx, v->mlx_win);
	exit(0);
}

void	ft_initialize_pointers(t_vars *v)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	v->bg = mlx_xpm_file_to_image(v->mlx, "./images/bg.xpm", &x, &y);
	v->pu = mlx_xpm_file_to_image(v->mlx, "./images/pu.xpm", &x, &y);
	v->pd = mlx_xpm_file_to_image(v->mlx, "./images/pd.xpm", &x, &y);
	v->pl = mlx_xpm_file_to_image(v->mlx, "./images/pl.xpm", &x, &y);
	v->pr = mlx_xpm_file_to_image(v->mlx, "./images/pr.xpm", &x, &y);
	v->wl1 = mlx_xpm_file_to_image(v->mlx, "./images/wl1.xpm", &x, &y);
	v->wl2 = mlx_xpm_file_to_image(v->mlx, "./images/wl2.xpm", &x, &y);
	v->cl = mlx_xpm_file_to_image(v->mlx, "./images/cl.xpm", &x, &y);
	v->ex1 = mlx_xpm_file_to_image(v->mlx, "./images/ex1.xpm", &x, &y);
	v->ex2 = mlx_xpm_file_to_image(v->mlx, "./images/ex2.xpm", &x, &y);
	if (!v->bg || !v->pu || !v->pd || !v->pl || !v->pr || !v->wl1 || !v->wl2
		|| !v->cl || !v->ex1 || !v->ex2)
		ft_error(0);
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
	else if (c == 'E' && v->count < v->c)
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->ex1, v->x, v->y);
	else if (c == 'E' && v->count == v->c)
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->ex2, v->x, v->y);
}

void	ft_fill_window(t_vars *v)
{
	v->y = 0;
	v->i = 0;
	while (v->map[v->i])
	{
		v->j = 0;
		v->x = 0;
		while (v->map[v->i][v->j])
		{
			mlx_put_image_to_window(v->mlx, v->mlx_win, v->bg, v->x,
				v->y);
			ft_fill_util(v->map[v->i][v->j], v);
			v->j++;
			v->x += 50;
		}
		v->i++;
		v->y += 50;
	}
}

int	ft_open_window(t_vars *v)
{
	v->mlx = mlx_init();
	if (!v->mlx)
		return (1);
	if (v->lines > 29 || v->length_of_line > 57)
		return (1);
	v->mlx_win = mlx_new_window(v->mlx, (v->length_of_line * 50), (v->lines
				* 50), "So Long");
	if (!v->mlx_win)
		return (free(v->mlx_win), 1);
	v->keycode = 13;
	v->moves = 0;
	v->count = 0;
	ft_initialize_pointers(v);
	ft_fill_window(v);
	return (0);
}
