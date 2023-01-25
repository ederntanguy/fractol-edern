/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edern <edern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:30:50 by edern             #+#    #+#             */
/*   Updated: 2023/01/25 21:04:42 by edern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_coord calcule_all_it_julia(t_coord pos, int *i)
{
	t_coord z;
	int tmp;

	tmp = *i;
	z = pos;
	while (tmp < ITERATION && (z.complex * z.complex + z.reel * z.reel) <= 4)
	{
		z = get_next_pos_julia(z);
		// z = get_next_pos(z, c);
		tmp++;
	}
	*i = tmp;
	return (z);
}

t_coord get_next_pos_julia(t_coord z)
{
	t_coord next_z;

	next_z.reel = (z.reel * z.reel) - (z.complex * z.complex) + 0.285;
	next_z.complex = (2 * z.reel * z.complex);
	return (next_z);
}