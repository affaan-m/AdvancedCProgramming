#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define NTHREADS 10

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t evens_done = PTHREAD_COND_INITIALIZER;

int number_evens_finished = 0;
int counter = 0;
 
void* func1(void* data)
{
    int *x = (int *) data;
   
    pthread_mutex_lock( &lock); 

    if (*x % 2 == 0) {
       number_evens_finished++;
    }
    else {
       pthread_cond_wait(&evens_done, &lock);   
    }
  
    counter++;
    printf("message is %d, thread id = %lud modified the counter to %d\n", *x, pthread_self(), counter);
    printf("message is %d, thread id = %lud read the counter %d\n", *x, pthread_self(), counter); 
    
    pthread_mutex_unlock( &lock );        
}

int main(void)
{
   pthread_t thread_id[NTHREADS];
   int values[NTHREADS];

   for(int i=0; i < NTHREADS; i++) {
      values[i] = i;
      pthread_create( &thread_id[i], NULL, func1, &values[i]);
   }

   // NEED TO WAIT UNTIL ALL THREADS HAVE BEEN CREATED AND RUNNING (SO THAT ALL ODD THREADS ARE WAITING, BEFORE WE 
   // EVEN TRY TO SIGNAL  (OR THERE WILL BE A RACE CONDITION, RAN INTO THE PROBLEM OF SIGNALLING BEFORE ALL ODD THREADS WERE WAITING
   sleep(1);
   
   while(1) {
	if(number_evens_finished == NTHREADS / 2) {
	  pthread_cond_broadcast(&evens_done);
      break;
    }    
   }

   for(int j=0; j < NTHREADS; j++) {
      pthread_join( thread_id[j], NULL); 
      pthread_exit(&thread_id[j]);
   }
    
   return 0;
}


/*  SOLUTION USING TWO LOCKS AND RUNNING 1000 times */

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define NTHREADS 10000

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutext = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t evens_done = PTHREAD_COND_INITIALIZER;

int number_evens_finished = 0;

int counter = 0;
 
void* func1(void* data)
{
    int *x = (int *) data;
   
    pthread_mutex_lock( &condition_mutext ); 

    if (*x % 2 == 0) {
       number_evens_finished++;
    }
    else {
       pthread_cond_wait(&evens_done, &condition_mutext);   
    }
  
    pthread_mutex_unlock( &condition_mutext );

    pthread_mutex_lock( &lock ); 

    counter++;
    printf("message is %d, thread id = %lud modified the counter to %d\n", *x, pthread_self(), counter);
    printf("message is %d, thread id = %lud read the counter %d\n", *x, pthread_self(), counter); 
    
    pthread_mutex_unlock( &lock );        
}

int main(void)
{
   pthread_t thread_id[NTHREADS];
   int values[NTHREADS];

   for (int k = 0; k < 1000; k++) {
     for(int i=0; i < NTHREADS; i++) {
        values[i] = i;
        pthread_create( &thread_id[i], NULL, func1, &values[i]);
     }

     // NEED TO WAIT UNTIL ALL THREADS HAVE BEEN CREATED AND RUNNING (SO THAT ALL ODD THREADS ARE WAITING, BEFORE WE 
	 // EVEN TRY TO SIGNAL  (OR THERE WILL BE A RACE CONDITION, RAN INTO THE PROBLEM OF SIGNALLING BEFORE ALL ODD THREADS WERE WAITING
     sleep(1);

    while(1) {

	  if(number_evens_finished == NTHREADS / 2) {
	    pthread_cond_broadcast(&evens_done);
        break;
      }    
    }

     for(int j=0; j < NTHREADS; j++) {
        pthread_join( thread_id[j], NULL); 
     }

      number_evens_finished = 0;
   }

   for(int j=0; j < NTHREADS; j++) {
	pthread_exit(&thread_id[j]);
   }

   return 0;
}

