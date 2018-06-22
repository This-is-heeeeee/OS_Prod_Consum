/*2018년 1학기 운영체제 005반 숙제 3번
 *  * 성명 : 이건희, 학번 : 14011211*/

#include <pthread.h>
#include <semaphore.h>

/* number of producer */
int NUM_OF_PRODUCER;

/* number of consumer */
int NUM_OF_CONSUMER;

/* time of sleep */
int sleeptime;

/* semaphores and mutex lock */
pthread_mutex_t 	mutex_lock;

/* semaphore declarations */
sem_t	 full;
sem_t	 empty;

/* buffer definition */
typedef int buffer_item;
#define BUFFER_SIZE 5
buffer_item buffer[BUFFER_SIZE];

/* buffer  variable */
int counter;
int in;
int out;

/* buffer funcrion prototype */
int insert_item(buffer_item item);
int remove_item(buffer_item *item);

/* producer function prototype */
void *prod_loop(void *param);

/* consumer founction prototype */
void *consum_loop(void *param);
