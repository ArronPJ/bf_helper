//
//  bf_object.cpp
//  bf_object
//
//  Created by ArronPJ on 6/30/21.
//  Copyright (c) 2021 GTDigital. All rights reserved.
//

#include "bf_object.h"

#include <string.h>

bf_object *bf_object_create(void)
{
    json_t *json = json_object();
    if (!json)
    {
        return NULL;
    }

    return json;
}

bf_object *bf_object_create_array(void)
{
    json_t *json = json_array();
    if (!json)
    {
        return NULL;
    }

    return json;
}

bf_object *bf_object_create_from_file(const char *path)
{
    if (!path)
    {
        return NULL;
    }

    json_error_t error;
    json_t *json = json_load_file(path, JSON_DECODE_ANY, &error);

    if (!json)
    {
    }

    return json;
}

bf_object *bf_object_create_from_json_str(const char *str)
{
    if (!str)
    {
        return NULL;
    }

    json_error_t error;
    json_t *json = json_loads(str, JSON_DECODE_ANY, &error);
    if (!json)
    {
        return NULL;
    }

    return json;
}

bf_object *bf_object_create_from_object(const bf_object *object)
{
    if (!object)
    {
        return NULL;
    }

    json_t *json_object = (json_t *)object;

    json_t *json = json_deep_copy(json_object);

    if (!json)
    {
        return NULL;
    }

    bf_object *new_object = json;

    return new_object;
}

void bf_object_release(bf_object **object)
{
    if (!(*object))
    {
        return;
    }

    json_t *json = (*object);
    if (json)
    {
        json_decref(json);
    }

    (*object) = NULL;
}

char *bf_object_create_string_buffer(const bf_object *object)
{
    if (!object)
    {
        return NULL;
    }

    const json_t *json = object;

    char *dumps = json_dumps(json, JSON_ESCAPE_SLASH & JSON_ENCODE_ANY);

    return dumps;
}
void bf_object_release_string_buffer(char **buffer)
{
    if (!(*buffer))
    {
        return;
    }

    free(*buffer);
}
bool bf_object_to_cstr(const bf_object *object,
                       const uint32_t buffer_size,
                       char *buffer,
                       uint32_t *copied_size)
{
    if (!object ||
        0 == buffer_size ||
        !buffer ||
        !copied_size)
    {
        return false;
    }

    char *string_buffer = bf_object_create_string_buffer(object);
    if (!string_buffer)
    {
        return false;
    }

    copied_size = 0;
    *copied_size = (uint32_t)strlen(string_buffer);
    strncpy(buffer, string_buffer, buffer_size);

    bf_object_release_string_buffer(&string_buffer);
    return true;
}

bool bf_object_save_to_file(const bf_object *object,
                            const char *filename)
{
    if (!object || !filename)
    {
        return false;
    }

    const json_t *json = object;

    int ret_value = json_dump_file(json, filename, JSON_ESCAPE_SLASH);

    return (0 == ret_value);
}

bf_object *bf_object_get_object(const bf_object *object,
                                const char *key)
{
    if (!object || !key)
    {
        return NULL;
    }

    const json_t *json = object;

    json_t *json_value = json_object_get(json, key);

    return json_value;
}

