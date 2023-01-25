/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edern <edern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:57:00 by etanguy           #+#    #+#             */
/*   Updated: 2023/01/25 18:51:26 by edern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void clear_all(t_all *all)
{
	mlx_destroy_image(all->ptr.mlx_ptr, all->img.img);
	mlx_destroy_window(all->ptr.mlx_ptr, all->ptr.win_ptr);
	mlx_destroy_display(all->ptr.mlx_ptr);
	free(all->ptr.mlx_ptr);
	free(all->plan.color_array);
	exit(EXIT_SUCCESS);
}

int quit(t_all *all)
{
	printf("ici\n");
	clear_all(all);
	return (0);
}

void change_color_set(t_all *all)
{
	free(all->plan.color_array);
	if (all->plan.first == 0)
	{
		all->plan.color_array = color_set1();
		all->plan.first = 1;
	}
	else if (all->plan.first == 1)
	{
		all->plan.first = 0;
		all->plan.color_array = color_set();
	}
}

int keyboard_event(int key, t_all *all)
{
	if (key == 65307)
		clear_all(all);
	else if (key == 97)
		change_color_set(all);
	else if (key == 65363)
		all->plan.changex += (0.5 * all->plan.zoom);
	else if (key == 65361)
		all->plan.changex -= 0.5 * all->plan.zoom;
	else if (key == 65364)
		all->plan.changey -= 0.5 * all->plan.zoom;
	else if (key == 65362)
		all->plan.changey += 0.5 * all->plan.zoom;
	if (key == 65363 || key == 65361 || key == 65364 || key == 65362 || key == 97)
		show(&(all->img), &(all->plan), &(all->ptr));
	return (0);
}

int mouse_event(int button, int x, int y, void *param)
{
	t_all *all;

	all = param;
	all->plan.xpos_to_zoom = x;
	all->plan.ypos_to_zoom = y;
	if (button == 5)
		zoom_func(&(all->ptr), &(all->plan), 5, all);
	else if (button == 4)
		zoom_func(&(all->ptr), &(all->plan), 4, all);
	else if (button == 1)
	{
		change_offset(&(all->plan), x, y);
		show(&(all->img), &(all->plan), &(all->ptr));
	}
	return (1);
}
