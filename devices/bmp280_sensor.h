/************************************************************
 *   Author : German Mundinger
 *   Date   : 2023
 ************************************************************/

#ifndef BMP280_SENSOR_H
#define BMP280_SENSOR_H

#include <stdint.h>

typedef struct std_error std_error_t;

typedef int (*bmp280_sensor_i2c_callback_t) (uint16_t device_address, uint16_t register_address, uint16_t register_size, uint8_t *array, uint16_t array_size, uint32_t timeout_ms, std_error_t * const error);
typedef void (*bmp280_sensor_delay_callback_t) (uint32_t delay_ms);

typedef struct bmp280_sensor_config
{
    bmp280_sensor_i2c_callback_t read_i2c_callback;
    bmp280_sensor_i2c_callback_t write_i2c_callback;
	uint32_t i2c_timeout_ms;

    bmp280_sensor_delay_callback_t delay_callback;

} bmp280_sensor_config_t;

typedef struct bmp280_sensor_data
{
    float pressure_hPa;
    float temperature_C;

} bmp280_sensor_data_t;

int bmp280_sensor_init (bmp280_sensor_config_t const * const init_config, std_error_t * const error);

int bmp280_sensor_read_data (bmp280_sensor_data_t * const data, std_error_t * const error);

#endif // BMP280_SENSOR_H
