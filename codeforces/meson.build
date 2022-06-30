includes = include_directories('.')

lib_reorder = library('reorder',
    sources: 'reorder.c')

dep_reorder = declare_dependency(
    link_with: lib_reorder,
    include_directories: includes)

test_reorder = executable('reorder_test',
    sources: 'reorder_test.c',
    dependencies: [dep_cmocka, dep_reorder])

test('codeforces reorder', test_reorder)
