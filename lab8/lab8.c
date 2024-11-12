#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "matrix.h"

void matrix_test(void) { 
  matrix_t m1 = matrix_create(3, 5);
  for (int i = 0; i < m1.rows; i++) { 
    for (int j = 0; j < m1.cols; j++) { 
      matrix_set(m1, i, j, i - j);
    }
  }
  matrix_print(m1);
  matrix_t m2 = matrix_transpose(m1);
  matrix_print(m2);
  matrix_t m3 = matrix_create(5, 2); 
  for (int i = 0; i < m3.rows; i++) { 
    for (int j = 0; j < m3.cols; j++) { 
      matrix_set(m3, i, j, i - j);
    }
  }
  matrix_print(m3);

  matrix_t m4 = matrix_multiply(m1, m3);
  matrix_print(m4);

  matrix_t m5 = matrix_transpose(m3);
  matrix_print(m5);

  matrix_t m6 = matrix_multiply_transposed(m1, m5);
  matrix_print(m6);
}
/* Expected result of matrix_test():
0	-1	-2	-3	-4	
1	0	-1	-2	-3	
2	1	0	-1	-2	

0	1	2	
-1	0	1	
-2	-1	0	
-3	-2	-1	
-4	-3	-2	

0	-1	
1	0	
2	1	
3	2	
4	3	

-30	-20	
-20	-15	
-10	-10	

0	1	2	3	4	
-1	0	1	2	3	

-30	-20	
-20	-15	
-10	-10	
*/
 

typedef matrix_t (*multiplier)(matrix_t m1, matrix_t m2); 

void time_it(multiplier f, matrix_t m1, matrix_t m2, char *msg) { 
  clock_t start = clock();
  (*f)(m1, m2);  // It doesn't matter for this exercise,
		 // but do you see the memory leak? 
  clock_t end = clock();
  clock_t diff = end - start;
  printf("%s: %ld microseconds\n", msg, diff);
}

int main(void) { 
  matrix_test();
  /* Once you get the expected output for matrix_test(), run this 
     code to see which matrix multiplication routine is faster. */
  matrix_t m1 = matrix_create(500, 500);
  matrix_t m2 = matrix_create(500, 500);
  time_it(matrix_multiply, m1, m2, "matrix_multiply");
  time_it(matrix_multiply_fast, m1, m2, "matrix_multiply_fast");
  return 0;
}
