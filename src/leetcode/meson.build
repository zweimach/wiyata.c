includes = include_directories('.')

lib_add_two_numbers = library('add_two_numbers',
    sources: 'add_two_numbers.c')

dep_add_two_numbers = declare_dependency(
    link_with: lib_add_two_numbers,
    include_directories: includes)

lib_longest_substring = library('longest_substring',
    sources: 'longest_substring.c')

dep_longest_substring = declare_dependency(
    link_with: lib_longest_substring,
    include_directories: includes)

lib_reverse_integer = library('reverse_integer',
    sources: 'reverse_integer.c')

dep_reverse_integer = declare_dependency(
    link_with: lib_reverse_integer,
    include_directories: includes)
