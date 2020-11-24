includes = include_directories('.')

lib_add_two_numbers = library('add_two_numbers',
    sources: 'add_two_numbers.c')

dep_add_two_numbers = declare_dependency(
    link_with: lib_add_two_numbers,
    include_directories: includes)
