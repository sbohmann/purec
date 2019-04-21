#pragma once

struct ReferenceCounted;

void ReferenceCounted_init(struct ReferenceCounted *self);

void ReferenceCounted_retain(struct ReferenceCounted *instance);

void ReferenceCounted_release(struct ReferenceCounted *instance);

#define retain(instance) (ReferenceCounted_retain((struct ReferenceCounted *) (instance)))

#define release(instance) (ReferenceCounted_release((struct ReferenceCounted *) (instance)))
