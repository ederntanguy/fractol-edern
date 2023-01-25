/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_and_iteration.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edern <edern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:59:36 by etanguy           #+#    #+#             */
/*   Updated: 2023/01/25 21:05:06 by edern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_coord get_next_pos(t_coord z, t_coord c)
{
	t_coord next_z;

	next_z.reel = (z.reel * z.reel) - (z.complex * z.complex) + c.reel;
	next_z.complex = (2 * z.reel * z.complex) + c.complex;
	return (next_z);
}

t_coord calcule_all_it(t_coord pos, int *i)
{
	t_coord c;
	t_coord z;
	int tmp;

	tmp = *i;
	z.reel = 0;
	z.complex = 0;
	c = pos;
	while (tmp < ITERATION && (z.complex * z.complex + z.reel * z.reel) <= 4)
	{
		z = get_next_pos(z, c);
		tmp++;
	}
	*i = tmp;
	return (z);
}

t_coord pos_point(int x, int y, t_plan *plan)
{
	t_coord pos;

	pos.reel = (((x * 2) * LEN * plan->zoom) * 0.001) - (LEN * plan->zoom);
	pos.complex = (((y * 2) * LEN * plan->zoom) * 0.001) - (LEN * plan->zoom);
	pos.reel += plan->changex;
	pos.complex -= plan->changey;
	return (pos);
}