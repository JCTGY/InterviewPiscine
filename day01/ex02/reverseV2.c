/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:57:49 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/04 19:19:26 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct s_stack *stackInit(void) {
	
	struct s_stack *s;
	if (!(s = malloc(sizeof(struct s_stack))))
		return NULL;
	s->item = NULL;
	return s;
}

void *pop(struct s_stack *stack) {
	
	if (!stack->item)
		return NULL;
	struct s_item *tmp = stack->item;
	void *content = tmp->word;
	stack->item = tmp->next;
	free(tmp);
	return content;
}

void push(struct s_stack *stack, char *word) {

	struct s_item *n;
	if (!(n = malloc(sizeof(struct s_node))))
		return ;
	n->word = word;
	n->next = NULL;
	if (stack->item)
		n->next = stack->item;
	stack->item = n;
}

void printReverseV2(struct s_node *lst) {

	struct s_node *iter = lst;
	struct s_stack *s = stackInit();
	while (iter) {
		push(s, iter->word);
		iter = iter->next;
	}
	while (s->item) {
		if (s->item->next)
			printf("%s ", pop(s));
		else
			printf("%s", pop(s));
	}
	printf("\n");
}
