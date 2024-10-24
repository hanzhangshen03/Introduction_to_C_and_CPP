#ifndef EXPR_H
#define EXPR_H 1 

typedef enum type {LIT, PLUS, TIMES} expr_type;
typedef struct expr * expr_t;

struct expr { 
  expr_type type;
  union { 
    int literal;
    struct pair {
      expr_t fst;
      expr_t snd;
    } args;
  } data;
};

expr_t mkLit(int n);
expr_t mkPlus(expr_t e1, expr_t e2);
expr_t mkTimes(expr_t e1, expr_t e2);

expr_t copy_expr(expr_t e);

int eval_expr(expr_t e);
void print_expr(expr_t e);

void free_expr(expr_t e);

#endif