bool bf_object_get_integer(const bf_object *object,
                           const char *key,
                           int64_t *value)
{
    if (!object || !key || !value)
    {
        return false;
    }

    const json_t *json = object;

    json_t *json_value = json_object_get(json, key);

    if (!json_is_integer(json_value))
    {
        return false;
    }

    *value = json_integer_value(json_value);
    return true;
}
bool bf_object_get_boolean(const bf_object *object,
                           const char *key,
                           bool *value)
{
    if (!object || !key || !value)
    {
        return false;
    }

    const json_t *json = object;

    json_t *json_value = json_object_get(json, key);

    if (!json_is_boolean(json_value))
    {
        return false;
    }
    if (json_is_true(json_value))
    {
        *value = true;
    }
    else
    {
        *value = false;
    }
    return true;
}
const char *bf_object_get_string(const bf_object *object,
                                 const char *key)
{
    if (!object || !key)
    {
        return NULL;
    }

    const json_t *json = object;

    json_t *json_value = json_object_get(json, key);

    if (!json_is_string(json_value))
    {
        return NULL;
    }

    return json_string_value(json_value);
}
bool bf_object_get_real(const bf_object *object,
                        const char *key,
                        double *value)
{
    if (!object || !key || !value)
    {
        return false;
    }

    const json_t *json = object;

    json_t *json_value = json_object_get(json, key);

    if (!json_is_real(json_value))
    {
        return false;
    }

    *value = json_real_value(json_value);
    return true;
}
bool bf_object_get_number(const bf_object *object,
                          const char *key,
                          double *value)
{
    if (!object || !key || !value)
    {
        return false;
    }

    const json_t *json = object;

    json_t *json_value = json_object_get(json, key);
    if (!json_is_number(json_value))
    {
        return false;
    }
    if (!json_is_real(json_value)) // int or real
    {
        //it must be int
        int64_t tmpIntValue = 0;
        tmpIntValue = json_integer_value(json_value);
        *value = (double)tmpIntValue;
        return true;
    }
    *value = json_real_value(json_value);
    return true;
}

bool bf_object_set_object(bf_object *object,
                          const char *key,
                          bf_object *input)
{
    if (!object || !key || !input)
    {
        return false;
    }

    json_t *json = object;

    json_t *input_json = input;

    int ret = json_object_set(json, key, input_json);

    return (0 != ret) ? false : true;
}

bool bf_object_set_integer(bf_object *object,
                           const char *key,
                           const int64_t value)
{
    if (!object || !key)
    {
        return false;
    }

    json_t *json_value = json_integer(value);
    if (!json_value)
    {
        return false;
    }

    json_t *json = object;

    int ret = json_object_set(json, key, json_value);
    json_decref(json_value);
    json_value = NULL;

    return (0 != ret) ? false : true;
}

bool bf_object_set_boolean(bf_object *object,
                           const char *key,
                           const bool value)
{
    if (!object || !key)
    {
        return false;
    }

    json_t *json_value = json_boolean(value);
    if (!json_value)
    {
        return false;
    }

    json_t *json = object;

    int ret = json_object_set(json, key, json_value);
    json_decref(json_value);
    json_value = NULL;

    return (0 != ret) ? false : true;
}

bool bf_object_set_string(bf_object *object,
                          const char *key,
                          const char *value)
{
    if (!object || !key)
    {
        return false;
    }

    json_t *json_value = json_string(value);
    if (!json_value)
    {
        return false;
    }

    json_t *json = object;

    int ret = json_object_set(json, key, json_value);
    json_decref(json_value);
    json_value = NULL;

    return (0 != ret) ? false : true;
}

bool bf_object_set_real(bf_object *object,
                        const char *key,
                        const double value)
{
    if (!object || !key)
    {
        return false;
    }

    json_t *json_value = json_real(value);
    if (!json_value)
    {
        return false;
    }

    json_t *json = object;

    int ret = json_object_set(json, key, json_value);
    json_decref(json_value);
    json_value = NULL;

    return (0 != ret) ? false : true;
}
bool bf_object_integer_value(const bf_object *object,
                             int64_t *value)
{
    if (!object || !value)
    {
        return false;
    }

    const json_t *json = object;
    if (!json_is_integer(json))
    {
        return false;
    }

    *value = json_integer_value(json);
    return true;
}
const char *bf_object_string_value(const bf_object *object)
{
    if (!object)
    {
        return NULL;
    }

    const json_t *json = object;
    if (!json_is_string(json))
    {
        return NULL;
    }

    return json_string_value(json);
}
bool bf_object_real_value(const bf_object *object,
                          double *value)
{
    if (!object || !value)
    {
        return false;
    }

    const json_t *json = object;
    if (!json_is_real(json))
    {
        return false;
    }

    *value = json_real_value(json);
    return true;
}

