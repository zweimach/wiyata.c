lib_autori = library('autori',
    sources: 'autori.c')

test_autori = executable('autori_test',
    sources: 'autori-test.c',
    link_with: lib_autori,
    dependencies: dep_cmocka)

test('open_kattis autori', test_autori)
