/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 00:37:35 by lmazzi            #+#    #+#             */
/*   Updated: 2017/05/25 01:25:16 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_check_piece(t_gen *g, t_pc *pc)
{
	int p;
	int ko;

	ko = 0;
	p = 0;
	while (p < g->fpcs)
	{
		if ((g->map[((pc[p].y + g->dify) * g->xa) +
					pc[p].x + g->difx] != '.') ||
				((pc[p].x + g->difx) >= g->xa) ||
				((pc[p].y + g->dify) >= g->ya) || ((pc[p].x + g->difx) < 0) ||
				((pc[p].y + g->dify) < 0))
			ko++;
		if (ko > 1)
			break ;
		p++;
	}
	return (ko);
}
/*
** ft_check_piece controls if the piece can be placed
*/
static void	ft_check_pos(t_gen *g, t_me *me, t_core *sc, t_pc *pc)
{
	int p;
	int m;

	p = 0;
	m = 0;
	g->fs = 0;
	while (m < g->fme)
	{
		while (p < g->fpcs)
		{
			g->difx = me[m].x - pc[p].x;
			g->dify = me[m].y - pc[p++].y;
			if (ft_check_piece(g, pc) == 1)
			{
				sc[g->fs].x = g->difx;
				sc[g->fs++].y = g->dify;
			}
		}
		p = 0;
		m++;
	}
}
/*
** the first functions are in the file vivaldi.c (based on the 4 seasons :)) and
** take into account a positional advantage to isolate as soon as possible the opponent
** player, each "season" function is in charge of one sector.
** if there's no positional advantage then the sc[].scof score is used, 
** based on the piece that max the distance from my center of influence 
** and min the distance from the opponent center of influence.
*/
static int	ft_finalgo(t_gen *g, t_core *sc, int res)
{
	int	i;
	int	x;

	i = 0;
	if (g->mexy >= (g->ya / 2) && g->mexy <= g->miny && g->menx < g->minx)
		res = ft_fiseason(g, sc, res);
	else if (g->meny < (g->ya / 2) && g->meny >= g->maxy && g->menx < g->minx)
		res = ft_seseason(g, sc, res);
	else if (g->meny < (g->ya / 2) && g->meny >= g->maxy && g->mexx > g->maxx)
		res = ft_thseason(g, sc, res);
	else if (g->mexy >= (g->ya / 2) && g->mexy <= g->miny && g->mexx > g->maxx)
		res = ft_foseason(g, sc, res);
	else
	{
		i = 0;
		while (i < g->fs)
		{
			x = sc[res].scof;
			res = (sc[i].scof >= x) ? i : res;
			i++;
		}
	}
	return (res);
}
/*
** ft_check_pos: register every available position
** ft_score: gives a score based on the distance between my piece and the center of influence of the opponent
** ft_mescore: gives a score based on the distance between my piece and the center of influence of my player
** If I have a solution I give to the VM the coordinates to put the piece in X and Y
*/
void		ft_algo(t_gen *g, t_me *me, t_pc *pc)
{
	static t_core	sc[SIZE];
	int				i;
	int				res;

	i = 0;
	res = 0;
	ft_check_pos(g, me, sc, pc);
	if (g->fs > 0 && ft_score(g, sc) && ft_mescore(g, sc))
		ft_fscore(g, sc);
	res = ft_finalgo(g, sc, res);
	i = 0;
	sc[res].y = (g->fs < 1 &&
			!(sc[res].x = 0)) ? 0 : sc[res].y;
	ft_putnbr(sc[res].y);
	write(1, " ", 1);
	ft_putnbr(sc[res].x);
	write(1, "\n", 1);
}
