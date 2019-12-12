/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:32:51 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/11 10:51:03 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void slicePizza(struct s_array *arr, int size) {

	for (int i = size; i > 0; i--) {
		struct s_array *tmp = arrayClone(arr);
		arrayAppend(tmp, i);
		if (tmp->sum <= size) {
			if (tmp->sum == size)
				arrayPrint(tmp);
			else 
				slicePizza(tmp, size);
		}
		tmp->content = NULL;
		free(tmp);
	}
}

void printPossibleSlices(int pizzaSize) {

	struct s_array *arr = arrayInit();
	slicePizza(arr, pizzaSize);
	arr->content = NULL;
	free(arr);

	while (1) {}
}
