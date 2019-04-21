#ifndef PUREC_REFERENCE_COUNTED_H
#define PUREC_REFERENCE_COUNTED_H

struct ReferenceCounted;

void ReferenceCounted_retain(struct ReferenceCounted *instance);

void ReferenceCounted_release(struct ReferenceCounted *instance);

#define retain(instance) (ReferenceCounted_retain((struct ReferenceCounted *) (instance)))

#define release(instance) (ReferenceCounted_release((struct ReferenceCounted *) (instance)))

#endif
