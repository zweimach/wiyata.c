lib_restoran_chanek = library('restoran_chanek',
    sources: 'restoran_chanek.c')

test_restoran_chanek = executable('restoran_chanek_test',
    sources: 'restoran_chanek-test.c',
    link_with: lib_restoran_chanek,
    dependencies: dep_cmocka)

test('tlx_toki restoran_chanek', test_restoran_chanek)
