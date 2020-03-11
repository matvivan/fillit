/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:55:48 by matvivan          #+#    #+#             */
/*   Updated: 2019/12/14 23:55:50 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int			valid_tetro(char **t, int (*c)())
{
	if (!t[1])
		return (!c(t[0], "####"));
	else if (!t[2])
	{
		if (!c(t[0], "###"))
			return (!c(t[1], "#..") || !c(t[1], ".#.") || !c(t[1], "..#"));
		else if (!c(t[1], "###"))
			return (!c(t[0], "#..") || !c(t[0], ".#.") || !c(t[0], "..#"));
		else if (!c(t[0], ".##") || !c(t[1], ".##"))
			return (!c(t[0], "##.") || !c(t[1], "##."));
		return (!c(t[0], "##") && !c(t[1], "##"));
	}
	else if (!t[3])
	{
		if (!c(t[1], "##") && (!c(t[0], "#.") || !c(t[0], ".#")))
			return (!c(t[2], "#.") || !c(t[2], ".#"));
		else if (!c(t[0], "##") && !c(t[1], "#."))
			return (!c(t[2], "#."));
		else if (!c(t[0], "##") && !c(t[1], ".#"))
			return (!c(t[2], ".#"));
		else if (!c(t[2], "##") && !c(t[0], "#."))
			return (!c(t[1], "#."));
		return (!c(t[2], "##") && !c(t[0], ".#") && !c(t[1], ".#"));
	}
	return (!c(t[0], "#") && !c(t[1], "#") && !c(t[2], "#") && !c(t[3], "#"));
}

int			check_space(char **tet, int y)
{
	while (*tet)
	{
		if ((*tet)[y] == '#')
			return (1);
		++tet;
	}
	return (0);
}

void		move(char **tet)
{
	int		i;

	ft_strdel(tet);
	i = 0;
	while (tet[i + 1])
	{
		tet[i] = tet[i + 1];
		++i;
	}
	tet[i] = NULL;
}

void		cut(char ***tetro, int ymin, int ymax, char *tmp)
{
	int		i;

	while (!check_space(tetro[0], ymin))
		++ymin;
	ymax = ymin;
	while (check_space(tetro[0], ymax))
		++ymax;
	while (tetro[0][0] && !ft_strchr(tetro[0][0], '#'))
		move(tetro[0]);
	i = 0;
	while (tetro[0][i] && ft_strchr(tetro[0][i], '#'))
	{	
		tmp = tetro[0][i];
		tetro[0][i] = ft_strsub(tetro[0][i], ymin, ymax - ymin);
		ft_strdel(&tmp);
		++i;
	}
	while (tetro[0][i])
		ft_strdel(tetro[0] + i++);
}

int			valid_list(char ***tetro)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	while (tetro[++i])
	{
		cut(tetro + i, 0, 0, NULL);
		if (!valid_tetro(tetro[i], &ft_strcmp))
			return (0);
		x = -1;
		while (tetro[i][++x])
		{
			y = -1;
			while (tetro[i][x][++y])
				if (tetro[i][x][y] == '#')
					tetro[i][x][y] = 'A' + i;
		}
	}
	return (1);
}
