/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edern <edern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:25:52 by etanguy           #+#    #+#             */
/*   Updated: 2023/01/25 22:04:27 by edern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void init_plan(t_plan *plan)
{
	plan->xplan = 1;
	plan->yplan = 1;
	plan->zoom = 1;
	plan->changex = 0;
	plan->changey = 0;
	plan->lastzoom = 1;
	plan->ypos_to_zoom = 500;
	plan->xpos_to_zoom = 500;
	plan->move_arrow = 0;
	plan->first = 0;
	plan->color_array = color_set();
}

void zoom_func(t_mlxptr *ptr, t_plan *plan, int zoominput, t_all *all)
{
	change_offset(plan, plan->xpos_to_zoom, plan->ypos_to_zoom);
	if (zoominput == 4)
	{
		plan->zoom *= 0.8;
		show(&(all->img), plan, ptr);
	}
	else if (zoominput == 5)
	{
		plan->zoom *= 1.2;
		show(&(all->img), plan, ptr);
	}
}

void choose_fractal(t_all *all, int argc, char **argv)
{
	int i;

	if (argc <= 1 || (!(argc == 4) && ft_strcmp(argv[1], "Julia")) || (!(argc == 2) && ft_strcmp(argv[1], "Mandelbrot")) || !(ft_strcmp(argv[1], "Julia") || ft_strcmp(argv[1], "Mandelbrot")))
	{
		i = write(1, "you don't write a Valide set.\n", 30);
		i = write(1, "please write Mandelbrot fot the Mandelbroat Fractal\n", 52);
		i = write(1, "Julia for the Julia fractal with different settings\n", 52);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], "Mandelbrot"))
		all->plan.is_mandelbrot = 1;
	else
	{
		all->plan.is_mandelbrot = 0;
		all->plan.julia_set_re = ft_atof(argv[2]);
		all->plan.julia_set_im = ft_atof(argv[3]);
		printf("%lf", all->plan.julia_set_im);
	}
	(void)i;
}

int main(int argc, char **argv)
{
	t_mlxptr ptr;
	t_data img;
	t_plan plan;
	t_all all;

	choose_fractal(&all, argc, argv);
	init_plan(&plan);
	ptr.zoominput = 0;
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, 1000, 1000, "edourn");
	img.img = mlx_new_image(ptr.mlx_ptr, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	show(&img, &plan, &ptr);
	all.plan = plan;
	all.ptr = ptr;
	all.img = img;
	mlx_key_hook(ptr.win_ptr, keyboard_event, &all);
	mlx_mouse_hook(ptr.win_ptr, mouse_event, &all);
	mlx_loop(ptr.mlx_ptr);
	mlx_hook(ptr.win_ptr, DestroyNotify, ButtonReleaseMask, quit, &all);
	return (0);
}
