/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edern <edern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:00:15 by etanguy           #+#    #+#             */
/*   Updated: 2023/01/25 21:09:24 by edern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	color_choose(t_data *img, int x, int y, t_plan *plan)
{
	t_coord	pos;
	int		i;

	i = 0;
	pos = pos_point(x, y, plan);
	pos = calcule_all_it(pos, &i);
	my_mlx_pixel_put(img, x, y, plan->color_array[i * 5]);
}

void	change_offset(t_plan *plan, int x, int y)
{
	plan->changex += (x * (2 * LEN * plan->lastzoom)
			* 0.001) - (LEN * plan->lastzoom);
	plan->changey += (y * (2 * LEN * plan->lastzoom)
			* -0.001) + (LEN * plan->lastzoom);
}

void	show(t_data *img, t_plan *plan, t_mlxptr *ptr)
{
	int		x;
	int		y;

	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{	
			color_choose(img, x, y, plan);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, img->img, 0, 0);
	plan->lastzoom = plan->zoom;
}
