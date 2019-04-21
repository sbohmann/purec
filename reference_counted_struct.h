#pragma once

#include "reference_counted.h"

#include <stdatomic.h>

struct ReferenceCounted {
    atomic_size_t reference_count;
    void (*cleanup)(struct ReferenceCounted *self);
};
