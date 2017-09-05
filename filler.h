/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 22:22:32 by lmazzi            #+#    #+#             */
/*   Updated: 2017/05/18 00:09:36 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define SIZE 10000

# include "libft.h"

typedef struct	s_solve
{
	int			pl;
	char		ma;
	char		mu;
	int			ya;
	int			xa;
	int			yp;
	int			xp;
	char		*map;
	char		*pcs;
	int			fpcs;
	int			fme;
	int			fyou;
	int			fs;
	char		*line;
	int			dify;
	int			difx;
	int			minx;
	int			miny;
	int			maxx;
	int			maxy;
	int			menx;
	int			meny;
	int			mexx;
	int			mexy;
	int			mcx;
	int			mcy;
	int			ucy;
	int			ucx;
}				t_gen;

typedef struct	s_me
{
	int			y;
	int			x;
}				t_me;

typedef struct	s_you
{
	int			y;
	int			x;
}				t_you;

typedef struct	s_pc
{
	int			y;
	int			x;
}				t_pc;

typedef struct	s_core
{
	int			y;
	int			x;
	int			sco;
	int			scom;
	int			scof;
	int			angle;
}				t_core;

void			ft_cord(t_gen *g, t_me *me, t_you *you, t_pc *pc);
void			ft_algo(t_gen *g, t_me *me, t_pc *pc);
int				ft_score(t_gen *g, t_core *sc);
int				ft_mescore(t_gen *g, t_core *sc);
int				ft_fscore(t_gen *g, t_core *sc);
int				ft_fiseason(t_gen *g, t_core *sc, int res);
int				ft_seseason(t_gen *g, t_core *sc, int res);
int				ft_thseason(t_gen *g, t_core *sc, int res);
int				ft_foseason(t_gen *g, t_core *sc, int res);

#endif
