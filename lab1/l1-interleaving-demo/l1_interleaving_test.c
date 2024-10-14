
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUMTHREADS 4
char *threadstr = "Thread";

void *threadfn(void *ptr) {
  int threadnum = (int) ptr;
  // Try it also with the next line commented out.
  sleep(rand() % 2); // Sleep 0 or 1 seconds
  printf("%s %d\n", threadstr, threadnum);
  return 0;
}

void main(void) {
  pthread_t threads[NUMTHREADS];  // Thread IDs

  for (int i = 0; i < NUMTHREADS; i++) pthread_create(&threads[i], 0, threadfn, (void *)i);
  for (int i = 0; i < NUMTHREADS; i++) pthread_join(threads[i], 0);
}

// eof
