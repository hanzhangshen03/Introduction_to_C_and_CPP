#include <ctype.h>
#include <string.h>
#include "revwords.h"
#include <stdio.h>

void reverse_substring(char str[], int start, int end) {
  char tmp;
  for (; start < end; start ++, end --) {
    tmp = str[start];
    str[start] = str[end];
    str[end] = tmp;
  }
}


int find_next_start(char str[], int len, int i) { 
  for (int j = i; j < len; j++) {
    if ((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z')) {
      return j;
    }
  }
  return -1;
}

int find_next_end(char str[], int len, int i) {
  for (int j = i + 1; j < len; j++)
    if (!((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z')))
      return j;
  return len;
}

void reverse_words(char s[]) { 
  int len = strlen(s);
  int i = 0;
  while (i < len) {
    int word_start = find_next_start(s, len, i);
    if (word_start == -1)
      return;
    int word_end = find_next_end(s, len, i);
    reverse_substring(s, word_start, word_end - 1);
    i = word_end;
  }
}
