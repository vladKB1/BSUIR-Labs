tab_len = 2

gap_symbols = "\n\r\t "
COMPLEX_TYPES = [list, dict]


class YamlParser(object):
    @staticmethod
    def dumps(obj, depth):
        response = ""
        if type(obj) is dict:
            for key, value in obj.items():
                response += " " * tab_len * depth
                response += YamlParser.obj_to_str(key) + ": "
                if type(value) in COMPLEX_TYPES:
                    response += '\n'
                response += YamlParser.dumps(value, depth + 1)
                if type(value) not in COMPLEX_TYPES:
                    response += '\n'
        elif type(obj) is list:
            for value in obj:
                response += " " * tab_len * (depth - 1) + '-'
                if type(value) not in COMPLEX_TYPES:
                    response += ' ' + YamlParser.dumps(value, depth)
                else:
                    response += YamlParser.dumps(value, depth)[tab_len * (depth - 1) + 1:]
                if type(value) not in COMPLEX_TYPES:
                    response += '\n'
        else:
            return YamlParser.obj_to_str(obj)
        return response

    @staticmethod
    def loads_dict(s, current, depth, flag=False):
        response = {}
        while True:
            prev_current = current
            line, current = YamlParser.read_until_symbol(s, current, '\n')
            if current == len(s):
                return response, current
            if ':' not in line:
                return YamlParser.loads_list(s, prev_current, depth)
            key, value = line.split(':')
            if max(0, depth - 1) * tab_len < len(key) and key[max(0, depth - 1) * tab_len] == '-':
                if not flag:
                    return YamlParser.loads_list(s, prev_current, depth)
                else:
                    return response, prev_current

            if not YamlParser.get_spaces_count(key) == depth * tab_len:
                return response, prev_current

            key = YamlParser.str_to_obj(YamlParser.trim(key))
            value = YamlParser.trim(value)

            if len(value) > 0:
                response[key] = YamlParser.str_to_obj(value)
                current += 1
            else:
                response[key], current = YamlParser.loads_dict(s, current + 1, depth + 1)
                if flag:
                    return response, current
                continue

    @staticmethod
    def loads_list(s, current, depth):
        response = []
        while True:
            if current >= len(s):
                return response, current
            prev_current = current
            line, current = YamlParser.read_until_symbol(s, current, '\n')
            if '-' not in line:
                return response, prev_current
            if not line[max(0, (depth - 1)) * tab_len] == '-':
                return response, prev_current
            if ':' not in line:
                line = line[0:max(0, (depth - 1)) * tab_len] + ' ' + line[max(0, (depth - 1)) * tab_len + 1:]
                response.append(YamlParser.str_to_obj(YamlParser.trim(line)))
                current += 1
                continue

            if line[max(0, (depth - 1)) * tab_len] == '-':
                s = s[0:prev_current + max(0, (depth - 1)) * tab_len] + ' ' + s[prev_current + max(0, (
                        depth - 1)) * tab_len + 1:]
                resp, current = YamlParser.loads_dict(s, prev_current, depth, True)
                response.append(resp)
                continue

    @staticmethod
    def get_spaces_count(s):
        i = 0
        while i < len(s) and s[i] == ' ':
            i += 1
        return i

    @staticmethod
    def read_until_symbol(text, current, symbols):
        res = ""
        while len(text) > current and not text[current] in symbols:
            res += text[current]
            current += 1
        return res, current

    @staticmethod
    def trim(s):
        l, r = -1, 0
        for i in range(len(s)):
            if l == -1 and not s[i] in gap_symbols:
                l = i
            if not s[i] in gap_symbols:
                r = i + 1
        return s[l:r]

    @staticmethod
    def obj_to_str(obj):
        if type(obj).__name__ == 'str':
            return "\'" + str(obj) + "\'"
        if type(obj).__name__ == 'bool':
            return str(obj).lower()
        if obj is None:
            return "null"
        return str(obj)

    @staticmethod
    def str_to_obj(s):
        if s[0] == "'" and s[0] == s[-1]:
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
