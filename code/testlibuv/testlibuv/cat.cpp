#include "stdafx.h"
#include "cat.h"


 uv_fs_t open_req;
 uv_fs_t read_req;
 uv_fs_t write_req;


void on_write(uv_fs_t *req){
	if (req->result < 0){
		fprintf(stderr, "write error:%s\n", uv_strerror((int)req->result));
	}
	else{
		uv_fs_read(uv_default_loop(), &read_req, open_req.result, &iov, 1, -1, on_read);
	}
}

void on_read(uv_fs_t *req){
	if (req->result < 0){
		fprintf(stderr, "read error:%s\n", uv_strerror(req->result));
	}
	else if (req->result == 0){
		uv_fs_t close_req;
		uv_fs_close(uv_default_loop(), &close_req, open_req.result, NULL);
	}
	else if (req->result > 0){
		iov.len = req->result;
		uv_fs_write(uv_default_loop(), &write_req, 1, &iov, 1, -1, on_write);
	}
}

void on_open(uv_fs_t *req){
	assert(req == &open_req);

	if (req->result >= 0){
		iov = uv_buf_init(buffer, sizeof(buffer));
		uv_fs_read(uv_default_loop(), &read_req, req->result, &iov, 1, -1, on_read);
	}
	else{
		fprintf(stderr, "error opening file:%s\n", uv_strerror((int)req->result));
	}
}