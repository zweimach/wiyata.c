includes = include_directories('.')

lib_autori = library('autori',
    sources: 'autori.c')

dep_autori = declare_dependency(
    link_with: lib_autori,
    include_directories: includes)

lib_batter_up = library('batter_up',
    sources: 'batter_up.c',
    dependencies: dep_m)

dep_batter_up = declare_dependency(
    link_with: lib_batter_up,
    include_directories: includes)

lib_bijele = library('bijele',
    sources: 'bijele.c')

dep_bijele = declare_dependency(
    link_with: lib_bijele,
    include_directories: includes)

lib_cold_puter_science = library('cold_puter_science',
    sources: 'cold_puter_science.c')

dep_cold_puter_science = declare_dependency(
    link_with: lib_cold_puter_science,
    include_directories: includes)

lib_death_knight_hero = library('death_knight_hero',
    sources: 'death_knight_hero.c')

dep_death_knight_hero = declare_dependency(
    link_with: lib_death_knight_hero,
    include_directories: includes)

lib_faktor = library('faktor',
    sources: 'faktor.c')

dep_faktor = declare_dependency(
    link_with: lib_faktor,
    include_directories: includes)

lib_fizzbuzz = library('fizzbuzz',
    sources: 'fizzbuzz.c')

dep_fizzbuzz = declare_dependency(
    link_with: lib_fizzbuzz,
    include_directories: includes)

lib_ladder = library('ladder',
    sources: 'ladder.c',
    dependencies: dep_m)

dep_ladder = declare_dependency(
    link_with: lib_ladder,
    include_directories: includes)

lib_modulo = library('modulo',
    sources: 'modulo.c')

dep_modulo = declare_dependency(
    link_with: lib_modulo,
    include_directories: includes)

lib_nasty_hacks = library('nasty_hacks',
    sources: 'nasty_hacks.c')

dep_nasty_hacks = declare_dependency(
    link_with: lib_nasty_hacks,
    include_directories: includes)

lib_herman = library('herman',
    sources: 'herman.c',
    dependencies: dep_m)

dep_herman = declare_dependency(
    link_with: lib_herman,
    include_directories: includes)

lib_knapsack = library('knapsack',
    sources: 'knapsack.c',
    dependencies: dep_m)

dep_knapsack = declare_dependency(
    link_with: lib_knapsack,
    include_directories: includes)

lib_number_fun = library('number_fun',
    sources: 'number_fun.c')

dep_number_fun = declare_dependency(
    link_with: lib_number_fun,
    include_directories: includes)

lib_oddities = library('oddities',
    sources: 'oddities.c')

dep_oddities = declare_dependency(
    link_with: lib_oddities,
    include_directories: includes)

lib_planina = library('planina',
    sources: 'planina.c',
    dependencies: dep_m)

dep_planina = declare_dependency(
    link_with: lib_planina,
    include_directories: includes)

lib_pot = library('pot',
    sources: 'pot.c',
    dependencies: dep_m)

dep_pot = declare_dependency(
    link_with: lib_pot,
    include_directories: includes)

lib_quadrant_selection = library('quadrant_selection',
    sources: 'quadrant_selection.c',
    dependencies: dep_m)

dep_quadrant_selection = declare_dependency(
    link_with: lib_quadrant_selection,
    include_directories: includes)

lib_r2 = library('r2',
    sources: 'r2.c')

dep_r2 = declare_dependency(
    link_with: lib_r2,
    include_directories: includes)

lib_quick_brown_fox = library('quick_brown_fox',
    sources: 'quick_brown_fox.c')

dep_quick_brown_fox = declare_dependency(
    link_with: lib_quick_brown_fox,
    include_directories: includes)

lib_reversed_binary_numbers = library('reversed_binary_numbers',
    sources: 'reversed_binary_numbers.c',
    dependencies: dep_m)

dep_reversed_binary_numbers = declare_dependency(
    link_with: lib_reversed_binary_numbers,
    include_directories: includes)

lib_stuck_in_a_time_loop = library('stuck_in_a_time_loop',
    sources: 'stuck_in_a_time_loop.c')

dep_stuck_in_a_time_loop = declare_dependency(
    link_with: lib_stuck_in_a_time_loop,
    include_directories: includes)

lib_take_two_stones = library('take_two_stones',
    sources: 'take_two_stones.c')

dep_take_two_stones = declare_dependency(
    link_with: lib_take_two_stones,
    include_directories: includes)

lib_tarifa = library('tarifa',
    sources: 'tarifa.c')

dep_tarifa = declare_dependency(
    link_with: lib_tarifa,
    include_directories: includes)

lib_to_lower = library('to_lower',
    sources: 'to_lower.c')

dep_to_lower = declare_dependency(
    link_with: lib_to_lower,
    include_directories: includes)

lib_trik = library('trik',
    sources: 'trik.c')

dep_trik = declare_dependency(
    link_with: lib_trik,
    include_directories: includes)

lib_zamka = library('zamka',
    sources: 'zamka.c',
    dependencies: dep_m)

dep_zamka = declare_dependency(
    link_with: lib_zamka,
    include_directories: includes)

test_autori = executable('autori_test',
    sources: 'autori_test.c',
    dependencies: [dep_cmocka, dep_autori])

