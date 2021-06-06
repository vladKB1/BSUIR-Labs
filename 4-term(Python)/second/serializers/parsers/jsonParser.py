tab_len = 2
gap_symbols = "\n\r\t "


class JsonParser(object):
    @staticmethod
    def dumps(obj, depth=1):
        if type(obj) is dict:
            res = "{\n"
            for key, value in obj.items():
                res = res + " " * tab_len * depth
                res = res + "\"" + str(key) + "\"" + ": " + JsonParser.dumps(value, depth + 1) + ',\n'
            res = res[0:-2] + "\n"
            res += " " * tab_len * (depth - 1) + "}"
            return res
        elif type(obj) == list:
            res = "[\n"
            for item in obj:
                res = res + " " * tab_len * depth
                res = res + JsonParser.dumps(item, depth + 1) + ',\n'
            res = res[0:-2] + "\n"
            res += " " * tab_len * (depth - 1) + "]"
            return res
        else:
            return JsonParser.obj_to_str(obj)

    @staticmethod
    def loads(text, current=0):
        if text[current] == '{':
            return JsonParser.load_object(text, current + 1)
        else:
            return JsonParser.load_list(text, current + 1)

    @staticmethod
    def load_object(text, current):
        res = {}
        while True:
            key, current = JsonParser.get_key(text, current)
            value, current = JsonParser.get_value(text, current + 2)
            res[key] = value
            if text[current] == ']':
                current += 1
            current = JsonParser.read_gap_symbols(text, current + 1)
            if text[current] == '}':
                return res, current

    @staticmethod
    def load_list(text, current):
        res = []
        while True:
            value, current = JsonParser.get_value(text, current)
            res.append(value)
            if text[current] == '}':
                current += 1
            current = JsonParser.read_gap_symbols(text, current + 1)
            if text[current] == ']':
                return res, current

    @staticmethod
    def get_key(text, current):
        _, current = JsonParser.read_until_symbol(text, current, '"')
        key, current = JsonParser.read_until_symbol(text, current + 1, '"')
        return key, current

    @staticmethod
    def get_value(text, current):
        current = JsonParser.read_gap_symbols(text, current)
        if text[current] == '{' or text[current] == '[':
            return JsonParser.loads(text, current)

        if text[current] == '"':
            value, current = JsonParser.read_until_symbol(text, current + 1, '"')
            current += 1
        else:
            value, current = JsonParser.read_until_symbol(text, current, ' ,}]\n')
        return JsonParser.str_to_obj(value), current

    @staticmethod
    def read_until_symbol(text, current, symbols):
        res = ""

        if current >= len(text) - 1:
            return res, len(text) - 1

        while not text[current] in symbols:
            res += text[current]
            current += 1
            if current == len(text) - 1:
                break

        return res, current

    @staticmethod
    def read_gap_symbols(text, current):
        if current >= len(text) - 1:
            return len(text) - 1

        while text[current] in gap_symbols:
            current += 1
            if current == len(text) - 1:
                break
        return current

    @staticmethod
    def obj_to_str(obj):
        if type(obj).__name__ == 'str':
            return "\"" + str(obj) + "\""
        if type(obj).__name__ == 'bool':
            return str(obj).lower()
        if obj is None:
            return "null"
        return str(obj)

    @staticmethod
    def str_to_obj(s):
        if len(s) == 0:
            return None
        if s[0] == '"' and s[0] == s[-1]:
            if len(s) == 1:
                return None
            else:
                return s[1:-1]
        if s == 'false':
            return False
        if s == 'true':
            return True
        if s == 'null':
            return None
        try:
            return int(s)
        except:
            try:
                return float(s)
            except:
                return str(s)
