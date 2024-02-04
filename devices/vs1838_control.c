/************************************************************
 *   Author : German Mundinger
 *   Date   : 2022
 ************************************************************/

#include "vs1838_control.h"


void vs1838_control_init (vs1838_control_t * const self, vs1838_control_config_t const * const init_config)
{
    self->config = *init_config;

    self->start_bit_min = self->config.start_bit - self->config.threshold;
    self->start_bit_max = self->config.start_bit + self->config.threshold;
    self->zero_bit_min  = self->config.zero_bit - self->config.threshold;
    self->zero_bit_max  = self->config.zero_bit + self->config.threshold;
    self->one_bit_min   = self->config.one_bit - self->config.threshold;
    self->one_bit_max   = self->config.one_bit + self->config.threshold;

    self->code      = 0U;
    self->bit_count = 0U;

    return;
}

void vs1838_control_process_bit (vs1838_control_t * const self, uint32_t bit_value)
{
    if ((bit_value > self->zero_bit_min) && (bit_value < self->zero_bit_max))
    {
        if (self->bit_count < 32U)
        {
            self->code &= ~(1 << self->bit_count);
            ++self->bit_count;
        }
    }
    else if ((bit_value > self->one_bit_min) && (bit_value < self->one_bit_max))
    {
        if (self->bit_count < 32U)
        {
            self->code |= (1 << self->bit_count);
            ++self->bit_count;
        }
    }
    else if ((bit_value > self->start_bit_min) && (bit_value < self->start_bit_max))
    {
        self->code      = 0U;
        self->bit_count = 0U;
    }
    return;
}

void vs1838_control_is_frame_ready (vs1838_control_t const * const self, bool * const is_frame_ready)
{
    *is_frame_ready = false;

    if (self->bit_count > 31U)
    {
        *is_frame_ready = true;
    }
    return;
}

void vs1838_control_get_frame (vs1838_control_t const * const self, uint32_t * const frame)
{
    *frame = self->code;

    return;
}

void vs1838_control_reset_frame (vs1838_control_t * const self)
{
    self->code      = 0U;
    self->bit_count = 0U;

    return;
}
