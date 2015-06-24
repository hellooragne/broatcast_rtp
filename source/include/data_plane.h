#ifndef __data_plane__
#define __data_plane__

#include <stdio.h>
#include <stdint.h>

#include <sys/type.h>
#include <sys/socket.h>


typedef struct {
	sockaddr_t s_addr;	
	uint16_t s_port;		

	sockaddr_t d_addr;	
	uint16_t d_port;
} data_plane_t;


data_plane_t data_plane_context[61];

#endif
