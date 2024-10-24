#include <stdlib.h>
#include "expr.h"
#include "parse.h"

int parse_int(char *s, int i, expr_t *result) { 
  int acc;
  if (s[i] >= '0' && s[i] <= '9') { 
    acc = s[i] - '0';
    i++;
  } else { 
    *result = NULL;
    return -1;
  }
  while (s[i] >= '0' && s[i] <= '9') {
    acc = acc * 10 + (s[i] - '0');
    i++;
  } 
  *result = mkLit(acc);
  return i;
}

int parse_atom(char *s, int i, expr_t *result) { 
  if (s[i] >= '0' && s[i] <= '9') { 
    return parse_int(s, i, result);
  } else if (s[i] == '(') { 
    i++;
    i = parse_expr(s, i, result);
    if (s[i] == ')') { 
      return i+1;
    } else { 
      free_expr(*result);
      *result = NULL;
      return -1;
    }
  } else { 
    return -1;
  }
}

int parse_term(char *s, int i, expr_t *result) { 
  expr_t e;
  i = parse_atom(s, i, &e);
  if (i == -1) {
    *result = NULL;
    return -1;
  }
  while (s[i] == '*') { 
    i++;
    expr_t e2;
    i = parse_atom(s, i, &e2);
    if (i == -1) { 
      free(e);
      *result = NULL;
      return -1;
    } else { 
      e = mkTimes(e, e2);
    }
  }
  *result = e;
  return i;
}

int parse_expr(char *s, int i, expr_t *result) { 
  expr_t e;
  i = parse_term(s, i, &e);
  if (i == -1) {
    *result = NULL;
    return -1;
  }
  while (s[i] == '+') { 
    i++;
    expr_t e2;
    i = parse_term(s, i, &e2);
    if (i == -1) { 
      free(e);
      *result = NULL;
      return -1;
    } else { 
      e = mkPlus(e, e2);
    }
  }
  *result = e;
  return i;
}

int parse(char *s, int i, expr_t *result) {
  expr_t e; 
  int j = parse_expr(s, i, &e);
  if (j != -1 && s[j] != '\0') { 
    free_expr(e);
    *result = NULL;
    return -1;
  } else { 
    *result = e;
    return j;
  }
}
  
