#pragma once

#include "reference_counted.h"

struct String;

struct String * String_create(const char *text);

const char * String_cstring(struct String *self);

const struct String * String_concatenate(struct String *lhs, struct String *rhs);
