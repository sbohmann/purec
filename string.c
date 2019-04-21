#include "string.h"
#include "reference_counted_struct.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct String {
    struct ReferenceCounted base;
    size_t length;
    char *value;
};

static void assign_text(struct String *self, const char *text, size_t size) {
    memcpy(self->value, text, size + 1);
    self->length = size;
}

static bool allocate_and_assign_text(struct String *self, const char *text) {
    size_t size = strlen(text);
    self->value = malloc(size + 1);
    if (self->value) {
        assign_text(self, text, size);
    }
    return self->value != NULL;
}

struct String * String_create(const char *text) {
    struct String * self = malloc(sizeof(struct String));
    if (self) {
        bzero(self, sizeof(struct String));
        ReferenceCounted_init(&self->base);
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

bool create_concatenated_string(struct String *result, struct String *lhs, struct String *rhs) {
    result->value = malloc(lhs->length + rhs->length + 1);
    if (!result->value) {
        return NULL;
    }
    memcpy(result->value, lhs->value, lhs->length);
    memcpy(result->value + lhs->length, rhs->value, rhs->length);
    result->value[lhs->length + rhs->length] = 0;
    return true;
}

struct String * String_concatenate(struct String *lhs, struct String *rhs) {
    struct String *result = malloc(sizeof(struct String));
    if (result) {
        if (!create_concatenated_string(result, lhs, rhs)) {
            free(result);
            return NULL;
        }
    }
    return result;
}