test('open_kattis autori', test_autori)

test_batter_up = executable('batter_up_test',
    sources: 'batter_up_test.c',
    dependencies: [dep_cmocka, dep_batter_up])

test('open_kattis batter_up', test_batter_up)

test_bijele = executable('bijele_test',
    sources: 'bijele_test.c',
    dependencies: [dep_cmocka, dep_bijele])

test('open_kattis bijele', test_bijele)

test_cold_puter_science = executable('cold_puter_science_test',
    sources: 'cold_puter_science_test.c',
    dependencies: [dep_cmocka, dep_cold_puter_science])

test('open_kattis cold_puter_science', test_cold_puter_science)

test_death_knight_hero = executable('death_knight_hero_test',
    sources: 'death_knight_hero_test.c',
    dependencies: [dep_cmocka, dep_death_knight_hero])

test('open_kattis death_knight_hero', test_death_knight_hero)

test_faktor = executable('faktor_test',
    sources: 'faktor_test.c',
    dependencies: [dep_cmocka, dep_faktor])

test('open_kattis faktor', test_faktor)

test_fizzbuzz = executable('fizzbuzz_test',
    sources: 'fizzbuzz_test.c',
    dependencies: [dep_cmocka, dep_fizzbuzz])

test('open_kattis fizzbuzz', test_fizzbuzz)

test_ladder = executable('ladder_test',
    sources: 'ladder_test.c',
    dependencies: [dep_cmocka, dep_ladder])

test('open_kattis ladder', test_ladder)

test_modulo = executable('modulo_test',
    sources: 'modulo_test.c',
    dependencies: [dep_cmocka, dep_modulo])

test('open_kattis modulo', test_modulo)

test_nasty_hacks = executable('nasty_hacks_test',
    sources: 'nasty_hacks_test.c',
    dependencies: [dep_cmocka, dep_nasty_hacks])

test('open_kattis nasty_hacks', test_nasty_hacks)

test_herman = executable('herman_test',
    sources: 'herman_test.c',
    dependencies: [dep_cmocka, dep_herman])

test('open_kattis herman', test_herman)

test_knapsack = executable('knapsack_test',
    sources: 'knapsack_test.c',
    dependencies: [dep_cmocka, dep_knapsack])

test('open_kattis knapsack', test_knapsack)

test_number_fun = executable('number_fun_test',
    sources: 'number_fun_test.c',
    dependencies: [dep_cmocka, dep_number_fun])

test('open_kattis number_fun', test_number_fun)

test_oddities = executable('oddities_test',
    sources: 'oddities_test.c',
    dependencies: [dep_cmocka, dep_oddities])

test('open_kattis oddities', test_oddities)

test_planina = executable('planina_test',
    sources: 'planina_test.c',
    dependencies: [dep_cmocka, dep_planina])

test('open_kattis planina', test_planina)

test_pot = executable('pot_test',
    sources: 'pot_test.c',
    dependencies: [dep_cmocka, dep_pot])

test('open_kattis pot', test_pot)

test_quadrant_selection = executable('quadrant_selection_test',
    sources: 'quadrant_selection_test.c',
    dependencies: [dep_cmocka, dep_quadrant_selection])

test('open_kattis quadrant_selection', test_quadrant_selection)

test_r2 = executable('r2_test',
    sources: 'r2_test.c',
    dependencies: [dep_cmocka, dep_r2])

test('open_kattis r2', test_r2)

test_quick_brown_fox = executable('quick_brown_fox_test',
    sources: 'quick_brown_fox_test.c',
    dependencies: [dep_cmocka, dep_quick_brown_fox])

test('open_kattis quick_brown_fox', test_quick_brown_fox)

test_reversed_binary_numbers = executable('reversed_binary_numbers_test',
    sources: 'reversed_binary_numbers_test.c',
    dependencies: [dep_cmocka, dep_reversed_binary_numbers])

test('open_kattis reversed_binary_numbers', test_reversed_binary_numbers)

test_stuck_in_a_time_loop = executable('stuck_in_a_time_loop_test',
    sources: 'stuck_in_a_time_loop_test.c',
    dependencies: [dep_cmocka, dep_stuck_in_a_time_loop])

test('open_kattis stuck_in_a_time_loop', test_stuck_in_a_time_loop)

test_take_two_stones = executable('take_two_stones_test',
    sources: 'take_two_stones_test.c',
    dependencies: [dep_cmocka, dep_take_two_stones])

test('open_kattis take_two_stones', test_take_two_stones)

test_tarifa = executable('tarifa_test',
    sources: 'tarifa_test.c',
    dependencies: [dep_cmocka, dep_tarifa])

test('open_kattis tarifa', test_tarifa)

test_to_lower = executable('to_lower_test',
    sources: 'to_lower_test.c',
    dependencies: [dep_cmocka, dep_to_lower])

test('open_kattis to_lower', test_to_lower)

test_trik = executable('trik_test',
    sources: 'trik_test.c',
    dependencies: [dep_cmocka, dep_trik])

test('open_kattis trik', test_trik)

test_zamka = executable('zamka_test',
    sources: 'zamka_test.c',
    dependencies: [dep_cmocka, dep_zamka])

test('open_kattis zamka', test_zamka)
