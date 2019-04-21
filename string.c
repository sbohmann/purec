#include "string.h"
#include "reference_counted_struct.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct String {
    struct ReferenceCounted base;
    const size_t length;
    char *value;
};

static void assign_text(struct String *self, const char *text, size_t size) {
    memcpy(self->value, text, size);
}

static bool allocate_and_assign_text(struct String *self, const char *text) {
    size_t size = strlen(text) + 1;
    self->value = malloc(size);
    if (self->value) {
        assign_text(self, text, size);
    }
    return self->value != NULL;
}

struct String * String_create(const char *text) {
    struct String * self = malloc(sizeof(struct String));
    if (self) {
        bzero(self, sizeof(struct String));
        if (!allocate_and_assign_text(self, text)) {
            free(self);
            return NULL;
        }
    }
    return self;
}

const char *String_cstring(struct String *self) {
    return self->value;
}
