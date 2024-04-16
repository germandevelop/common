/************************************************************
 *   Author : German Mundinger
 *   Date   : 2023
 ************************************************************/

#ifndef NODE_COMMAND_H
#define NODE_COMMAND_H

typedef enum node_command_id
{
    DO_NOTHING = 0,
	REQUEST_VERSION,
	RESPONSE_VERSION,
	UPDATE_FIRMWARE,
    SET_MODE,
    SET_WARNING,
    SET_LIGHT,
    SET_INTRUSION,
	UPDATE_HUMIDITY,
    UPDATE_TEMPERATURE,
    UPDATE_DOOR_STATE,
    NODE_COMMAND_SIZE

} node_command_id_t;

typedef enum node_mode_id
{
    SILENCE_MODE = 0,
    GUARD_MODE,
    ALARM_MODE

} node_mode_id_t;

typedef enum node_warning_id
{
    WARNING_OFF = 0,
    WARNING_ON

} node_warning_id_t;

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

