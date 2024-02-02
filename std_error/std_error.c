/************************************************************
 *   Author : German Mundinger
 *   Date   : 2020
 ************************************************************/

#include "std_error.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>


#define DEFAULT_ERROR_TEXT          "Unknown error"
#define INVALID_ARGUMENT_ERROR_TEXT "Invalid input argument"

#define RANGE_ERROR_TEXT    "Range error"
#define DOMAIN_ERROR_TEXT   "Domain error"

#define ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))


void std_error_init (std_error_t * const self)
{
    std_error_reset(self);

    return;
}

void std_error_reset (std_error_t * const self)
{
    self->text[0] = '\0';
    self->code = STD_SUCCESS;

    return;
}

void std_error_catch_errno (std_error_t * const self,
                           char const * const source_file,
                           int source_line)
{
    const int error_code = errno;

#ifdef __AVR__
    if (error_code == EDOM)
    {
        std_error_catch_custom(self, error_code, DOMAIN_ERROR_TEXT, source_file, source_line);
    }
    else if (error_code == ERANGE)
    {
        std_error_catch_custom(self, error_code, RANGE_ERROR_TEXT, source_file, source_line);
    }
    else
    {
        std_error_catch_custom(self, error_code, DEFAULT_ERROR_TEXT, source_file, source_line);
    }
#else
    std_error_catch_custom(self, error_code, strerror(error_code), source_file, source_line);
#endif

    return;
}

void std_error_catch_invalid_argument (std_error_t * const self,
                                      char const * const source_file,
                                      int source_line)
{
    std_error_catch_custom(self, STD_FAILURE, INVALID_ARGUMENT_ERROR_TEXT, source_file, source_line);

    return;
}

void std_error_catch_custom (std_error_t * const self,
                            int error_code,
                            char const * const error_text,
                            char const * const source_file,
                            int source_line)
{
    if (self == NULL)
    {
        return;
    }

    self->code = error_code;

    char error_place[ARRAY_SIZE(self->text) / 2U];
    sprintf(error_place, "(file: \'%s\', line: %d)", source_file, source_line);

    sprintf(self->text, "%d %s %s", self->code, error_text, error_place);

    return;
}
