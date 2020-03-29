lib_take_two_stones = library('take_two_stones',
    sources: 'take_two_stones.c')

test_take_two_stones = executable('take_two_stones_test',
    sources: 'take_two_stones-test.c',
    link_with: lib_take_two_stones,
    dependencies: dep_cmocka)

test('open_kattis take_two_stones', test_take_two_stones)
