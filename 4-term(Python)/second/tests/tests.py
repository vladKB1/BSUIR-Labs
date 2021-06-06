from serializers.serializeFactory import SerializeFactory
from examples import *
import unittest


def parse_and_compare_func(obj, Format, tester):
    s = SerializeFactory.create_serializer(Format.upper())

    file = open(f"output.{Format}", "w")
    s.dump(obj, file)
    file.close()
    file = open(f"output.{Format}", "r")
    res = s.load(file)
    file.close()


class TestClass(unittest.TestCase):
    def test_parse_json(self):
        parse_and_compare_func(test_fact, "json", self)
        parse_and_compare_func(test_dict_func, "jSoN", self)

    def test_parse_yaml(self):
        parse_and_compare_func(test_dict_func, "yaml", self)
        parse_and_compare_func(test_fact, "YAMl", self)

    def test_parse_toml(self):
        parse_and_compare_func(test_dict_func, "toml", self)
        parse_and_compare_func(test_fact, "toMl", self)

    def test_parse_err(self):
        res = False
        try:
            s = SerializeFactory.create_serializer("err")
        except ValueError:
            res = True
        self.assertTrue(res)
