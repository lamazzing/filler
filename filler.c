/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 22:00:04 by lmazzi            #+#    #+#             */
/*   Updated: 2017/05/19 04:30:47 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

static int	ft_fline(t_gen *g)
{
	free(g->line);
	g->line = NULL;
	return (1);
}

static void	ft_playernum(t_gen *g)
{
	get_next_line(0, &g->line);
	g->pl = ft_natoi(g->line, 1);
	ft_fline(g);
	g->ma = (g->pl == 1) ? 'O' : 'X';
	g->mu = (g->pl == 1) ? 'X' : 'O';
}

static void	ft_readmap(t_gen *g)
{
	char	*tmp;
	char	*ttmp;
	int		i;
	int		fi;

	i = g->ya;
	fi = 0;
	get_next_line(0, &g->line);
	while (i--)
	{
		if (fi == 1 && get_next_line(0, &g->line))
		{
			tmp = g->map;
			g->map = ft_strjoin(g->map,
					(ttmp = (ft_strsub(g->line, 4, g->xa))));
			free(tmp);
			free(ttmp);
			ft_fline(g);
		}
		if (fi == 0 && (fi = 1) && get_next_line(0, &g->line) &&
				(g->map = ft_strsub(g->line, 4, g->xa)))
			ft_fline(g);
	}
}

static void	ft_readp(t_gen *g)
{
	char	*tmp;
	int		i;
	int		fi;

	if (!(fi = 0) && get_next_line(0, &g->line))
	{
		g->yp = ft_natoi(g->line, 1);
		g->xp = ft_natoi(g->line, 2);
		ft_fline(g);
	}
	i = g->yp;
	while (i--)
	{
		if (fi == 1 && get_next_line(0, &g->line) && (tmp = g->pcs)
				&& (g->pcs = ft_strjoin(g->pcs, g->line)))
		{
			ft_fline(g);
			free(tmp);
		}
		if (fi == 0 && (fi = 1) && get_next_line(0, &g->line)
				&& (g->pcs = ft_strdup(g->line)))
			ft_fline(g);
	}
}
/*
** ft_playernum: check if first or second player
** ft_readmap: read and register the map updated with the opposite player piece
** ft_readp: read the piece provided that has to be placed
** ft_cord: register the coordinates of the pieces placed for me and for my opponent and 
** compute the center of influence for both players
** ft_algo: check available positions to put the piece and give a score for each 
** based on some rules explained in the function 
*/
int			main(void)
{
	t_gen	g[1];
	t_me	me[SIZE];
	t_you	you[SIZE];
	t_pc	pc[100];
	int		end;

	ft_playernum(g);
	end = 0;
	while (end == 0)
	{
		if (get_next_line(0, &g->line))
		{
			g->ya = ft_natoi(g->line, 1);
			g->xa = ft_natoi(g->line, 2);
		}
		ft_readmap(g);
		ft_readp(g);
		ft_cord(g, me, you, pc);
		ft_algo(g, me, pc);
		end = (g->fs != 0) ? 0 : 1;
	}
	return (0);
}
