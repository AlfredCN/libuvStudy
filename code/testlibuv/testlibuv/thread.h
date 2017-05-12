#ifndef _THREAD_H__
#define _THREAD_H__
#include "stdafx.h"
#include <stdio.h>
#include <process.h>
#include <io.h>
#include <uv.h>

	void hare(void * arg);
	void tortoise(void * arg);
	void callthread();


#endif // _THREAD_H__