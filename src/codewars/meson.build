includes = include_directories('.')

lib_alternate_case = library('alternate_case',
    sources: 'alternate_case.c')

dep_alternate_case = declare_dependency(
    link_with: lib_alternate_case,
    include_directories: includes)

lib_n_th_power = library('n-th_power',
    sources: 'n-th_power.c',
    dependencies: dep_m)

dep_n_th_power = declare_dependency(
    link_with: lib_n_th_power,
    include_directories: includes)

lib_ones_and_zeros = library('ones_and_zeros',
    sources: 'ones_and_zeros.c',
    dependencies: dep_m)

dep_ones_and_zeros = declare_dependency(
    link_with: lib_ones_and_zeros,
    include_directories: includes)

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

lib_who_likes_it = library('who_likes_it',
    sources: 'who_likes_it.c')

dep_who_likes_it = declare_dependency(
    link_with: lib_who_likes_it,
    include_directories: includes)
