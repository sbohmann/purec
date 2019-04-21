class ElementType:
    def __init__(self, name, typename, size, by_pointer):
        self._name = name
        self._typename = typename
        self._size = size
        self._by_pointer = by_pointer

    @property
    def name(self):
        return self._name

    @property
    def typename(self):
        return self._typename

    @property
    def size(self):
        return self._size

    @property
    def by_pointer(self):
        return self._by_pointer


def primitive_type(name, typename, size):
    return ElementType(name, typename, size, False)


primitive_types = [
    primitive_type('int8', 'int8_t', 1),
    primitive_type('uint8', 'uint8_t', 1),
    primitive_type('int16', 'int16_t', 2),
    primitive_type('uint16', 'uint16_t', 2),
    primitive_type('int32', 'int32_t', 4),
    primitive_type('uint32', 'uint32_t', 4),
    primitive_type('int64', 'int64_t', 8),
    primitive_type('uint64', 'uint64_t', 8),
    primitive_type('float', 'float', 4),
    primitive_type('double', 'double', 8)]


class PointerSize:
    pass


pointer_size = PointerSize()


def pointer_type(name):
    return ElementType(name, name, pointer_size, True)
