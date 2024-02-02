/************************************************************
 *   Author : German Mundinger
 *   Date   : 2020
 ************************************************************/

#ifndef STD_ERROR_H
#define STD_ERROR_H

#define STD_SUCCESS (0)
#define STD_FAILURE (-1)

#ifdef __AVR__
#define TEXT_SIZE 128
#else
#define TEXT_SIZE 256
#endif

typedef struct std_error
{
    char text[TEXT_SIZE];
    int code;

} std_error_t;

#ifdef __cplusplus
extern "C" {
#endif

void std_error_init (std_error_t * const self);
void std_error_reset (std_error_t * const self);

void std_error_catch_errno (std_error_t * const self,
                           char const * const source_file,
                           int source_line);

void std_error_catch_invalid_argument (std_error_t * const self,
                                      char const * const source_file,
                                      int source_line);

void std_error_catch_custom (std_error_t * const self,
                            int error_code,
                            char const * const error_text,
                            char const * const source_file,
                            int source_line);
#ifdef __cplusplus
}
#endif

#endif // STD_ERROR_H
