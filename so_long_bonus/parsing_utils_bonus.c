/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:48:39 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/20 21:00:55 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error(int cases)
{
	if (cases == 1)
		ft_putstr("\e[1m\x1B[31mError: \e[37mtoo few arguments\n");
	else if (cases == 2)
		ft_putstr("\e[1m\x1B[31mError: \e[37minvalid extension\n");
	else if (cases == 3)
		ft_putstr("\e[1m\x1B[31mError: \e[37mfile does not exist\n");
	else if (cases == 4)
		ft_putstr("\e[1m\x1B[31mError: \e[37minvalid map\n");
	else if (cases == 5)
		ft_putstr("\e[1m\x1B[31mError: \e[37mtoo many arguments\n");
	else if (cases == 6)
		ft_putstr("\e[1m\x1B[31mError: \e[37mthere no valid path\n");
	exit(1);
}

char	*ft_read_map(int fd)
{
	char	*str;
	char	*line;	

	str = NULL;
	line = ft_get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) < 4)
			ft_error(4);
		str = ft_strjoin(str, line);
		free(line);
		line = ft_get_next_line(fd);
	}
	return (str);
}

char	**ft_copy_map_to_two_dim_array(char *file_path, t_vars *v)
{
	int		i;
	int		fd;
	char	*str;
	char	**map;

	i = -1;
	v->lines = 0;
	v->newline = 0;
	fd = open(file_path, O_RDWR);
	if (fd < 0)
		ft_error(3);
	str = ft_read_map(fd);
	if (!str)
		return (NULL);
	while (str[++i])
		if (str[i] == '\n')
			v->newline++;
	map = ft_split(str, '\n');
	while (map[v->lines])
		v->lines++;
	if (v->lines <= v->newline)
		ft_error(4);
	free(str);
	return (map);
}

int	ft_check_special_character(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'Z')
				return (1);
		}
	}
	return (0);
}
