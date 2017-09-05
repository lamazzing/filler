/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:58:13 by lmazzi            #+#    #+#             */
/*   Updated: 2017/05/25 01:27:54 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** score for a piece based on the min distance with the opponent influence
** and max distance with my influence
*/
int		ft_fscore(t_gen *g, t_core *sc)
{
	int i;

	i = 0;
	while (i < g->fs)
	{
		sc[i].scof = sc[i].scom - sc[i].sco;
		i++;
	}
	return (1);
}
/*
** score for a piece based on his distance with the my influence
*/

int		ft_mescore(t_gen *g, t_core *sc)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < g->fs)
	{
		x = ((sc[i].x - g->mcx) > 0) ? (sc[i].x - g->mcx) :
			((sc[i].x - g->mcx) * -1);
		y = ((sc[i].y - g->mcy) > 0) ? (sc[i].y - g->mcy) :
			((sc[i].y - g->mcy) * -1);
		sc[i].scom = x + y;
		i++;
	}
	return (1);
}
/*
** score for a piece based on his distance with the opponent influence
*/
int		ft_score(t_gen *g, t_core *sc)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < g->fs)
	{
		x = ((sc[i].x - g->ucx) > 0) ? (sc[i].x - g->ucx) :
			((sc[i].x - g->ucx) * -1);
		y = ((sc[i].y - g->ucy) > 0) ? (sc[i].y - g->ucy) :
			((sc[i].y - g->ucy) * -1);
		sc[i].sco = x + y;
		i++;
	}
	return (1);
}
