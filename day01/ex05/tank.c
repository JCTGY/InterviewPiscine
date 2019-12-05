/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 22:44:56 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/04 23:35:19 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_tank *initTank(void) {

	struct s_tank *tank;
	struct s_stack **s;

	if (!(tank = malloc(sizeof(struct s_tank))))
		return NULL;
	tank->n = 1;
	if (!(s = malloc(sizeof(struct s_stack *))))
		return NULL;
	tank->stacks = s;
	if (!(*s = malloc(sizeof(struct s_stack))))
		return NULL;
	(*s)->elem = NULL;
	(*s)->sum = 0;
	return tank;
}

void tankPrint(struct s_tank *tank) {

	int i = 0;
	while (i < tank->n) {
		if (i == 0)
			printf("%6s", "normal\n");
		else 
			printf("%6s%d\n", "nitrol: ", i);
		printf("______\n");
		printf("|%4d|\n", (tank->stacks)[i]->sum);
		printf("|    |\n\n");
		i++;
	}
}

void tankPush(struct s_tank *tank, int energy) {
	
	struct s_stack	**s;
	struct s_elem	*e;

	if (tank->stacks[tank->n - 1]->sum + energy > 1000)
	{
		if ((s = malloc(sizeof(struct s_stack *) * (tank->n + 1))) == NULL)
			return ;
		memmove(s, tank->stacks, sizeof(struct s_stack *) * (tank->n));
		tank->stacks = s;
		if ((tank->stacks[tank->n] = malloc(sizeof(struct s_stack))) == NULL)
			return ;
		tank->stacks[tank->n]->elem = NULL;
		tank->stacks[tank->n]->sum = 0;
		tank->n += 1;
	}
	if ((e = malloc(sizeof(struct s_elem))) == NULL)
		return ;
	e->next = tank->stacks[tank->n - 1]->elem;
	tank->stacks[tank->n - 1]->elem = e;
	e->energy = energy;
	tank->stacks[tank->n - 1]->sum += energy;
	printf("push(%d)\n", energy);
}

int tankPop(struct s_tank *tank)
{
	int		result;
	struct s_stack	*s;
	struct s_elem 	*e;

	s = tank->stacks[tank->n - 1];
	e = s->elem;
	if (e == NULL)
		return (0);
	result = e->energy;
	s->sum -= result;
	s->elem = s->elem->next;
	free(e);
	if (s->sum == 0 && tank->n > 1)
	{
		free(s);
		tank->n -= 1;
	}
	printf("pop()\n");
	return (result);
}
