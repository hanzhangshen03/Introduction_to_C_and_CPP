#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

Tree *empty = NULL;

/* BASE EXERCISE */

int tree_member(int x, Tree *tree) { 
  if (tree != NULL) {
    if (tree->value == x)
      return 1;
    else
      return tree_member(x, tree->left) || tree_member(x, tree->right);
  }
  return 0;
}

Tree *tree_insert(int x, Tree *tree) { 
  if (tree == NULL) {
    Tree *new_node = (Tree *)malloc(sizeof(Tree));
    new_node->value = x;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }
  else {
    if (tree->value < x)
      tree->right = tree_insert(x, tree->right);
    else
      tree->left = tree_insert(x, tree->left);
    return tree;
  }
}

void tree_free(Tree *tree) { 
  if (tree != NULL) {
    tree_free(tree->left);
    tree_free(tree->right);
    free(tree);
  }
}

void print_tree(Tree *tree) {
  if (tree != NULL) {
    printf("%d\n", tree->value);
    print_tree(tree->left);
    print_tree(tree->right);
  }
}

/* CHALLENGE EXERCISE */ 

void pop_minimum(Tree *tree, int *min, Tree **new_tree) { 
  if (tree->left == NULL) {
    *min = tree->value;
    *new_tree = tree->right;
  }
  else {
    pop_minimum(tree->left, min, new_tree);
    tree->left = *new_tree;
    *new_tree = tree;
  }
}

Tree *tree_remove(int x, Tree *tree) { 
  if (tree != NULL) {
    if (tree->value == x) {
      if (tree->right == NULL && tree->left == NULL)
        return NULL;
      else if (tree->right == NULL)
        return tree->left;
      else {
        Tree **new_tree = (Tree **)malloc(sizeof(Tree *));
        int *min = (int *)malloc(sizeof(int));
        pop_minimum(tree->right, min, new_tree);
        tree->value = *min;
        tree->right = *new_tree;
      }
    }
    else if (tree->value < x)
      tree_remove(x, tree->right);
    else
      tree_remove(x, tree->left);
  }
  return tree;
}
