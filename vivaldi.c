/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vivaldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 23:17:47 by lmazzi            #+#    #+#             */
/*   Updated: 2017/05/19 04:30:49 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
/*
** list of 4 functions to take advantage of specific positions
** I divide the board in 4 theoretical sectors and each time my center of
** influence is in the same sector of the opponent center of influence but
** I have a more centered position, I chose solutions that cut on the sides
** and try to immediately isolate the opponent making it harder for him put his piece
*/
int		ft_fiseason(t_gen *g, t_core *sc, int res)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (i < g->fs)
	{
		sc[i].angle = sc[i].x - (sc[i].y / 2);
		i++;
	}
	i = 0;
	while (i < g->fs)
	{
		x = sc[res].angle;
		res = (sc[i].angle > x) ? i : res;
		i++;
	}
	return (res);
}

int		ft_seseason(t_gen *g, t_core *sc, int res)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (i < g->fs)
	{
		sc[i].angle = sc[i].x + (sc[i].y / 2);
		i++;
	}
	i = 0;
	while (i < g->fs)
	{
		x = sc[res].angle;
		x = (sc[i].angle > x) ? i : res;
		i++;
	}
	return (res);
}

int		ft_thseason(t_gen *g, t_core *sc, int res)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (i < g->fs)
	{
		sc[i].angle = (sc[i].y / 2) - sc[i].x;
		i++;
	}
	i = 0;
	while (i < g->fs)
	{
		x = sc[res].angle;
		x = (sc[i].angle > x) ? i : res;
		i++;
	}
	return (res);
}

int		ft_foseason(t_gen *g, t_core *sc, int res)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (i < g->fs)
	{
		sc[i].angle = sc[i].x + (sc[i].y * 2);
		i++;
	}
	i = 0;
	while (i < g->fs)
	{
		x = sc[res].angle;
		x = (sc[i].angle < x) ? i : res;
		i++;
	}
	return (res);
}
