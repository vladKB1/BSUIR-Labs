from .commonSerializer import CommonSerializer
from .serialized import serialized
from .deserialized import deserialized
import pickle


class PickleSerializer(CommonSerializer):
    @serialized
    def dumps(self, obj):
        return pickle.dumps(obj)

    @serialized
    def dump(self, obj, fp):
        return pickle.dump(obj, fp)

    @deserialized
    def loads(self, s):
        return pickle.loads(s)

    @deserialized
    def load(self, fp):
        return pickle.load(fp)
