/*2018년 1학기 운영체제 005반 숙제 3번
 *  * 성명 : 이건희, 학번 : 14011211*/

#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "prod_consum.h"

int insert_item(buffer_item item) {
	if(counter == BUFFER_SIZE)return -1;
	buffer[in] = item; 
	in = (in+1)%BUFFER_SIZE;
	counter++;
	return 0;
}

int remove_item(buffer_item *item) {
	if(counter == 0) return -1;

	*item = buffer[out];
	out = (out+1)%BUFFER_SIZE;
	counter--;
	return 0;
}
