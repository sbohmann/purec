class ElementType:
    def __init__(self, name, typename, size):
        self._name = name
        self._typename = typename
        self._size = size

    @property
    def name(self):
        return self._name

    @property
    def typename(self):
        return self._typename

    @property
    def size(self):
        return self._size


class PointerSize:
    pass


pointer_size = PointerSize()


def pointer_type(name):
    return ElementType(name, name, pointer_size)


primitive_types = [
    ElementType('int8', 'int8_t', 1),
    ElementType('uint8', 'uint8_t', 1),
    ElementType('int16', 'int16_t', 2),
    ElementType('uint16', 'uint16_t', 2),
    ElementType('int32', 'int32_t', 4),
    ElementType('uint32', 'uint32_t', 4),
    ElementType('int64', 'int64_t', 8),
    ElementType('uint64', 'uint64_t', 8),
    ElementType('float', 'float', 4),
    ElementType('double', 'double', 8)]
