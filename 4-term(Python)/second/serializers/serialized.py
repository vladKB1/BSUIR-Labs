import inspect
from types import FunctionType
from .Types import rude_types
from .Types import object_types
from .Types import code_attributes


def serialized(func):
    def serialized_wrapper(*args, **kwargs):
        if bool(kwargs):
            if kwargs.get('obj') is None:
                raise TypeError('[@serialized] obj doesn\'t exists in kwargs')
            kwargs['obj'] = serialize(kwargs.get('obj'))
        if bool(args):
            if not type(args[1]) is dict and not type(args[1]) is FunctionType:
                raise TypeError('[@serialized] first argument(exclude self) is\'t available to serialize')
        return func(*[args[0], serialize(args[1]), *(args[2:])], **kwargs)

    return serialized_wrapper


def serialize(obj):
    result = {}

    if obj is None:
        return {"None": None}

    elif not rude_types.get(type(obj).__name__) is None:
        return {type(obj).__name__: obj}

    elif type(obj) is dict:
        serialized_dict = {}
        for key in obj:
            serialized_dict['item%i' % len(serialized_dict)] = {"key": serialize(key), "value": serialize(obj[key])}
        result = {type(obj).__name__: serialized_dict}

    elif not object_types.get(type(obj).__name__) is None:
        serialized_object_like = []
        for key in obj:
            serialized_object_like.append(serialize(key))
        result = {type(obj).__name__: serialized_object_like}

    elif type(obj) is FunctionType:
        result = {type(obj).__name__: serialize(function_to_dict(obj))}

    return result


def function_to_dict(func):
    members = dict(inspect.getmembers(func))
    code_attrs = dict(inspect.getmembers(members['__code__']))
    special = []
    for attr_name in code_attributes:
        if attr_name == 'co_lnotab' or attr_name == 'co_code':
            if len(list(code_attrs[attr_name])) == 0:
                special.append(None)
            else:
                special.append(list(code_attrs[attr_name]))
        else:
            if code_attrs[attr_name] == ():
                special.append(None)
            else:
                special.append(code_attrs[attr_name])

    name = members['__name__']
    globals_res = {"__name__": name}
    for outer_obj_name in code_attrs['co_names']:
        if outer_obj_name == name:
            globals_res[outer_obj_name] = outer_obj_name
            continue
        if outer_obj_name in __builtins__:
            continue
        globals_res[outer_obj_name] = serialize(members['__globals__'][outer_obj_name])

    return {"__code__": special,
            "__globals__": globals_res,
            "__name__": name,
            "__defaults__": members['__defaults__']}