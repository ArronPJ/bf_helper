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

const char *bf_object_version()
{
    return "bf_object_version = v0.1.0";
}
//v0.0.1: add version
//v0.1.0: add dependency and functions()