/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:55:30 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/18 05:51:11 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count_characters(char **map)
{
	int		i;
	int		j;
	t_vars	v;

	v.c = 0;
	v.e = 0;
	v.p = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				v.e++;
			else if (map[i][j] == 'P')
				v.p++;
			else if (map[i][j] == 'C')
				v.c++;
		}
	}
	if (v.e == 0 && v.p == 0 && v.c == 0)
		return (1);
	return (0);
}

char	**ft_fill(char **map, t_vars *v, int i, int j)
{
	if (i >= v->lines || j >= v->length_of_line || i < 0 || j < 0
		|| map[i][j] == '1' || map[i][j] == '#' || map[i][j] == 'Z')
		return (0);
	map[i][j] = '#';
	ft_fill(map, v, i + 1, j);
	ft_fill(map, v, i - 1, j);
	ft_fill(map, v, i, j + 1);
	ft_fill(map, v, i, j - 1);
	return (map);
}

int	ft_valid_path(t_vars *v)
{
	int		x;
	int		y;

	v->i = 0;
	while (v->tmp[v->i])
	{
		v->j = 0;
		while (v->tmp[v->i][v->j])
		{
			if (v->tmp[v->i][v->j] == 'P')
			{
				x = v->i;
				y = v->j;
				break ;
			}
			v->j++;
		}
		v->i++;
	}
	if (ft_count_characters(ft_fill(v->tmp, v, x, y)))
		return (0);
	return (1);
}
