#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

Node *empty = NULL;

Node *node(int value, Node *left, Node *right) { 
  Node *r = malloc(sizeof(Node));
  r->marked = false;
  r->value = value;
  r->left = left;
  r->right = right;
  return r;
}


/* Basic Problems */

int size(Node *node) { 
  if (node == NULL || node->marked)
    return 0;
  node->marked = true;
  int num_nodes = 1;
  if (node->left != NULL && !node->left->marked)
    num_nodes += size(node->left);
  if (node->right != NULL && !node->right->marked)
    num_nodes += size(node->right);
  return num_nodes;
}


void unmark(Node *node) { 
  if (node != NULL) {
    node->marked = false;
    if (node->left != NULL && node->left->marked)
      unmark(node->left);
    if (node->right != NULL && node->right->marked)
      unmark(node->right);
  }
}

bool path_from(Node *node1, Node *node2) {
  if (node1 == NULL || node2 == NULL || node1->marked)
    return false;
  node1->marked = true;
  if (node1 == node2)
    return true;
  return path_from(node1->left, node2) || path_from(node1->right, node2);
}

bool cyclic(Node *node) { 
  if (node != NULL)
    return path_from(node->left, node) || path_from(node->right, node);
  else
    return false;
} 


/* Challenge problems */

Node **get_nodes(Node *node, Node **dest) { 
  if (node == NULL || node->marked)
    return dest;
  
  node->marked = true;
  *dest = node;
  dest ++;
  dest = get_nodes(node->left, dest);
  dest = get_nodes(node->right, dest);
  return dest;
}

void graph_free(Node *node) { 
  int graph_size = size(node);
  Node **dest = (Node**) malloc(sizeof(Node*) * graph_size);
  dest = get_nodes(node, dest);
  for (int i = 0; i < graph_size; i++)
    free(dest[i]);
}


