lib_batter_up = library('batter_up',
    sources: 'batter_up.c',
    dependencies: dep_m)

test_batter_up = executable('batter_up_test',
    sources: 'batter_up-test.c',
    link_with: lib_batter_up,
    dependencies: dep_cmocka)

test('open_kattis batter_up', test_batter_up)
