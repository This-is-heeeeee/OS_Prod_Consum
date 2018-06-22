/*2018년 1학기 운영체제 005반 숙제 3번
 *  * 성명 : 이건희, 학번 : 14011211*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "prod_consum.h"
#include <errno.h>

void *prod_loop(void *param) {
	buffer_item item;
	
	while(1) {
		int t = rand()/500000000;
		sleep(t);
		item = rand();
		
		if(sem_wait(&empty) != 0) printf("%s\n",strerror(errno));//empty--
		if(pthread_mutex_lock(&mutex_lock) != 0) printf("%s\n",strerror(errno));//
		
		if(insert_item(item))
			fprintf(stderr,"report error condition");
		else {
			printf("producer produced %d\n", item);
		}		
		if(pthread_mutex_unlock(&mutex_lock) != 0) printf("%s\n", strerror(errno));
		if(sem_post(&full) != 0) printf("%s\n", strerror(errno));//full++
	}
}

void *consum_loop(void *param) {
	buffer_item item;

	while(1) {
		int t = rand()/500000000;
		sleep(t);
		
		if(sem_wait(&full) != 0) printf("%s\n",strerror(errno));//full--
		if(pthread_mutex_lock(&mutex_lock) != 0) printf("%s\n",strerror(errno));
		
		if(remove_item(&item))
			fprintf(stderr,"report error condition");
		else
			printf("consumer consumed %d\n", item);
		
		if(pthread_mutex_unlock(&mutex_lock) != 0) printf("%s,\n", strerror(errno));
		if(sem_post(&empty) != 0) printf("%s\n",strerror(errno));//empty++
	}
}
