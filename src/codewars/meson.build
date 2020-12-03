includes = include_directories('.')

lib_reverse_list_recursively = library('reverse_list_recursively',
    sources: 'reverse_list_recursively.c')

dep_reverse_list_recursively = declare_dependency(
    link_with: lib_reverse_list_recursively,
    include_directories: includes)

lib_string_repeat = library('string_repeat',
    sources: 'string_repeat.c')

dep_string_repeat = declare_dependency(
    link_with: lib_string_repeat,
    include_directories: includes)
