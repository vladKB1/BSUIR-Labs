from .commonSerializer import CommonSerializer
from .parsers.tomlParser import TomlParser as toml
from .serialized import serialized
from .deserialized import deserialized


class TomlSerializer(CommonSerializer):
    @serialized
    def dumps(self, obj):
        toml.replace_null(obj)
        return toml.dumps(obj)

    def dump(self, obj, fp):
        fp.write(TomlSerializer.dumps(self, obj))

    @deserialized
    def loads(self, s):
        res = toml.loads(s)
        toml.replace_null_back(res)
        return res

    def load(self, fp):
        return TomlSerializer.loads(self, fp.read())
