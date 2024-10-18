#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *cons(int head, List *tail) { 
  /* malloc() will be explained in the next lecture! */
  List *cell = malloc(sizeof(List));
  cell->head = head;
  cell->tail = tail;
  return cell;
}

/* Functions for you to implement */

int sum(List *list) {
  int total = 0;
  while (list != NULL) {
    total += list->head;
    list = list->tail;
  }
  return total;
}

void iterate(int (*f)(int), List *list) {
  while(list != NULL) {
    list->head = (*f)(list->head);
    list = list->tail;
  }
}

void print_list(List *list) { 
  if (list != NULL) {
    printf("[%d", list->head);
    list = list->tail;
  }
  else
    printf("[");
  while (list != NULL) {
    printf(", %d", list->head);
    list = list->tail;
  }
  printf("]\n");
}

/**** CHALLENGE PROBLEMS ****/

List *merge(List *list1, List *list2) { 
  List *tmp;
  List *start;
  if (list1->head > list2->head) {
    tmp = list1;
    list1 = list2;
    list2 = tmp;
  }
  start = list1;

  while (list1->tail != NULL) {
    list1 = list1->tail;
    if (list1->head > list2->head) {
      tmp = list1;
      list1->tail = list2;
      list2 = list2->tail;
      list1 = list1->tail;
      list1->tail = tmp;
    }
    if (list2 == NULL)
      return start;
  }
  list1->tail = list2;
  return start;
}

void split(List *list, List **list1, List **list2) { 
  int i = 0;
  List *list_one, *list_two;
  list_one = NULL;
  list_two = NULL;
  while (list != NULL) {
    if (i % 2 == 0)
      list_one = cons(list->head, list_one);
    else
      list_two = cons(list->head, list_two);
    list = list->tail;
    i++;
  }
  *list1 = list_one;
  *list2 = list_two;
}

/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */

List *merge_sort(List *list) { 
  if (list == NULL || list->tail == NULL) { 
    return list;
  } else { 
    List *list1;
    List *list2;
    split(list, &list1, &list2);
    list1 = merge_sort(list1);
    list2 = merge_sort(list2);
    return merge(list1, list2);
  }
}
