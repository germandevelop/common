/************************************************************
 *   Author : German Mundinger
 *   Date   : 2023
 ************************************************************/

#ifndef NODE_COMMAND_H
#define NODE_COMMAND_H

typedef enum node_command_id
{
    DO_NOTHING = 0,
    SET_MODE,
    SET_LIGHT,
    SET_INTRUSION,
    UPDATE_TEMPERATURE,
    NODE_COMMAND_SIZE

} node_command_id_t;

typedef enum node_mode_id
{
    SILENCE = 0,
    GUARD,
    ALARM

} node_mode_id_t;

typedef enum node_light_id
{
    LIGHT_OFF = 0,
    LIGHT_ON

} node_light_id_t;

typedef enum node_intrusion_id
{
    INTRUSION_OFF = 0,
    INTRUSION_ON

} node_intrusion_id_t;

#endif // NODE_COMMAND_H

