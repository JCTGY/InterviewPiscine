/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:38:40 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/04 18:36:04 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct s_node *allocateNode(char c) {

	struct s_node *n;
	if (!(n = malloc(sizeof(struct s_node))))
			return NULL;
	n->prev = NULL;
	n->next = NULL;
	n->c = c;
	return n;
}

struct s_node *circleList(void) {

	const char *csString = CS;
	struct s_node *connect;
	struct s_node *first = NULL;
	struct s_node *prev = NULL;
	for (int i = 0; csString[i]; i++) {
		connect = allocateNode(csString[i]);
		if (first == NULL)
			first = connect;
		if (prev) {			
			connect->prev = prev;
			prev->next = connect;
		}
		prev = connect;
	}
	prev->next = first;
	first->prev = prev;
	return first;
}

char rotateChar(struct s_node **n, int index) {

	while (index != 0) {
		*n = index > 0 ? (*n)->next : (*n)->prev;
		index = index > 0 ? index - 1 : index + 1;
	}
	return (*n)->c;
}

char *precious(int *test, int size) {

	struct s_node *n = circleList();
	char *s;
	if (!(s = malloc(sizeof(*s) * size + 1)))
		return NULL;
	s[size] = '\0';
	for (int i = 0; i < size; i++) {
		s[i] = rotateChar(&n, test[i]);
	}
	return s;
}
