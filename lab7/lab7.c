#include <stdio.h>
#include <stdlib.h>
#include "re.h"

int main(void) {
  char *strings[7] = {"ab", "xab", "abc", "xba", "xxx", "Hello, world", "axu"};
  Regexp *r[3];

  arena_t a = create_arena(128);
  r[0] = re_seq(a, re_chr(a, 'x'),
		re_alt(a, 
		       re_seq(a, re_chr(a, 'a'), re_chr(a, 'b')),
		       re_seq(a, re_chr(a, 'b'), re_chr(a, 'a'))));
  r[1] = re_seq(a, 
		re_alt(a, 
		       re_alt(a, re_chr(a, 'a'), re_chr(a, 'b')),
		       re_chr(a, 'c')),
		re_seq(a, 
		       re_alt(a, re_chr(a, 'x'), re_chr(a, 'y')),
		       re_alt(a, re_chr(a, 'u'), re_alt(a, re_chr(a, 'v'), 
							   re_chr(a, 'w')))));
  r[2] = re_seq(a, re_chr(a, 'H'), 
         re_seq(a, re_chr(a, 'e'), 
	 re_seq(a, re_chr(a, 'l'), 
	 re_seq(a, re_chr(a, 'l'),
	 re_seq(a, re_chr(a, 'o'),
	 re_seq(a, re_chr(a, ','),
         re_seq(a, re_chr(a, ' '),
	 re_seq(a, re_chr(a, 'w'),
	 re_seq(a, re_chr(a, 'o'),
         re_seq(a, re_chr(a, 'r'),
	 re_seq(a, re_chr(a, 'l'),
                   re_chr(a, 'd'))))))))))));

  for (int i = 0; i < 3; i++) { 
    printf("re = ");
    re_print(r[i]);
    printf("\n");

    for (int j = 0; j < 7; j++) { 
      printf("re matches \"%s\" = %d\n", 
	     strings[j], 
	     re_match(r[i], strings[j], 0));
    }
    printf("\n");
  }
  
  arena_free(a);
  return 0;
}

/* Expected correct output:

$ ./lab6 
re = x(ab+ba)
re matches "ab" = -1
re matches "xab" = 3
re matches "abc" = -1
re matches "xba" = 3
re matches "xxx" = -1
re matches "Hello, world" = -1
re matches "axu" = -1

re = (a+b+c)(x+y)(u+v+w)
re matches "ab" = -1
re matches "xab" = -1
re matches "abc" = -1
re matches "xba" = -1
re matches "xxx" = -1
re matches "Hello, world" = -1
re matches "axu" = 3

re = Hello, world
re matches "ab" = -1
re matches "xab" = -1
re matches "abc" = -1
re matches "xba" = -1
re matches "xxx" = -1
re matches "Hello, world" = 12
re matches "axu" = -1

*/
