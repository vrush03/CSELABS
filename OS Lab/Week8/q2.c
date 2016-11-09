#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int produced_so_far = 0;
int bytes_to_read = 0;
 

int in_mrkr;                    
int out_mrkr;                  

sem_t empty;                       
sem_t full;                      

pthread_mutex_t mutex;            

void rand_str(char *dest, size_t length) {
    char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (length-- > 0) {
        size_t index = (double) rand() / RAND_MAX * (strlen(charset));
        *dest++ = charset[index];
    }
    *dest = '\0';
}

void buffer_init(void) {
  
   
    if (sem_init(&empty, 0, PIPE_BUF)) {
        fprintf(stderr, "Error initializing \"empty\" semaphore.\n");
        exit(1);
    }
 
    if (sem_init(&full, 0, 0)) {
        fprintf(stderr, "Error initializing \"full\" semaphore.\n");
        exit(1);
    }
 
   
    if (pthread_mutex_init(&mutex, NULL)) {
        fprintf(stderr, "Error initializing mutex lock.\n");
        exit(1);
    }
}
 
void * insert_item(void *arg) {

    int thread_number = *(int *)arg;
    int i = 0;
    int fd;
    int bytes_to_write;
    
  
    if((fd = open("data", O_WRONLY)) < 0) {
        perror("open");
        exit(1);
    }
    
    for (i; i < 5; i++) {
        
      
        sem_wait(&empty);
     
        
        pthread_mutex_lock(&mutex);
        
        //--- PRODUCER CRITICAL SECTION ---
        /* add string to FIFO */
        bytes_to_write = (1 + rand() % 4); 
        char *buf = malloc(bytes_to_write);
        rand_str(buf, bytes_to_write);
        if((write(fd, buf, bytes_to_write)) < 0) {
            perror("write");
            exit(1);
        }
        bytes_to_read += bytes_to_write;
        produced_so_far += strlen(buf);
        printf("Producer: \"%s\" (%d)\n", buf, produced_so_far);
        free(buf);
     
        /* release the lock on the producer thread */
        pthread_mutex_unlock(&mutex);
     
        /* increment full semaphore to indicate buffer has a filled slot */
        sem_post(&full);
    }
    //close(fd);
     pthread_exit(NULL);
    //return 0; 
}
 
void * remove_item(void *arg) {

    int fd;
    int thread_number = *(int *)arg;
    int count = 0;
    char *buf;
    int num_bytes_read;
    if((fd = open("data", O_RDONLY)) < 0) {
        perror("read");
        exit(1);
    }    
    
    while(1) {
        /* decrement full semaphore for consumer */
        sem_wait(&full);
     
        /* lock thread so consumer can consume item from FIFO */
        pthread_mutex_lock(&mutex);
     
        //--- CONSUMER CRITICAL SECTION ---
        /* Remove an item from the FIFO */
        if (bytes_to_read > 0) {
            buf = malloc(bytes_to_read + 1);
            num_bytes_read = read(fd, buf, bytes_to_read);
             if(num_bytes_read < 0) {
                perror("read");
                exit(1);
            }
            else if(num_bytes_read == 0) {
                pthread_mutex_unlock(&mutex);
                pthread_exit(NULL);
                close(fd);
                return 0;
            }
            *(buf + bytes_to_read) = '\0';
            printf("Consumer: \"%s\"\n", buf);
            bytes_to_read = 0;
        }
        
        
        /* release the lock on the consumer thread */
        pthread_mutex_unlock(&mutex);
        pthread_exit(NULL);
     
        /* increment empty semaphore to inidicate FIFO has an empty slot */
        if (sem_post(&empty)) {
            perror("sem_post");
            exit(1);
        }
     }
     pthread_exit(NULL);
    return 0;   
}

int main (int argc, char *argv[]) {

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <FIFO-Name> <Number-Producers> <Number-Consumers>\n", argv[0]);
        exit (1);
    }
    struct stat stat_buf;

    int num_producers = atoi(argv[2]);
    int num_consumers = atoi(argv[3]);
    int s;
    pthread_t producers[num_producers];
    pthread_t consumers[num_consumers];
    int bytes_to_write;
    int fd_w;
    int fd_r;
    int t_error;
    int i;
    mode_t mode = 0777;
    srand(time(NULL));
    buffer_init();

    
    // If file doesn't exist, create it as a FIFO
    if (s = stat(argv[1], &stat_buf)) {
        if((mkfifo("data", mode)) < 0) {
            perror("mkfifo");
            exit(1);
        }
        else {
            printf("Data FIFO created.\n");
        }
    }
    else if (!S_ISFIFO(stat_buf.st_mode)) {
        fprintf(stderr, "%s exists, but is not a legit FIFO.\n", argv[1]);
        exit(1);
    }
    else {
        printf("The file \"%s\" exists and is a FIFO. Let's use it.\n", argv[1]);
    }
    
    for (i = 0; i < num_producers; i++) {
        if (t_error = pthread_create(&producers[i], NULL, insert_item, &i)) {
            perror("ptrhead_create");
            exit(1);
        }
    }

    for (i = 0; i < num_consumers; i++) {    
        if (t_error = pthread_create(&consumers[i], NULL, remove_item, &i)) {
            perror("ptrhead_create");
            exit(1);
        }
    }    
    /* Wait for the producer thread(s) to finish before terminating. */
    for (i = 0; i < num_producers; i++) {    
        if (t_error = pthread_join(producers[i], NULL)) {
            perror("pthread_join");
            exit(1);
        }
    }
    
    /* Wait for the consumer thread(s) to finish before terminating. */
    for (i = 0; i < num_consumers; i++) {    
        if (t_error = pthread_join(consumers[i], NULL)) {
            perror("pthread_join");
            exit(1);
        }
    }
    return 0;
}