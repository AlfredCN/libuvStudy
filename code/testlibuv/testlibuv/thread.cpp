#include "stdafx.h"
#include "thread.h"

void hare(void *arg){
	int tracklen = *((int*)arg);
	while (tracklen){
		tracklen--;
		Sleep(1000);
		fprintf(stderr, "hare ran another step\n");
	}

	fprintf(stderr, "hare done running!\n");
}

void tortoise(void *arg){
	int tracklen = *((int*)arg);
	while (tracklen){
		tracklen--;
		fprintf(stderr, "tortoise ran another step\n");
		Sleep(3000);
	}
	fprintf(stderr, "tortoise done running!\n");
}

void callthread(){
	int tracklen = 10;
	uv_thread_t hare_id;
	uv_thread_t tortoise_id;

	uv_thread_create(&hare_id, hare, &tracklen);
	uv_thread_create(&tortoise_id, tortoise, &tracklen);

	uv_thread_join(&hare_id);
	uv_thread_join(&tortoise_id);
}