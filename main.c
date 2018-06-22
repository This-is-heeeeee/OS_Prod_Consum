/*2018년 1학기 운영체제 005반 숙제 3번
 * 성명 : 이건희, 학번 : 14011211*/
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>
#include "prod_consum.h"

pthread_t *prod;
pthread_t *consum;

void init() {
	if(pthread_mutex_init(&mutex_lock, NULL) != 0) printf("%s\n", strerror(errno));
	/* full == BUFFER_SIZE : MAX*/
	if(sem_init(&full, 0, 0) == -1) printf("error init\n");
	/*empty == 0 : MAX*/
	if(sem_init(&empty, 0, BUFFER_SIZE) == -1) printf("error init\n");;
	
	/* set variable for buffer*/
	counter = 0; in = 0; out = 0;

}

void create_producers() {
	int p;
	for(p = 0; p < NUM_OF_PRODUCER; p++)
		pthread_create(&prod[p],0,prod_loop,0);
}

void create_consumers() {
	int c;
	for(c = 0; c < NUM_OF_CONSUMER; c++)
		pthread_create(&consum[c],0,consum_loop,0);
	
}

int main(int argc, char **argv) {
	
	if(argc<3) {
		 printf("Usage : <TIME_FOR_SLEEP> <NUM_OF_RODUCER> <NUM_OF_CONSUMER>\n");
		 return 0;
	}
	
	sleeptime = atoi(argv[1]);
	NUM_OF_PRODUCER = atoi(argv[2]);
	NUM_OF_CONSUMER = atoi(argv[3]);
	
	prod = (pthread_t*)malloc(sizeof(pthread_t)*NUM_OF_PRODUCER);
	consum = (pthread_t*)malloc(sizeof(pthread_t)*NUM_OF_CONSUMER);
	init();
	int c,p;
	/*쓰레드 생성*/
	create_producers();
	create_consumers();
	
	sleep(sleeptime);

	free(prod);
	free(consum);
	
	return 0;	
}

