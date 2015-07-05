#include "data_plane.h"


typedef struct {
	uint32_t port_start;
	uint32_t port_end;
} data_plane_port_range_t;


static data_plane_media_sdp_t data_plane_sender_context;
static data_plane_media_sdp_t data_plane_receiver_context[60];
static data_plane_port_range_t data_plane_port_range;

int data_plane_init(uint32_t rtp_port_start, uint32_t rtp_port_end) {
	data_plane_port_range.port_start = rtp_port_start;
	data_plane_port_range.port_end = rtp_port_end;
}

data_plane_media_sdp_t data_plane_add_sender(sdp_process_type_t sdp_type, struct sockaddr d_addr, uint16_t d_port) {
	if (sdp_type == SDP_SENDER) {
		data_plane_sender_context.d_addr = d_addr;
		data_plane_sender_context.d_port = d_port;
	} else if (sdp_type == SDP_RECEIVER) {
		/*
		data_plane_receiver_context.d_addr = d_addr;
		data_plane_receiver_context.d_port = d_port;
		*/
	}
}

int data_plane_del_sender(sdp_process_type_t sdp_type, data_plane_media_sdp_t media_sdp) {

	if (sdp_type == SDP_SENDER) {

	} else if (sdp_type == SDP_RECEIVER) {

	}
}

static int data_plane_run_thread() {

}

int data_plane_run() {

}