bool bf_object_is_string(const bf_object *object)
{
    if (!object)
    {
        return false;
    }

    const json_t *json = object;
    return json_is_string(json);
}
bool bf_object_is_integer(const bf_object *object)
{
    if (!object)
    {
        return false;
    }

    const json_t *json = object;
    return json_is_integer(json);
}
bool bf_object_is_real(const bf_object *object)
{
    if (!object)
    {
        return false;
    }

    const json_t *json = object;
    return json_is_real(json);
}

int32_t bf_object_array_size(const bf_object *object)
{
    if (!object)
    {
        return 0;
    }

    const json_t *json = object;

    if (!json_is_array(json))
    {
        return 0;
    }

    return (int32_t)json_array_size(json);
}
bf_object *bf_object_array_get(const bf_object *object,
                               const int32_t index)
{
    if (!object || 0 > index)
    {
        return NULL;
    }

    const json_t *json = object;
    if (!json_is_array(json))
    {
        return NULL;
    }

    json_t *json_value = json_array_get(json, index);

    return json_value;
}
bool bf_object_array_add(bf_object *array,
                         bf_object *input)
{
    if (!array || !input)
    {
        return false;
    }

    json_t *json = array;
    if (!json_is_array(json))
    {
        return false;
    }

    json_t *input_json = input;

    int ret = json_array_append(json, input_json);

    return (0 == ret) ? true : false;
}
bool bf_object_array_add_integer(const int64_t value,
                                 bf_object *array)
{
    if (!array)
    {
        return false;
    }

    json_t *json = array;
    if (!json_is_array(json))
    {
        return false;
    }

    json_t *object = json_integer(value);
    int ret = json_array_append(array, object);
    json_decref(object);

    return (0 == ret) ? true : false;
}
bool bf_object_array_add_string(const char *value,
                                bf_object *array)
{
    if (!array)
    {
        return false;
    }

    json_t *json = array;
    if (!json_is_array(json))
    {
        return false;
    }

    json_t *object = json_string(value);
    int ret = json_array_append(array, object);
    json_decref(object);

    return (0 == ret) ? true : false;
}
bool bf_object_array_add_real(const double value,
                              bf_object *array)
{
    if (!array)
    {
        return false;
    }

    json_t *json = array;
    if (!json_is_array(json))
    {
        return false;
    }

    json_t *object = json_real(value);
    int ret = json_array_append(array, object);
    json_decref(object);

    return (0 == ret) ? true : false;
}
bf_object_iterator bf_object_get_iterator(bf_object *object)
{
    if (!object)
    {
        return NULL;
    }

    json_t *json = object;

    void *json_iter = json_object_iter(json);
    if (!json_iter)
    {
        return NULL;
    }

    bf_object_iterator iterator = json_iter;

    return iterator;
}
const char *bf_object_get_iterator_key(bf_object_iterator iterator)
{
    if (!iterator)
    {
        return NULL;
    }

    void *json_iter = iterator;

    const char *key = json_object_iter_key(json_iter);

    return key;
}
bf_object *bf_object_get_iterator_object(bf_object_iterator iterator)
{
    if (!iterator)
    {
        return NULL;
    }

    void *json_iter = iterator;

    json_t *json = json_object_iter_value(json_iter);
    if (!json)
    {
        return NULL;
    }

    bf_object *object = json;

    return object;
}
bf_object_iterator bf_object_get_iterator_next(bf_object *object, bf_object_iterator iterator)
{
    if (!object || !iterator)
    {
        return NULL;
    }

    json_t *json = object;
    void *json_iter = iterator;

    void *json_next_iter = json_object_iter_next(json, json_iter);

    if (!json_next_iter)
    {
        return NULL;
    }

    bf_object_iterator next_iterator = json_next_iter;

    return next_iterator;
}

bool bf_object_update(bf_object *target, bf_object *source)
{
    if (!target || !source)
    {
        return false;
    }

    json_t *json_target = target;
    json_t *json_source = source;

    int ret = json_object_update(json_target, json_source);

    return (0 == ret) ? true : false;
}

const char *bf_object_version()
{
    return "bf_object_version = v1.0.0";
}
//v0.0.1: add version
//v0.1.0: add dependency and functions()
//v1.0.0: 38 functions. (basic usage ok)