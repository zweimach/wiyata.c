lib_herman = library('herman',
    sources: 'herman.c',
    dependencies: dep_m)

test_herman = executable('herman_test',
    sources: 'herman-test.c',
    link_with: lib_herman,
    dependencies: dep_cmocka)

test('open_kattis herman', test_herman)
