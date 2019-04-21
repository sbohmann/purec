#include "reference_counted_struct.h"

#include <stdlib.h>
#include <stdio.h>

void ReferenceCounted_init(struct ReferenceCounted *self) {
    self->reference_count = 1;
}

void ReferenceCounted_retain(struct ReferenceCounted *instance) {
    size_t previous_value = instance->reference_count;
    size_t new_value = ++instance->reference_count;
    if (new_value < previous_value) {
        fputs("Reference count overrun", stderr);
        exit(1);
    }
}

void ReferenceCounted_release(struct ReferenceCounted *instance) {
    size_t previous_value = instance->reference_count;
    size_t new_value = --instance->reference_count;
    if (new_value > previous_value) {
        fputs("Reference count underrun", stderr);
        exit(1);
    }
    if (new_value == 0) {
        if (instance->cleanup) {
            instance->cleanup(instance);
        }
        free(instance);
    }
}
