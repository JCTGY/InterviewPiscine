/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:20:56 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/04 22:06:07 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct s_stack *initStack(void) {

	struct s_stack *s;
	if (!(s = malloc(sizeof(struct s_stack))))
		return NULL;
	s->item = NULL;
	return s;
}

int pop(struct s_stack *stack) {

	struct s_item *item;
	if (!stack->item)
		return 0;
	item = stack->item;
	stack->item = stack->item->next;
	return item->idx;
}

void push(struct s_stack *stack, int idx) {

	struct s_item *n;
	if (!(n = malloc(sizeof(struct s_item))))
		return ;
	n->idx = idx;
	n->next = stack->item;
	stack->item = n;
}

char *console(void) {

	char input[256];
	char *message;
	char *tmp;
	size_t msgLen;
	struct s_stack *s = initStack();

	bzero(input, 256);
	while (printf("?> ") && getline(&tmp, &msgLen, stdin)) {
		if (!strcmp(tmp, "UNDO\n") || !(strcmp(tmp, "UNDO"))) {
				msgLen = pop(s);
				input[strlen(input) - msgLen] = '\0';
				printf("%s\n", input);
		}
		else if (!strcmp(tmp, "SEND\n") || (!strcmp(tmp, "SEND"))) {
			msgLen = strlen(input);
			input[msgLen] = '\0';
			break ;
		}
		else {
			if (strlen(tmp) + strlen(input) < 256) {
				msgLen = (tmp[strlen(tmp) - 1] == '\n') ? strlen(tmp) - 1 : strlen(tmp);
				if (tmp[msgLen] == '\n')
					tmp[msgLen] = '\0';
				if (input[0]) {
					strcat(input, " ");
					msgLen++;
				}
				push(s, msgLen);
				strcat(input, tmp);
				printf("%s\n", input);
			}
		}
	}
	if (!(message = malloc(sizeof(*message) * strlen(input) + 1)))
		return NULL;
	message[strlen(input)] = '\0';
	strcpy(message, input);
	return message;
}
