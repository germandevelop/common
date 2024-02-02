/************************************************************
 *   Author : German Mundinger
 *   Date   : 2022
 ************************************************************/

#ifndef VS1838_CONTROL_H
#define VS1838_CONTROL_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define ONE_BUTTON_CODE     3125149440U
#define TWO_BUTTON_CODE     3108437760U
#define THREE_BUTTON_CODE   3091726080U
#define FOUR_BUTTON_CODE    3141861120U
#define FIVE_BUTTON_CODE    3208707840U
#define SIX_BUTTON_CODE     3158572800U
#define SEVEN_BUTTON_CODE   4161273600U
#define EIGHT_BUTTON_CODE   3927310080U
#define NINE_BUTTON_CODE    4127850240U
#define STAR_BUTTON_CODE    3910598400U
#define ZERO_BUTTON_CODE    3860463360U
#define GRID_BUTTON_CODE    4061003520U
#define UP_BUTTON_CODE      3877175040U
#define LEFT_BUTTON_CODE    4144561920U
#define OK_BUTTON_CODE      3810328320U
#define RIGHT_BUTTON_CODE   2774204160U
#define DOWN_BUTTON_CODE    2907897600U

typedef struct vs1838_control vs1838_control_t;

typedef struct vs1838_control_config
{
    uint32_t start_bit;
    uint32_t zero_bit;
    uint32_t one_bit;
    uint32_t threshold;

} vs1838_control_config_t;

#ifdef __cplusplus
extern "C" {
#endif

void vs1838_control_init (vs1838_control_t * const self, vs1838_control_config_t const * const init_config);
void vs1838_control_process_bit (vs1838_control_t * const self, uint32_t bit_value);
void vs1838_control_is_frame_ready (vs1838_control_t const * const self, bool * const is_frame_ready);
void vs1838_control_get_frame (vs1838_control_t const * const self, uint32_t * const frame);
void vs1838_control_reset_frame (vs1838_control_t * const self);

#ifdef __cplusplus
}
#endif



// Private
typedef struct vs1838_control
{
    vs1838_control_config_t config;

    uint32_t start_bit_min;
    uint32_t start_bit_max;
    uint32_t zero_bit_min;
    uint32_t zero_bit_max;
    uint32_t one_bit_min;
    uint32_t one_bit_max;

    uint32_t code;
    size_t bit_count;

} vs1838_control_t;

#endif // VS1838_CONTROL_H
