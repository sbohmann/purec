#include <stdio.h>
#include "string.h"

int main() {
    struct String *text = String_create("Hi! :D");
    puts(String_cstring(text));
    release(text);
    release(text);
}
