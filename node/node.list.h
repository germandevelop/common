/************************************************************
 *   Author : German Mundinger
 *   Date   : 2023
 ************************************************************/

#ifndef NODE_LIST_H
#define NODE_LIST_H

#include <stdint.h>

// Nodes
typedef enum node_id
{
    NODE_T01 = 0,
    NODE_B01,
    NODE_B02,
    NODE_LIST_SIZE,
	NODE_BROADCAST = 255

} node_id_t;

extern const uint8_t node_ip_address[NODE_LIST_SIZE][4];

// Host
extern const uint16_t host_port;
extern const uint8_t host_ip_address[4];
extern const uint8_t host_netmask[4];

#endif // NODE_LIST_H
