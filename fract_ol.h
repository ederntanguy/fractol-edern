/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edern <edern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:03:05 by etanguy           #+#    #+#             */
/*   Updated: 2023/01/25 22:03:06 by edern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H

#define FRACT_OL_H

#define ITERATION 255
#define LEN 2
#define WHEEL_SIZE 1280
#include <stdlib.h>
#include "mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <X11/X.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_plan
{
	double zoom;
	double lastzoom;
	double xplan;
	double yplan;
	double changex;
	double changey;
	int xpos_to_zoom;
	int ypos_to_zoom;
	int *color_array;
	double arrowx;
	double arrowy;
	int move_arrow;
	int first;
	int is_mandelbrot;
	double julia_set_re;
	double julia_set_im;
} t_plan;

typedef struct s_coord
{
	double reel;
	double complex;
} t_coord;

typedef struct s_mlxptr
{
	void *mlx_ptr;
	void *win_ptr;
	int zoominput;
} t_mlxptr;

typedef struct s_all
{
	t_mlxptr ptr;
	t_coord pos;
	t_plan plan;
	t_data img;
} t_all;

void my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_coord get_next_pos(t_coord z, t_coord c);
t_coord calcule_all_it(t_coord pos, int *i);
t_coord pos_point(int x, int y, t_plan *plan);
int *color_set1(void);
int *color_set(void);
void color_set_1(int *color_tab, int *i);
void color_set_2(int *color_tab, int *i);
void color_choose(t_data *img, int x, int y, t_plan *plan);
void change_offset(t_plan *plan, int x, int y);
void show(t_data *img, t_plan *plan, t_mlxptr *ptr);
void init_plan(t_plan *plan);
void zoom_func(t_mlxptr *ptr, t_plan *plan, int zoominput, t_all *all);
int keyboard_event(int key, t_all *all);
int mouse_event(int button, int x, int y, void *param);
int quit(t_all *all);
t_coord get_next_pos_julia(t_coord z);
t_coord calcule_all_it_julia(t_coord pos, int *i);
int ft_strcmp(char *str1, char *str2);
int ft_strlen(char *str);
void choose_fractal(t_all *all, int argc, char **argv);
double ft_atof(char *str);

#endif