lib_pot = library('pot',
    sources: 'pot.c',
    dependencies: dep_m)

test_pot = executable('pot_test',
    sources: 'pot-test.c',
    link_with: lib_pot,
    dependencies: dep_cmocka)

test('open_kattis pot', test_pot)
