/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 05:04:00 by lmazzi            #+#    #+#             */
/*   Updated: 2017/05/19 04:30:54 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_myinfluence(t_gen *g, t_me *me)
{
	int i;

	g->mexx = me[0].x;
	g->mexy = me[0].y;
	g->menx = me[0].x;
	g->meny = me[0].y;
	i = 0;
	while (i < g->fme)
	{
		g->mexx = (me[i].x > g->mexx) ? me[i].x : g->mexx;
		g->mexy = (me[i].y > g->mexy) ? me[i].y : g->mexy;
		i++;
	}
	i = 0;
	while (i < g->fme)
	{
		g->menx = (me[i].x < g->menx) ? me[i].x : g->menx;
		g->meny = (me[i].y < g->meny) ? me[i].y : g->meny;
		i++;
	}
	g->mcx = (g->menx + ((g->mexx - g->menx) / 2));
	g->mcy = (g->meny + ((g->mexy - g->meny) / 2));
}

static void	ft_influence(t_gen *g, t_you *you)
{
	int i;

	g->maxx = you[0].x;
	g->maxy = you[0].y;
	g->minx = you[0].x;
	g->miny = you[0].y;
	i = 0;
	while (i < g->fyou)
	{
		g->maxx = (you[i].x > g->maxx) ? you[i].x : g->maxx;
		g->maxy = (you[i].y > g->maxy) ? you[i].y : g->maxy;
		i++;
	}
	i = 0;
	while (i < g->fyou)
	{
		g->minx = (you[i].x < g->minx) ? you[i].x : g->minx;
		g->miny = (you[i].y < g->miny) ? you[i].y : g->miny;
		i++;
	}
	g->ucx = (g->minx + ((g->maxx - g->minx) / 2));
	g->ucy = (g->miny + ((g->maxy - g->miny) / 2));
}

static void	ft_pcscord(t_gen *g, t_pc *pc)
{
	int	p;

	p = 0;
	g->fpcs = 0;
	while (g->pcs[p] != '\0')
	{
		while (g->pcs[p] == '.')
			p++;
		if (g->pcs[p] == '*')
		{
			(pc[g->fpcs]).x = p % g->xp;
			(pc[g->fpcs++]).y = p++ / g->xp;
		}
	}
}

void		ft_cord(t_gen *g, t_me *me, t_you *you, t_pc *pc)
{
	int i;

	g->fme = 0;
	g->fyou = 0;
	i = 0;
	while (g->map[i] != '\0')
	{
		while (g->map[i] == '.')
			i++;
		if (g->map[i] == g->ma || g->map[i] == (g->ma + 32))
		{
			(me[g->fme]).x = i % g->xa;
			(me[g->fme++]).y = i++ / g->xa;
		}
		if (g->map[i] == g->mu || g->map[i] == (g->mu + 32))
		{
			(you[g->fyou]).x = i % g->xa;
			(you[g->fyou++]).y = i++ / g->xa;
		}
	}
	ft_pcscord(g, pc);
	ft_influence(g, you);
	ft_myinfluence(g, me);
}
