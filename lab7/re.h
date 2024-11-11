#ifndef RE_H
#define RE_H 1 
#include <stdbool.h>

typedef struct re Regexp;
enum re_tag { CHR, SEQ, ALT };
struct re {
  enum re_tag type;
  union data { 
    char chr;
    struct { Regexp *fst; Regexp *snd; } pair;
  } data;
};


typedef struct arena *arena_t;
struct arena {
  int size;
  int current;
  Regexp *elts;
};

arena_t create_arena(int size);
Regexp *re_alloc(arena_t a);
void arena_free(arena_t a);

Regexp *re_chr(arena_t a, char c);
Regexp *re_alt(arena_t a, Regexp *r1, Regexp *r2);
Regexp *re_seq(arena_t a, Regexp *r1, Regexp *r2);

int re_match(Regexp *r, char *s, int i);

void re_print(Regexp *r);

#endif 
