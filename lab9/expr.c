#include <stdlib.h>
#include <stdio.h>
#include "expr.h"

expr_t mkLit(int n) { 
  expr_t e = malloc(sizeof(struct expr));
  e->type = LIT;
  e->data.literal = n;
  return e;
}

expr_t mkPlus(expr_t e1, expr_t e2) { 
  expr_t e = malloc(sizeof(struct expr));
  e->type = PLUS;
  e->data.args.fst = e1;
  e->data.args.snd = e2;
  return e;
}

expr_t mkTimes(expr_t e1, expr_t e2) { 
  expr_t e = malloc(sizeof(struct expr));
  e->type = TIMES;
  e->data.args.fst = e1;
  e->data.args.snd = e2;
  return e;
}

void free_expr(expr_t e) { 
  if (e != NULL) { 
    switch (e->type) { 
    case LIT:
      free(e);
      break;
    case PLUS:
    case TIMES: {
      free_expr(e->data.args.fst);
      free_expr(e->data.args.snd);
      free(e);
      break;
    }
    default:
      break;
    }
  }
}

int eval_expr(expr_t e) { 
  switch (e->type) { 
  case LIT:
    return e->data.literal;
  case PLUS:
    return eval_expr(e->data.args.fst) + eval_expr(e->data.args.snd);
  case TIMES:
    return eval_expr(e->data.args.fst) * eval_expr(e->data.args.snd);
  default:
    return -1;
  }
}

void print_expr(expr_t e) { 
  switch (e->type) { 
    case LIT:
      printf("%d", e->data.literal);
      break;
    case PLUS: 
      printf("(");
      print_expr(e->data.args.fst);
      printf("+");
      print_expr(e->data.args.snd);
      printf(")");
      break;
    case TIMES: {
      printf("(");
      print_expr(e->data.args.fst);
      printf("*");
      print_expr(e->data.args.snd);
      printf(")");
      break;
    }
    default:
      break;
  }
}

