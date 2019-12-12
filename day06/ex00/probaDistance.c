/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:28:58 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/12 14:50:12 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

double checkDistance(int dist, int *arr, int current, int n) {

	double viable = 0;
	int i = current + 1;
	for (; i < n; i++) {

		if ((arr[i] - arr[current]) > dist) {
			viable++;
		}
	}
	return viable;
}

double probaDistance(int dist, int *arr, int n) {

	double total = 0;
	double viable = 0;
	for (int i = 0; i < n; i++) {

		viable += checkDistance(dist, arr, i, n);
		total = i ? total + (n - i) : total;
	}
	return (viable / total);
}
