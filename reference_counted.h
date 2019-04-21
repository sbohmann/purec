#ifndef PUREC_REFERENCE_COUNTED_H
#define PUREC_REFERENCE_COUNTED_H

struct ReferenceCounted;

void retain(struct ReferenceCounted *instance);

void release(struct ReferenceCounted *instance);

#endif
