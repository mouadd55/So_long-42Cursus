/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:49:40 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/20 21:00:51 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_extension(char *file_name)
{
	int	i;

	if (ft_strcmp(file_name, ".ber") == 0)
		return (1);
	else
	{
		i = ft_strlen(file_name) - 4;
		if (file_name[0] != '.' && ft_strcmp(file_name + i, ".ber") == 0)
			return (0);
	}
	return (1);
}

int	ft_check_borders(t_vars *v)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (v->length_of_line == v->lines)
		return (1);
	while (++j < v->length_of_line)
		if (v->map[0][j] != '1' || v->map[v->lines - 1][j] != '1')
			return (1);
	while (++i <= v->lines - 2)
		if (v->map[i][0] != '1' || v->map[i][v->length_of_line - 1] != '1')
			return (1);
	return (0);
}

int	ft_check_rectangular_shape(t_vars *v)
{
	int	i;

	i = -1;
	while (++i < v->lines)
		if (v->length_of_line != (int)ft_strlen(v->map[i]))
			return (1);
	if (v->lines == v->length_of_line)
		return (1);
	return (0);
}

int	ft_check_characters(t_vars *v)
{
	int		i;
	int		j;

	v->c = 0;
	v->e = 0;
	v->p = 0;
	i = -1;
	while (v->map[++i])
	{
		j = -1;
		while (v->map[i][++j])
		{
			if (v->map[i][j] == 'E')
				v->e++;
			else if (v->map[i][j] == 'P')
				v->p++;
			else if (v->map[i][j] == 'C')
				v->c++;
		}
	}
	if (v->e == 1 && v->p == 1 && v->c >= 1)
		return (0);
	return (1);
}

int	ft_check_valid_map(t_vars *v)
{
	v->length_of_line = ft_strlen(v->map[0]);
	if (ft_check_borders(v))
		return (1);
	else if (v->lines == v->length_of_line)
		return (1);
	else if (ft_check_characters(v))
		return (1);
	else if (ft_check_rectangular_shape(v))
		return (1);
	else if (ft_check_special_character(v->map))
		return (1);
	return (0);
}
