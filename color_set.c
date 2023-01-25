/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:41:23 by etanguy           #+#    #+#             */
/*   Updated: 2023/01/25 15:58:38 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	*color_set1(void)
{
	int	*tab;
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	r = 0xFF;
	g = 0x00;
	b = 0x00;
	tab = malloc(sizeof(int) * 1280);
	while (g < 0xFF)
		tab[i++] = r << 16 | g++ << 8;
	while (r > 0x0)
		tab[i++] = r-- << 16 | g << 8;
	while (b < 0xFF)
		tab[i++] = g << 8 | b++;
	while (g > 0x0)
		tab[i++] = g-- << 8 | b;
	while (r < 0xFF)
		tab[i++] = r++ << 16 | b;
	return (tab);
}

void	color_set_1(int *color_tab, int *i)
{
	while ((*i) <= (int)(WHEEL_SIZE * 0.16))
	{
		color_tab[*i] = ((int)(32 / (WHEEL_SIZE * 0.16) * (*i))) << 16
			| (7 + (int)(100 / (WHEEL_SIZE * 0.16) * (*i))) << 8
			| (100 + (int)((203 - 100) / (WHEEL_SIZE * 0.16) * (*i)));
		(*i)++;
	}
	while (*i <= (int)(WHEEL_SIZE * 0.42))
	{
		color_tab[*i] = (32 + (int)((237.0 - 32)
					/ (WHEEL_SIZE * 0.26) * ((*i) - WHEEL_SIZE * 0.16))) << 16
			| (107 + (int)((255.0 - 107)
					/ (WHEEL_SIZE * 0.26) * ((*i) - WHEEL_SIZE * 0.16))) << 8
			| (203 + (int)((255.0 - 203)
					/ (WHEEL_SIZE * 0.26) * ((*i) - WHEEL_SIZE * 0.16)));
		(*i)++;
	}
}

void	color_set_2(int *color_tab, int *i)
{
	while ((*i) <= (int)(WHEEL_SIZE * 0.6425))
	{
		color_tab[*i] = (237 + (int)((255.0 - 237)
					/ (WHEEL_SIZE * 0.2225) * ((*i) - WHEEL_SIZE * 0.42))) << 16
			| (255 + (int)((170.0 - 255)
					/ (WHEEL_SIZE * 0.2225) * ((*i) - WHEEL_SIZE * 0.42))) << 8
			| (255 + (int)(-255.0
					/ (WHEEL_SIZE * 0.2225) * ((*i) - WHEEL_SIZE * 0.42)));
		(*i)++;
	}
	while ((*i) <= (int)(WHEEL_SIZE * 0.8575))
	{
		color_tab[*i] = (255 + (int)(-255.0 / (WHEEL_SIZE
						* 0.215) * ((*i) - WHEEL_SIZE * 0.6425))) << 16
			| (170 + (int)((2.0 - 170) / (WHEEL_SIZE
						* 0.215) * ((*i) - WHEEL_SIZE * 0.6425))) << 8;
		(*i)++;
	}
}

int	*color_set(void)
{
	int	*color_tab;
	int	i;

	i = 0;
	color_tab = malloc(sizeof(int) * WHEEL_SIZE);
	color_set_1(color_tab, &i);
	color_set_2(color_tab, &i);
	while (i < (int)(WHEEL_SIZE))
		color_tab[i++] = 0;
	return (color_tab);
}
