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

lib_string_to_integer = library('string_to_integer',
    sources: 'string_to_integer.c')

dep_string_to_integer = declare_dependency(
    link_with: lib_string_to_integer,
    include_directories: includes)

test_add_two_numbers = executable('add_two_numbers_test',
    sources: 'add_two_numbers_test.c',
    dependencies: [dep_cmocka, dep_add_two_numbers])

test('leetcode add_two_numbers', test_add_two_numbers)

test_longest_substring = executable('longest_substring_test',
    sources: 'longest_substring_test.c',
    dependencies: [dep_cmocka, dep_longest_substring])

test('leetcode longest_substring', test_longest_substring)

test_reverse_integer = executable('reverse_integer_test',
    sources: 'reverse_integer_test.c',
    dependencies: [dep_cmocka, dep_reverse_integer])

test('leetcode reverse_integer', test_reverse_integer)

test_string_to_integer = executable('string_to_integer_test',
    sources: 'string_to_integer_test.c',
    dependencies: [dep_cmocka, dep_string_to_integer])

test('leetcode string_to_integer', test_string_to_integer)
