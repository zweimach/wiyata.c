lib_fizzbuzz = library('fizzbuzz',
    sources: 'fizzbuzz.c')

test_fizzbuzz = executable('fizzbuzz_test',
    sources: 'fizzbuzz-test.c',
    link_with: lib_fizzbuzz,
    dependencies: dep_cmocka)

test('open_kattis fizzbuzz', test_fizzbuzz)
