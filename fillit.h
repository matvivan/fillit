/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:50:27 by matvivan          #+#    #+#             */
/*   Updated: 2019/12/11 10:52:54 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

void		resolve(char ***tetromino, int width);
int			valid_list(char ***tetro);
void		clean(char **ptr);

#endif
