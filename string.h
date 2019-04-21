#ifndef PUREC_STRING_H
#define PUREC_STRING_H

#include "reference_counted.h"

struct String;

struct String * String_create(const char *text);

#endif
