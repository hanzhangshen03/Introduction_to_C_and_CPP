#include <stdlib.h>
#include <stdio.h>
#include "re.h"

arena_t create_arena(int size) { 
  arena_t arena = malloc(sizeof(arena_t));
  arena->current = 0;
  arena->size = size;
  arena->elts = malloc(size * sizeof(Regexp));
  return arena;
}

void arena_free(arena_t a) { 
  free(a->elts);
  free(a);
}

Regexp *re_alloc(arena_t a) { 
  if (a->current == a->size)
    return NULL;

  Regexp *new_regex = a->elts + a->current;
  a->current ++;

  return new_regex;
}

Regexp *re_chr(arena_t a, char c) { 
  Regexp *regex = re_alloc(a);
  if (regex != NULL) {
    regex->type = CHR;
    regex->data.chr = c;
  }
  return regex;
}

Regexp *re_alt(arena_t a, Regexp *r1, Regexp *r2) { 
  Regexp *regex = re_alloc(a);
  if (regex != NULL) {
    regex->type = ALT;
    regex->data.pair.fst = r1;
    regex->data.pair.snd = r2;
  }

  return regex;
}

Regexp *re_seq(arena_t a, Regexp *r1, Regexp *r2) { 
  Regexp *regex = re_alloc(a);
  if (regex != NULL) {
    regex->type = SEQ;
    regex->data.pair.fst = r1;
    regex->data.pair.snd = r2;
  }

  return regex;
}

int re_match(Regexp *r, char *s, int i) { 
  if (r != NULL) {
    int result;
    switch (r->type) {
      case CHR:
        if (r->data.chr == s[i])
          return i + 1;
        break;
      case SEQ:
        result = re_match(r->data.pair.fst, s, i);
        if (result >= 0)
          result = re_match(r->data.pair.snd, s, result);
        return result;
        break;
      case ALT:
        result = re_match(r->data.pair.fst, s, i);
        if (result >= 0)
          return result;
        result = re_match(r->data.pair.snd, s, i);
        if (result >= 0)
          return result;
        break;
    }
  }
  return -1;
}



void re_print(Regexp *r) { 
  if (r != NULL) { 
    switch (r->type) {
    case CHR: 
      printf("%c", r->data.chr);
      break;
    case SEQ:
      if (r->data.pair.fst->type == ALT) { 
	printf("(");
	re_print(r->data.pair.fst);
	printf(")");
      } else {
	re_print(r->data.pair.fst);
      }
      if (r->data.pair.snd->type == ALT) { 
	printf("(");
	re_print(r->data.pair.snd);
	printf(")");
      } else {
	re_print(r->data.pair.snd);
      }
      break;
    case ALT:
      re_print(r->data.pair.fst);
      printf("+");
      re_print(r->data.pair.snd);
      break;
    }
  } else { 
    printf("NULL");
  }
}    


      
  
