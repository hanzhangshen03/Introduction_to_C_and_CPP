#include <stdio.h>
#include <stdlib.h>
#include "expr.h"
#include "parse.h"

int main(int argc, char **argv) { 
  if (argc == 2) { 
    expr_t e; 
    int i = parse_expr(argv[1], 0, &e);
    if (i == -1) 
      printf("parse error\n");
    else {
      print_expr(e);
      printf(" = %d\n", eval_expr(e));
    }
    free_expr(e);
  } else { 
    printf("Expected 1 argument\n");
  }
  return 0;
}
	
