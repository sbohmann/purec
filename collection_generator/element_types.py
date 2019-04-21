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


int8 = ElementType('int8', 'int8_t', 1)
uint8 = ElementType('uint8', 'uint8_t', 1)
int16 = ElementType('int16', 'int16_t', 2)
uint16 = ElementType('uint16', 'uint16_t', 2)
int32 = ElementType('int32', 'int32_t', 4)
uint32 = ElementType('uint32', 'uint32_t', 4)
int64 = ElementType('int64', 'int64_t', 8)
uint64 = ElementType('uint64', 'uint64_t', 8)
float = ElementType('float', 'float', 4)
double = ElementType('double', 'double', 8)
