from .serialized import serialized
from .deserialized import deserialized


class CommonSerializer(object):
    @serialized
    def dumps(self, obj):
        pass

    def dump(self, obj, fp):
        pass

    @deserialized
    def loads(self, s):
        pass

    def load(self, fp):
        pass

