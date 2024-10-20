#ifndef TREE_H
#define TREE_H 1

struct node {
  struct node *left;
  int value;
  struct node *right;
};
typedef struct node Tree;

/* Basic problems */

extern Tree *empty;

int tree_member(int x, Tree *tree);

Tree *tree_insert(int x, Tree *tree);

void tree_free(Tree *tree);

/* Challenge problems */

void pop_minimum(Tree *tree, int *min, Tree **new_tree);

Tree *tree_remove(int x, Tree *tree);

#endif 
