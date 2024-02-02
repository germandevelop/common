/************************************************************
 *   Author : German Mundinger
 *   Date   : 2023
 ************************************************************/

#include "node.list.h"

// Nodes
const uint8_t node_ip_address[NODE_LIST_SIZE][4] =
{
    [NODE_T01] = { 192, 168, 0, 110 },
    [NODE_B01] = { 192, 168, 0, 111 },
    [NODE_B02] = { 192, 168, 0, 112 }
};

// Host
const uint16_t host_port = 2399;

const uint8_t host_ip_address[4] = 
{
    192, 168, 0, 101
};

const uint8_t host_netmask[4] =
{
    255, 255, 0, 0
};
