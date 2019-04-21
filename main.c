#include <stdio.h>
#include "string.h"

int main() {
    struct String *lhs = String_create("Hi! :D");
    struct String *rhs = String_create(" this has been concatenated");
    struct String *text = String_concatenate(lhs, rhs);
    puts(String_cstring(text));
    release(text);
    release(rhs);
    release(lhs);
}
