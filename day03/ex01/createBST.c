/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:27:53 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/06 20:52:01 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>


struct s_node *allocateNode(int nb) {

	struct s_node *n;
	if (!(n = malloc(sizeof(struct s_node))))
		return NULL;
	n->value = nb;
	n->left = NULL;
	n->right = NULL;
	return n;
}

// Pre-order Traversal to make the tree
struct s_node *constructTree(int *arr, int midIndex) {

	if (!midIndex)
		return NULL;
	int nodeIndex = midIndex / 2;
	struct s_node *n = allocateNode(arr[nodeIndex]);
	if (nodeIndex) {
		n->left = constructTree(arr, nodeIndex);
		// move arr to find the midpoint for the right
		// (nodeIndex + 1) the first is 5 (1 2 3 4 |-5-| 6 7 8 9 10)
		n->right = constructTree(arr + (nodeIndex + 1), midIndex - (nodeIndex + 1));
	}
	return n;
}

struct s_node *createBST(int *arr, int n) {

	if (!arr || n <= 0)
		return NULL;
	return constructTree(arr, n);
}
