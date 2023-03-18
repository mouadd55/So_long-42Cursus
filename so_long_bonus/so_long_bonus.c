/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:50:59 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/18 05:08:24 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_vars	*v;

	v = malloc(sizeof(t_vars));
	if (ac < 2)
		ft_error(1);
	else if (ac > 2)
		ft_error(5);
	if (ft_check_extension(av[1]))
		ft_error(2);
	v->map = ft_copy_map_to_two_dim_array(av[1], v);
	v->tmp = ft_copy_map_to_two_dim_array(av[1], v);
	if (!v->map || ft_check_valid_map(v))
		ft_error(4);
	if (ft_valid_path(v))
		ft_error(6);
	if (ft_open_window(v))
		exit (1);
	mlx_loop_hook(v->mlx, ft_fill_window, v);
	mlx_hook(v->mlx_win, 2, 0, key_press, v);
	mlx_hook(v->mlx_win, 17, 0, ft_close_window, v);
	mlx_loop(v->mlx);
	ft_free_arr(v->map);
}
