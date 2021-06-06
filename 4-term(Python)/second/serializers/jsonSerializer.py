from .commonSerializer import CommonSerializer
from .parsers.jsonParser import JsonParser as json
from .serialized import serialized
from .deserialized import deserialized


class JsonSerializer(CommonSerializer):
    @serialized
    def dumps(self, obj):
        return json.dumps(obj)

    def dump(self, obj, fp):
       fp.write(JsonSerializer.dumps(self, obj))

    @deserialized
    def loads(self, s):
        return json.loads(s)[0]

    def load(self, fp):
        return JsonSerializer.loads(self, fp.read())
