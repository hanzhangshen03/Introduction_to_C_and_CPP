#ifndef PARSE_H
#define PARSE_H 1

#include "expr.h"

int parse_int(char *s, int i, expr_t *result);
int parse_atom(char *s, int i, expr_t *result);
int parse_term(char *s, int i, expr_t *result);
int parse_expr(char *s, int i, expr_t *result);
int parse(char *s, int i, expr_t *result);

#endif
