/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:53:56 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/09 10:30:58 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

char *getSum(char *a, char *b) {

	int i = 5;
	int incretment = 0;
	int tmp = 0;
	while (i >= 0) {

		tmp = (a[i] - '0') + (b[i] - '0') + incretment;
		if (tmp >= 2) {
			incretment = 1;
			tmp =  tmp % 2;
		}
		else 
			incretment = 0;
		a[i] = tmp + '0';
		i--;
	}
	return a;
}

int toInt(char *bits) {

	int num = 0;
	int power = 1;
	int len = strlen(bits) - 1;

	while (len >= 0) {

		num += (power * (bits[len] - '0'));
		power *= 2;
		len--;
	}
	return num;
}
