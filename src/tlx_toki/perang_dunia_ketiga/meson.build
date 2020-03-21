lib_perang_dunia_ketiga = library('perang_dunia_ketiga',
    sources: 'perang_dunia_ketiga.c')

test_perang_dunia_ketiga = executable('perang_dunia_ketiga_test',
    sources: 'perang_dunia_ketiga-test.c',
    link_with: lib_perang_dunia_ketiga,
    dependencies: dep_cmocka)

test('tlx_toki perang_dunia_ketiga', test_perang_dunia_ketiga)
