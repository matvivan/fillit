/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:38:57 by matvivan          #+#    #+#             */
/*   Updated: 2019/11/30 15:37:09 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void		print(char **b)
{
	while (*b)
		ft_putendl(*b++);
	ft_putendl("");
}

void		set(char **b, int w)
{
	int		i;

	i = 0;
	while (i < w)
		b[i++] = ft_memset(ft_strnew(w), '.', w);
	b[i] = NULL;
}

int			put(char **tet, int j, char **b, int y)
{
	char	*c;

	if (*tet)
	{
		if ((*tet)[j])
		{
			if (*b && (*b)[y + j])
			{
				if ((*tet)[j] > '.')
				{
					c = *b + y + j;
					if (*c == '.' || *c == (*tet)[j])
						if (put(tet, j + 1, b, y))
							return (*c = (*c < 'A' ? (*tet)[j] : '.'));
				}
				else
					return (put(tet, j + 1, b, y));
			}
			return (0);
		}
		return (put(tet + 1, 0, b + 1, y));
	}
	return (1);
}

int			fillit(char **b, char ***tet)
{
	int		x;
	int		y;

	x = 0;
	while (b[x])
	{
		y = 0;
		while (b[x][y])
		{
			if (put(tet[0], 0, b + x, y))
			{
				system("clear && printf '\e[3J'");
				print(b);
				if (!tet[1] || fillit(b, tet + 1))
					return (1);
				put(tet[0], 0, b + x, y);
			}
			++y;
		}
		++x;
	}
	return (0);
}

void		resolve(char ***tetromino, int width)
{
	int		i;
	char	*board[width + 1];

	i = 0;
	set(board, width);
	if (!fillit(board, tetromino))
		resolve(tetromino, width + 1);
	else
		while (board[i])
		{
			ft_putendl(board[i]);
			ft_strdel(board + i++);
		}
}
