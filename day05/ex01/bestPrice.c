/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:11:38 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/11 15:05:42 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void calculateBestPrice(int pizzaSize, double *prices, int currentSize, double *max, double currentPrice) {

	for (int i = pizzaSize; i > 0; i--) {
		currentSize += i;
		currentPrice += prices[i];
		if (currentSize <= pizzaSize) {
			if (currentSize == pizzaSize) {
				if (currentPrice > *max)
					*max =currentPrice;
			}
			else 
				calculateBestPrice(pizzaSize, prices, currentSize, max, currentPrice);
		}
		currentSize -= i;
		currentPrice -= prices[i];
	}
}

double bestPrice(int pizzaSize, double *prices) {

	double max = 0.0f;
	calculateBestPrice(pizzaSize, prices, 0, &max, 0);
	return max;
}
