includes = include_directories('.')

lib_alternate_case = library('alternate_case',
    sources: 'alternate_case.c')

dep_alternate_case = declare_dependency(
    link_with: lib_alternate_case,
    include_directories: includes)

lib_bouncing_balls = library('bouncing_balls',
    sources: 'bouncing_balls.c')

dep_bouncing_balls = declare_dependency(
    link_with: lib_bouncing_balls,
    include_directories: includes)

lib_consecutive_strings = library('consecutive_strings',
    sources: 'consecutive_strings.c')

dep_consecutive_strings = declare_dependency(
    link_with: lib_consecutive_strings,
    include_directories: includes)

lib_n_th_power = library('n-th_power',
    sources: 'n-th_power.c',
    dependencies: dep_m)

lib_how_much = library('how_much',
    sources: 'how_much.c')

dep_how_much = declare_dependency(
    link_with: lib_how_much,
    include_directories: includes)

lib_maximum_length_difference = library('maximum_length_difference',
    sources: 'maximum_length_difference.c')

dep_maximum_length_difference = declare_dependency(
    link_with: lib_maximum_length_difference,
    include_directories: includes)

dep_n_th_power = declare_dependency(
    link_with: lib_n_th_power,
    include_directories: includes)

lib_ones_and_zeros = library('ones_and_zeros',
    sources: 'ones_and_zeros.c',
    dependencies: dep_m)

dep_ones_and_zeros = declare_dependency(
    link_with: lib_ones_and_zeros,
    include_directories: includes)

lib_reverse_list_recursively = library('reverse_list_recursively',
    sources: 'reverse_list_recursively.c')

dep_reverse_list_recursively = declare_dependency(
    link_with: lib_reverse_list_recursively,
    include_directories: includes)

lib_sorted_yes_no_how = library('sorted_yes_no_how',
    sources: 'sorted_yes_no_how.c')

dep_sorted_yes_no_how = declare_dependency(
    link_with: lib_sorted_yes_no_how,
    include_directories: includes)

lib_string_repeat = library('string_repeat',
    sources: 'string_repeat.c')

dep_string_repeat = declare_dependency(
    link_with: lib_string_repeat,
    include_directories: includes)

lib_who_likes_it = library('who_likes_it',
    sources: 'who_likes_it.c')

dep_who_likes_it = declare_dependency(
    link_with: lib_who_likes_it,
    include_directories: includes)

test_alternate_case = executable('alternate_case_test',
    sources: 'alternate_case_test.c',
    dependencies: [dep_cmocka, dep_alternate_case])

test('codewars alternate_case', test_alternate_case)

test_bouncing_balls = executable('bouncing_balls_test',
    sources: 'bouncing_balls_test.c',
    dependencies: [dep_cmocka, dep_bouncing_balls])

test('codewars bouncing_balls', test_bouncing_balls)

test_consecutive_strings = executable('consecutive_strings_test',
    sources: 'consecutive_strings_test.c',
    dependencies: [dep_cmocka, dep_consecutive_strings])

test('codewars consecutive_strings', test_consecutive_strings)

test_how_much = executable('how_much_test',
    sources: 'how_much_test.c',
    dependencies: [dep_cmocka, dep_how_much])

test('codewars how_much', test_how_much)

test_maximum_length_difference = executable('maximum_length_difference_test',
    sources: 'maximum_length_difference_test.c',
    dependencies: [dep_cmocka, dep_maximum_length_difference])

test('codewars maximum_length_difference', test_maximum_length_difference)

test_n_th_power = executable('n-th_power_test',
    sources: 'n-th_power_test.c',
    dependencies: [dep_cmocka, dep_n_th_power])

test('codewars n-th_power', test_n_th_power)

test_ones_and_zeros = executable('ones_and_zeros_test',
    sources: 'ones_and_zeros_test.c',
    dependencies: [dep_cmocka, dep_ones_and_zeros])

test('codewars ones_and_zeros', test_ones_and_zeros)

test_reverse_list_recursively = executable('reverse_list_recursively_test',
    sources: 'reverse_list_recursively_test.c',
    dependencies: [dep_cmocka, dep_reverse_list_recursively])

test('codewars reverse_list_recursively', test_reverse_list_recursively)

test_sorted_yes_no_how = executable('sorted_yes_no_how_test',
    sources: 'sorted_yes_no_how_test.c',
    dependencies: [dep_cmocka, dep_sorted_yes_no_how])

test('codewars sorted_yes_no_how', test_sorted_yes_no_how)

test_string_repeat = executable('string_repeat_test',
    sources: 'string_repeat_test.c',
    dependencies: [dep_cmocka, dep_string_repeat])

test('codewars string_repeat', test_string_repeat)

test_who_likes_it = executable('who_likes_it_test',
    sources: 'who_likes_it_test.c',
    dependencies: [dep_cmocka, dep_who_likes_it])

test('codewars who_likes_it', test_who_likes_it)
