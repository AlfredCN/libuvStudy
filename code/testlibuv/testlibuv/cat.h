#ifndef _CAT_H__
#define _CAT_H__

#include "stdafx.h"
#include <assert.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <process.h>
#include <uv.h>

void on_read(uv_fs_t *req);
void on_write(uv_fs_t *req);
void on_open(uv_fs_t *req);

 extern uv_fs_t open_req;
 extern uv_fs_t read_req;
 extern uv_fs_t write_req;

static char buffer[1024];

static uv_buf_t iov;

#endif // _CAT_H__