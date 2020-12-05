includes = include_directories('.')

lib_report_repair = library('report_repair',
    sources: 'report_repair.c')

dep_report_repair = declare_dependency(
    link_with: lib_report_repair,
    include_directories: includes)

lib_not_quite_lisp = library('not_quite_lisp',
    sources: 'not_quite_lisp.c')

dep_not_quite_lisp = declare_dependency(
    link_with: lib_not_quite_lisp,
    include_directories: includes)
