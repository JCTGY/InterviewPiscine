/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:34:12 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/04 21:51:19 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_queue *queueInit(void) {

	struct s_queue *q;
	if (!(q = malloc(sizeof(struct s_queue))))
		return NULL;
	q->first = NULL;
	q->last = NULL;
	return q;
}

char *dequeue(struct s_queue *queue) {
	struct s_node *tmp = queue->first;
	if (!tmp)
		return NULL;
	char *message = tmp->message;
	queue->first = queue->first->next;
	free(tmp);
	return message;
}

void enqueue(struct s_queue *queue, char *message) {

	struct s_node *n;
	if (!(n = malloc(sizeof(struct s_node))))
		return ;
	n->message = strdup(message);
	n->next = NULL;
	if (!queue->first) {
		queue->first = n;
		queue->last = n;
	}
	else {
		queue->last->next = n;
		queue->last = n;
	}
}

char *peek(struct s_queue *queue) {

	if (!queue->first)
		return NULL;
	return queue->first->message;
}

int isEmpty(struct s_queue *queue) {

	if (!queue->first)
		return 0;
	return 1;
}


