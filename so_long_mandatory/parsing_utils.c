/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:54:07 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/02 09:59:46 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(void)
{
	ft_putstr("\e[1m\x1B[31mError\n\x1B[0m");
	exit(0);
}

char	**ft_copy_map_to_two_dim_array(char *file_path)
{
	int		fd;
	char	*str;
	char	*line;
	char	**map;

	str = NULL;
	fd = open(file_path, O_RDWR);
	if (fd < 0)
		ft_error();
	line = ft_get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			ft_error();
		str = ft_strjoin(str, line);
		free(line);
		line = ft_get_next_line(fd);
	}
	map = ft_split(str, '\n');
	free(str);
	return (map);
}
