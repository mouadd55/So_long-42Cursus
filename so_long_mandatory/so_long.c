/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:23:07 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/01 19:38:46 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	char	**map;

	if (ac == 2)
	{
		if (ft_check_extension(av[1]))
			ft_error();
		map = ft_copy_map_to_two_dim_array(av[1]);
		if (ft_check_components(map))
			ft_error();
		for (int i = 0; i < 5; i++)
			printf("|%s|\n", map[i]);
	}
	else
		ft_error();
}
