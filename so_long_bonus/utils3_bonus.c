/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 05:35:29 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/20 21:54:31 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	nbr_len(long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	nb = n;
	len = nbr_len(nb);
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= (-1);
	}
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb != 0)
	{
		str[len--] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}

void	ft_print_moves_in_window(t_vars *v)
{
	char	*move;

	v->x = 0;
	while (v->x < (v->length_of_line * 50))
	{
		mlx_put_image_to_window(v->mlx, v->mlx_win, v->bg, v->x, v->y);
		v->x += 50;
	}
	move = ft_itoa(v->moves);
	mlx_string_put(v->mlx, v->mlx_win, 20, v->lines * 50 + 10, 0x111, "Moves:");
	mlx_string_put(v->mlx, v->mlx_win, 90, v->lines * 50 + 10, 0x111,
		move);
	free(move);
}
