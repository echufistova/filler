/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 20:33:54 by ychufist          #+#    #+#             */
/*   Updated: 2018/11/02 20:34:09 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int check_int_arr_equal(int **tab, int **tab2, int high, int length)
{
	int i;
	int j;

	i = 0;
	while (i < high)
	{
		j = 0;
		while (j < length)
		{
			if (tab[i][j] != tab2[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int **create_same_arr(int **tab, int high, int length)
{
	int **res;
	int i;
	int j;

	res = (int**)malloc(sizeof(int*) * high);
	i = 0;
	while (i < high)
	{
		j = 0;
		res[i] = (int*)malloc(sizeof(int) * length);
		while (j < length)
		{
			res[i][j] = tab[i][j];
			j++;
//			ft_printf("%d ", res[i][j]);
		}
//		ft_printf("\n");
		i++;
	}
	return (res);
}

int **create_arr(int high, int length)
{
	int **res;
	int i;
	int j;

	res = (int**)malloc(sizeof(int*) * high);
	i = 0;
	while (i < high)
	{
		j = 0;
		res[i] = (int*)malloc(sizeof(int) * length);
		while (j < length)
		{
			res[i][j] = 0;
			j++;
		}
		i++;
	}
	return (res);
}

void del_arr(int **tab, int high)
{
	int i;

	i = 0;
	while (i < high)
	{
		free(tab[i]);
		i++;
	}
}