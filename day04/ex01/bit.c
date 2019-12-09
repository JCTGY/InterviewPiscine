/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:32:33 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/09 10:46:08 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

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

char *getAnd(char *a, char *b) {

	int aIndex = a[0] == '~' ? 1 : 0;
	int bIndex = b[0] == '~' ? 1 : 0;
	int newIndex = 0;
	char *new;

	if (!(new = malloc(sizeof(*new) * 4 + 1)))
		return NULL;
	new[4] = '\0';
	while (a[aIndex] && b[bIndex]) {

		if (a[aIndex] == b[bIndex])
			new[newIndex] = a[aIndex];
		else
			new[newIndex] = 0;
		aIndex++;
		bIndex++;
		newIndex++;
	}
	return new;
}


char *getOr(char *a, char *b) {
	
	int aIndex = a[0] == '~' ? 1 : 0;
	int bIndex = b[0] == '~' ? 1 : 0;
	int newIndex = 0;
	char *new;

	if (!(new = malloc(sizeof(*new) * 4 + 1)))
		return NULL;
	new[4] = '\0';
	while (a[aIndex] && b[bIndex]) {

		if (a[aIndex] || b[bIndex])
			new[newIndex] = a[aIndex];
		else
			new[newIndex] = 0;
		aIndex++;
		bIndex++;
		newIndex++;
	}
	return new;
}
