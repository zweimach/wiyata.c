includes = include_directories('.')

lib_report_repair = library('report_repair',
    sources: 'report_repair.c')

dep_report_repair = declare_dependency(
    link_with: lib_report_repair,
    include_directories: includes)

lib_rocket_equation = library('rocket_equation',
    sources: 'rocket_equation.c',
    dependencies: dep_m)

dep_rocket_equation = declare_dependency(
    link_with: lib_rocket_equation,
    include_directories: includes)

lib_not_quite_lisp = library('not_quite_lisp',
    sources: 'not_quite_lisp.c')

dep_not_quite_lisp = declare_dependency(
    link_with: lib_not_quite_lisp,
    include_directories: includes)

lib_there_would_be_no_math = library('there_would_be_no_math',
    sources: 'there_would_be_no_math.c')

dep_there_would_be_no_math = declare_dependency(
    link_with: lib_there_would_be_no_math,
    include_directories: includes)
