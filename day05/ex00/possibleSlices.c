/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:32:51 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/10 21:33:45 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int combinationNum(int pizzaSize) {

	int combine = 1;
	for (int i = 1; i <= pizzaSize; i++) {
		combine *= i;
	}
	return combine;
}

void rerangeNum(struct s_array *arr, struct s_array *copy) {


}

void printPossibleSlices(int pizzaSize) {

	int combine = combinationNum(pizzaSize);
	printf("combine = %d\n", combine);
	struct s_array *arr = arrayInit();
	arrayAppend(arr, 15);
	arrayAppend(arr, 10);
	arrayPrint(arr); //print ’[15, 10]\n’
	struct s_array *copy = arrayClone(arr);
	printf("length: %d, sum: %d\n", arr->length, arr->sum); //print ’length: 2, sum: 25\n’
	printf("campacitty: %d", arr->capacity); //print ’length: 2, sum: 25\n’
	
}
