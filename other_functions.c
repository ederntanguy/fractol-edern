/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edern <edern@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:21:33 by edern             #+#    #+#             */
/*   Updated: 2023/01/25 22:09:31 by edern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_strcmp(char *str1, char *str2)
{
    int i;

    i = 0;
    while (str1[i] && str2[i])
    {
        if (str1[i] != str2[i])
            return (0);
        i++;
    }
    if (str1[i] != str2[i])
        return (0);
    return (1);
}

double ft_atof(char *str)
{
    double result;
    int neg;
    int i;
    float is_after_comma = 0.0;

    neg = 1;
    result = 0;
    i = 0;
    while (str[i] && str[i] == ' ')
        i++;
    if (str[i] == '+' || str[i] == '-')
        if (str[i++] == '-')
            neg *= -1;
    while (str[i] && str[i] != '.' && str[i] >= 48 && str[i] <= 57)
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
    {
        i++;
        is_after_comma = 10.0;
    }
    else
        return (result * neg);
    while (str[i] && str[i] >= 48 && str[i] <= 57)
    {
        result += (str[i] - '0') / is_after_comma;
        is_after_comma *= 10;
        i++;
    }
    return (result * neg);
}
