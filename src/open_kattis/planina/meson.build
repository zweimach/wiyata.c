lib_planina = library('planina',
    sources: 'planina.c',
    dependencies: dep_m)

test_planina = executable('planina_test',
    sources: 'planina-test.c',
    link_with: lib_planina,
    dependencies: dep_cmocka)

test('open_kattis planina', test_planina)
