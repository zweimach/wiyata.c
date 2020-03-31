lib_reversed_binary_numbers = library('reversed_binary_numbers',
    sources: 'reversed_binary_numbers.c',
    dependencies: dep_m)

test_reversed_binary_numbers = executable('reversed_binary_numbers_test',
    sources: 'reversed_binary_numbers-test.c',
    link_with: lib_reversed_binary_numbers,
    dependencies: dep_cmocka)

test('open_kattis reversed_binary_numbers', test_reversed_binary_numbers)
