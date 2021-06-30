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

    const char *bf_object_version(void);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif /* defined(__geoobjct__geo_object__) */