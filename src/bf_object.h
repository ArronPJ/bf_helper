//
//  bf_object.cpp
//  bf_object
//
//  Created by ArronPJ on 6/30/21.
//  Copyright (c) 2021 GTDigital. All rights reserved.
//

#ifndef __bf__bf_object__
#define __bf__bf_object__

#ifdef __cplusplus
extern "C"
{
#endif // #ifdef __cplusplus

#include <stdint.h>
#include <stdbool.h>
#include "jansson.h"

#define bf_object json_t
#define bf_object_iterator void *

#define bf_json_typeof(json) json_typeof(json)
#define bf_json_is_object(json) json_is_object(json)
#define bf_json_is_array(json) json_is_array(json)
#define bf_json_is_string(json) json_is_string(json)
#define bf_json_is_integer(json) json_is_integer(json)
#define bf_json_is_real(json) json_is_real(json)
#define bf_json_is_number(json) json_is_number(json)
#define bf_json_is_true(json) json_is_true(json)
#define bf_json_is_false(json) json_is_false(json)
#define bf_json_is_boolean(json) json_is_boolean(json)
#define bf_json_is_null(json) json_is_null(json)

    /// Creation
    bf_object *bf_object_create(void);
    bf_object *bf_object_create_array(void);
    bf_object *bf_object_create_from_file(const char *path);
    bf_object *bf_object_create_from_json_str(const char *str);
    bf_object *bf_object_create_from_object(const bf_object *object);
    void bf_object_release(bf_object **object);

    char *bf_object_create_string_buffer(const bf_object *object);
    void bf_object_release_string_buffer(char **buffer);
    bool bf_object_to_cstr(const bf_object *object,
                           const uint32_t buffer_size,
                           char *buffer,
                           uint32_t *copied_size);
    bool bf_object_save_to_file(const bf_object *object,
                                const char *filename);
    bf_object *bf_object_get_object(const bf_object *object,
                                    const char *key);
    bool bf_object_get_integer(const bf_object *object,
                               const char *key,
                               int64_t *value);
    bool bf_object_get_boolean(const bf_object *object,
                               const char *key,
                               bool *value);
    const char *bf_object_get_string(const bf_object *object,
                                     const char *key);
    bool bf_object_get_real(const bf_object *object,
                            const char *key,
                            double *value);
    bool bf_object_get_number(const bf_object *object,
                              const char *key,
                              double *value);
    bool bf_object_set_object(bf_object *object,
                              const char *key,
                              bf_object *input);
    bool bf_object_set_integer(bf_object *object,
                               const char *key,
                               const int64_t value);
    bool bf_object_set_boolean(bf_object *object,
                               const char *key,
                               const bool value);
    bool bf_object_set_string(bf_object *object,
                              const char *key,
                              const char *value);
    bool bf_object_set_real(bf_object *object,
                            const char *key,
                            const double value);

    bool bf_object_integer_value(const bf_object *object,
                                 int64_t *value);
    const char *bf_object_string_value(const bf_object *object);
    bool bf_object_real_value(const bf_object *object,
                              double *value);

    bool bf_object_is_string(const bf_object *object);
    bool bf_object_is_integer(const bf_object *object);
    bool bf_object_is_real(const bf_object *object);

    int32_t bf_object_array_size(const bf_object *object);
    bf_object *bf_object_array_get(const bf_object *object,
                                   const int32_t index);
    bool bf_object_array_add(bf_object *array,
                             bf_object *input);
    bool bf_object_array_add_integer(const int64_t value,
                                     bf_object *array);
    bool bf_object_array_add_string(const char *value,
                                    bf_object *array);
    bool bf_object_array_add_real(const double value,
                                  bf_object *array);

    bf_object_iterator bf_object_get_iterator(bf_object *object);
    const char *bf_object_get_iterator_key(bf_object_iterator iterator);
    bf_object *bf_object_get_iterator_object(bf_object_iterator iterator);
    bf_object_iterator bf_object_get_iterator_next(bf_object *object, bf_object_iterator iterator);

    bool bf_object_update(bf_object *target, bf_object *source);

    const char *bf_object_version(void);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif /* defined(__geoobjct__geo_object__) */
