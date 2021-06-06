from .jsonSerializer import JsonSerializer
from .pickleSerializer import PickleSerializer
from .tomlSerializer import TomlSerializer
from .yamlSerializer import YamlSerializer

from enum import Enum


class AvailableSerializers(Enum):
    json = "JSON"
    pickle = "PICKLE"
    toml = "TOML"
    yaml = "YAML"


class SerializeFactory:
    @staticmethod
    def validate_covers_all_available_serializers(serializer_type_to_serializer_object):
        for value in [e.value for e in AvailableSerializers]:
            if serializer_type_to_serializer_object.get(value) is None:
                raise TypeError("%s serializer doesn't exists in serializer_type_to_serializer_object, but added to "
                                "AvailableSerializers" % value)

    @classmethod
    def create_serializer(cls, serializer_type):
        serializer_type_to_serializer_object = {AvailableSerializers.json.value: JsonSerializer(),
                                                AvailableSerializers.pickle.value: PickleSerializer(),
                                                AvailableSerializers.toml.value: TomlSerializer(),
                                                AvailableSerializers.yaml.value: YamlSerializer()}

        cls.validate_covers_all_available_serializers(serializer_type_to_serializer_object)

        if not serializer_type_to_serializer_object.get(serializer_type):
            raise ValueError("%s serializer doesn't support" % serializer_type)

        return serializer_type_to_serializer_object[serializer_type]

