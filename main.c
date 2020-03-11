/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:01:10 by matvivan          #+#    #+#             */
/*   Updated: 2019/12/10 19:22:59 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include "fcntl.h"

void		clean(char **ptr)
{
	int		i;

	i = 0;
	while (ptr[i])
		ft_strdel(ptr + i++);
	free(ptr);
}

int			valid_chr(char **tet)
{
	int		x;
	int		y;
	int		count;

	x = 0;
	count = 0;
	while (tet[x])
	{
		y = 0;
		while (tet[x][y])
		{
			if (tet[x][y] == '#')
				++count;
			else if (tet[x][y] != '.')
				return (0);
			++y;
		}
		++x;
	}
	return (count == 4);
}

int			get_one(int fd, char ***tet)
{
	int		i;

	i = -1;
	(*tet) = (char **)malloc(sizeof(char *) * 5);
	while (++i < 4)
	{
		(*tet)[i] = (char *)malloc(sizeof(char) * 5);
		if (read(fd, (*tet)[i], 5) == 5)
			if (!((*tet)[i][4] -= '\n'))
				continue ;
		(*tet)[i + 1] = NULL;
		return (0);
	}
	(*tet)[i] = NULL;
	return (valid_chr(*tet));
}

int			get(int fd, char ****tetro, char c)
{
	int		count;

	count = 0;
	*tetro = (char ***)malloc(sizeof(char **) * 27);
	while (count < 26 && get_one(fd, *tetro + count++))
	{
		if (read(fd, &c, 1))
		{
			if (c == '\n')
				continue ;
			break ;
		}
		(*tetro)[count] = NULL;
		return (count);
	}
	(*tetro)[count] = NULL;
	return (0);
}

int			sqr(int n)
{
	int		i;

	i = 0;
	while (i * i < n)
		++i;
	return (i);
}

int			main(int fd, char **file)
{
	char	***tetromino;
	int		n;

	if (fd == 2)
	{
		if ((fd = open(file[1], O_RDONLY)) > 0)
		{
			n = sqr(get(fd, &tetromino, 0) * 4);
			if (n && valid_list(tetromino))
				resolve(tetromino, n);
			else
				ft_putendl("error");
			while (*tetromino)
				clean(*tetromino++);
			close(fd);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("usage\n\t./fillit [tetromino_file]");
	system("leaks fillit");
	return (0);
}
