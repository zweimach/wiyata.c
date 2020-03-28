lib_to_lower = library('to_lower',
    sources: 'to_lower.c')

test_to_lower = executable('to_lower_test',
    sources: 'to_lower-test.c',
    link_with: lib_to_lower,
    dependencies: dep_cmocka)

test('open_kattis to_lower', test_to_lower)
