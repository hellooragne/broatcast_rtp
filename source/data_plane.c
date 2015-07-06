#include<sys/time.h>

#include "data_plane.h"
#include "hashmap.h"

typedef struct {
	uint32_t port_start;
	uint32_t port_end;
} data_plane_port_range_t;


static data_plane_port_range_t data_plane_port_range;

static data_plane_media_sdp_t data_plane_sender_context;
//static data_plane_media_sdp_t data_plane_receiver_context[60];

static hmap_t data_plane_receiver_map;

static void i64toa(uint64_t in, uint8_t *out) {
	sprintf(out, "%10lld", in);
}

int data_plane_init(uint32_t rtp_port_start, uint32_t rtp_port_end) {
	data_plane_port_range.port_start = rtp_port_start;
	data_plane_port_range.port_end = rtp_port_end;
	data_plane_receiver_map = hashmap_create();
}

const data_plane_media_sdp_t *data_plane_add_sender(sdp_process_type_t sdp_type, struct sockaddr d_addr, uint16_t d_port) {
	struct  timeval time_now;
	uint64_t key;
	gettimeofday(&time_now, NULL);
	key = time_now.tv_sec * 1000000 + time_now.tv_usec;

	if (sdp_type == SDP_SENDER) {
		data_plane_sender_context.d_addr = d_addr;
		data_plane_sender_context.d_port = d_port;

	} else if (sdp_type == SDP_RECEIVER) {
		data_plane_media_sdp_t *media_sdp = (data_plane_media_sdp_t *)malloc(sizeof(data_plane_media_sdp_t));
		i64toa(key, media_sdp->key);
		media_sdp->d_addr = d_addr;
		media_sdp->d_port = d_port;
		hashmap_put(data_plane_receiver_map, media_sdp->key, media_sdp);
	}
}

int data_plane_del_sender(sdp_process_type_t sdp_type, const data_plane_media_sdp_t *media_sdp) {

	if (sdp_type == SDP_SENDER) {

	} else if (sdp_type == SDP_RECEIVER) {
		data_plane_media_sdp_t *dat = NULL;
		hashmap_remove(data_plane_receiver_map, (char *)media_sdp->key, (void **)&dat);
	}
}

static int data_plane_run_thread() {

}

int data_plane_run() {

}
