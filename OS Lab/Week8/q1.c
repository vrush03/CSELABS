#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
 
#define SHARED 1
sem_t empty, full;    /* the global semaphores */
int data;  
int numIters;
 
void *Producer(void *arg) {
  int produced;
  printf("Producer created\n");
for (produced = 0; produced < numIters; produced++) {
        sem_wait(&empty);
    data = produced;
    printf("Producer produced: %d\n", produced);
    sem_post(&full);
  }
}
 
/* fetch numIters items from the buffer and sum them */
void *Consumer(void *arg) {
  int total = 0, consumed;
  printf("Consumer created\n");
  for (consumed = 0; consumed < numIters; consumed++) {
    sem_wait(&full);
    total = total+data;
    printf("Consumed consumed: %d\n", consumed);
    sem_post(&empty);
  }
  printf("\nFor %d iterations, the total is %d\n", numIters, total);
}
 
int main() {
 
    int x = 0, y = 0;
 
    /* show the initial values of x and y */
    printf("x: %d, y: %d\n", x, y);
 
    /* this variable is our reference to the second thread */
    pthread_t pid, cid;
 
    printf("Enter the number of iterations:\n>");
    scanf("%d", &numIters);
 
    sem_init(&empty, SHARED, 1);  /* sem empty = 1 */
    sem_init(&full, SHARED, 0);   /* sem full = 0  */
 
    pthread_create(&pid, NULL, Producer, NULL);
    pthread_create(&cid, NULL, Consumer, NULL);
    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
 
   
    printf("Main done\n");
 
    return 0;
 
}