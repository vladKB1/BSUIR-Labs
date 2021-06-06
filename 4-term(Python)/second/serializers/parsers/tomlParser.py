class TomlParser(object):
    @staticmethod
    def dumps(obj) -> str:
        if type(obj) == tuple:
            ans = ""
            for i in obj:
                ans += f"{TomlParser.dumps(i)}, "
            return f"[ {ans[0:len(ans) - 1]}]"
        else:
            return f"\"{str(obj)}\"".replace("\n", "\\n")

    @staticmethod
    def loads(obj: str):
        if obj == '[]':
            return tuple()
        elif obj[0] == '[':
            obj = obj[1:len(obj) - 1]
            parsed = []
            depth = 0
            quote = False
            substr = ""
            for i in obj:
                if i == '[':
                    depth += 1
                elif i == ']':
                    depth -= 1
                elif i == '\"':
                    quote = not quote
                elif i == ',' and not quote and depth == 0:
                    parsed.append(TomlParser.loads(substr))
                    substr = ""
                    continue
                elif i == ' ' and not quote:
                    continue

                substr += i

            return tuple(parsed)
        else:
            return obj[1:len(obj) - 1]

    @staticmethod
    def replace_null(obj):
        if isinstance(obj, dict):
            for key, value in obj.items():
                if value is None:
                    obj[key] = "null"
                TomlParser.replace_null(value)
        if isinstance(obj, list):
            for i in range(len(obj)):
                if obj[i] is None:
                    obj[i] = "null"
                TomlParser.replace_null(obj[i])

    @staticmethod
    def replace_null_back(obj):
        if isinstance(obj, dict):
            for key, value in obj.items():
                if value == "null":
                    obj[key] = None
                else:
                    TomlParser.replace_null_back(value)

        if isinstance(obj, list):
            for i in range(len(obj)):
                if obj[i] == "null":
                    obj[i] = None
                else:
                    TomlParser.replace_null_back(obj[i])