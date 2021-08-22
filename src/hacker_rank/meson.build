includes = include_directories('.')

lib_counting_valleys = library('counting_valleys',
    sources: 'counting_valleys.c')

dep_counting_valleys = declare_dependency(
    link_with: lib_counting_valleys,
    include_directories: includes)

lib_prime_or_not = library('prime_or_not',
    sources: 'prime_or_not.c')

dep_prime_or_not = declare_dependency(
    link_with: lib_prime_or_not,
    include_directories: includes)
