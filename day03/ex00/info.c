/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:26:21 by jchiang-          #+#    #+#             */
/*   Updated: 2019/12/05 16:48:24 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>

int getTreeMinSize(struct s_node *root) {

	if (!root)
		return 0;
	if (!root->right && !root->left)
		return 1;
	if (!root->right)
		return (getTreeMinSize(root->left) + 1);
	if (!root->left)
		return (getTreeMinSize(root->right) + 1);
	return min(getTreeMinSize(root->left), getTreeMinSize(root->right)) + 1;
}

int getTreeMaxSize(struct s_node *root) {

	if (!root)
		return 0;
	else 
	{
		int maxRight = getTreeMaxSize(root->right) + 1;
		int maxLeft = getTreeMaxSize(root->left) + 1;
		return max(maxRight, maxLeft);
	}
}

int getTreeElement(struct s_node *root) {

	int sum = 1;
	int sumRight = 0;
	int sumLeft = 0;
	if (!root)
		return 0;
	if (root->right) {
		sumRight = getTreeElement(root->right);
		sum += sumRight;
	}
	if (root->left) {
		sumLeft = getTreeElement(root->left);
		sum += sumLeft;
	}
	return sum;
}

struct s_info getInfo(struct s_node *root) {

	struct s_info info;

	info.min = getTreeMinSize(root);
	info.max = getTreeMaxSize(root);
	info.elements = getTreeElement(root);
	return info;
}
