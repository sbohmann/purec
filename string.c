#include "string.h"
#include "reference_counted_struct.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct String {
    struct ReferenceCounted base;
    const size_t length;
    char *text;
};

static void assign_text(struct String *self, const char *text, size_t size) {
    memcpy(self->text, text, size);
}

static bool allocate_and_assign_text(struct String *self, const char *text) {
    size_t size = strlen(text) + 1;
    self->text = malloc(size);
    if (self->text) {
        assign_text(self, text, size);
    }
    return self->text != 0;
}

struct String * String_create(const char *text) {
    struct String * self = malloc(sizeof(struct String));
    if (self) {
        bzero(self, sizeof(struct String));
        if (!allocate_and_assign_text(self, text)) {
            free(self);
            return 0;
        }
    }
    return self;
}
