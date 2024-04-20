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
    NODE_B01 = 0,
    NODE_B02,
	NODE_T01,
    NODE_LIST_SIZE,
	NODE_BROADCAST = 255,
	NODE_ADMIN

} node_id_t;

extern const uint8_t node_ip_address[NODE_LIST_SIZE][4];

// Server
extern const uint16_t server_port;
extern const uint8_t server_ip_address[4];

// Admin
extern const uint16_t admin_port;
extern const uint8_t admin_ip_address[4];

extern const uint8_t netmask[4];

#endif // NODE_LIST_H
