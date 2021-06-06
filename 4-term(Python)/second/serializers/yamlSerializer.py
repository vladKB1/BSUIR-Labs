from .commonSerializer import CommonSerializer
from .parsers.yamlParser import YamlParser as yaml
from .serialized import serialized
from .deserialized import deserialized


class YamlSerializer(CommonSerializer):
    @serialized
    def dumps(self, obj):
        return yaml.dumps(obj, 0)

    def dump(self, obj, fp):
        fp.write(YamlSerializer.dumps(self, obj))

    @deserialized
    def loads(self, s):
        return yaml.loads_dict(s, 0, 0)[0]

    def load(self, fp):
        return YamlSerializer.loads(self, fp.read())
