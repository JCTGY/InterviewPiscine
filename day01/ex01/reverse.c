/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:41:52 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/04 18:53:02 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
void printReverse(struct s_node *lst) {

	if (lst) {
		printReverse(lst->next);
		if (lst->next)
			printf(" %s", lst->word);
		else
			printf("%s", lst->word);
	}
}
