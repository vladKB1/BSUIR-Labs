code_attributes = [
    'co_argcount',
    'co_posonlyargcount',
    'co_kwonlyargcount',
    'co_nlocals',
    'co_stacksize',
    'co_flags',
    'co_code',
    'co_consts',
    'co_names',
    'co_varnames',
    'co_filename',
    'co_name',
    'co_firstlineno',
    'co_lnotab',
    'co_freevars',
    'co_cellvars'
]

rude_types = {
    "int": int,
    "float": float,
    "str": str,
    "bool": bool,
}

object_types = {
    "list": list,
    "set": set,
    "frozenset": frozenset,
    "dict": dict,
    "tuple": tuple,
}