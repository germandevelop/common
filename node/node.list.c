/************************************************************
 *   Author : German Mundinger
 *   Date   : 2023
 ************************************************************/

#include "node.list.h"

// Nodes
const uint8_t node_ip_address[NODE_LIST_SIZE][4] =
{
	[NODE_ADMIN]	= { 192, 168, 100, 100 },
    [NODE_B01]		= { 192, 168, 100, 110 },
    [NODE_B02]		= { 192, 168, 100, 111 },
    [NODE_T01]		= { 192, 168, 100, 112 }
};

// Server
const uint16_t server_port = 2398;

const uint8_t server_ip_address[4] = 
{
    192, 168, 100, 110
};

// Admin
const uint16_t admin_port = 2399;

const uint8_t netmask[4] =
{
    255, 255, 255, 0
};

