#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

// Return a dag representing a complete binary tree of height n+1
//
Node *make_dag(int n) { 
  Node* nodes[n + 1];
  for (int i = 0; i < n + 1; i++) { 
    nodes[i] = node(i, NULL, NULL);
  }
  for (int i = 0; i < n; i++) { 
    nodes[i]->left = nodes[i+1];
    nodes[i]->right = nodes[i+1];
  }
  return nodes[0];
}

Node *make_cyclic(int n) { 
  Node* nodes[n + 1];
  for (int i = 0; i < n + 1; i++) { 
    nodes[i] = node(i, NULL, NULL);
  }
  for (int i = 0; i < n; i++) { 
    if (i % 2) { 
      nodes[i]->left = nodes[i+1];
      nodes[i]->right = nodes[0];
    } else { 
      nodes[i]->left = nodes[0];
      nodes[i]->right = nodes[i+1];
    }
  }
  return nodes[0];
}

int main(void) { 
  setbuf(stdout, NULL);

  Node *graph1 = make_dag(4);
  Node *graph2 = make_cyclic(4);

  printf("Size of graph1 = %d\n", size(graph1));
  printf("Size of graph1 pre-unmarking = %d\n", size(graph1));
  unmark(graph1);
  printf("Size of graph1 post-unmarking = %d\n", size(graph1));
  unmark(graph1);
  printf("cyclic(graph1) = %d\n", cyclic(graph1));

  printf("Size of graph2 = %d\n", size(graph2));
  printf("Size of graph2 pre-unmarking = %d\n", size(graph2));
  unmark(graph2);
  printf("Size of graph2 post-unmarking = %d\n", size(graph2));
  unmark(graph2);
  printf("cyclic(graph2) = %d\n", cyclic(graph2));

  /* Challenge problem */

  unmark(graph1);
  unmark(graph2);
  // printf("size(graph1) = %d\n", size(graph1));
  graph_free(graph1);
  printf("Freed graph1\n");
  graph_free(graph2);
  printf("Freed graph2\n");

  return 0;
}

/* 

The expected output, not including the challenge, is:

$ ./lab5 
Size of graph1 = 5
Size of graph1 pre-unmarking = 0
Size of graph1 post-unmarking = 5
cyclic(graph1) = 0
Size of graph2 = 5
Size of graph2 pre-unmarking = 0
Size of graph2 post-unmarking = 5
cyclic(graph2) = 1


The expected output, including the challenge, is:

$ ./lab5 
Size of graph1 = 5
Size of graph1 pre-unmarking = 0
Size of graph1 post-unmarking = 5
cyclic(graph1) = 0
Size of graph2 = 5
Size of graph2 pre-unmarking = 0
Size of graph2 post-unmarking = 5
cyclic(graph2) = 1
Freed graph1
Freed graph2

*/
