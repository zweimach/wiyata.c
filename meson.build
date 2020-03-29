project('wiyata',
    'c',
    version : '0.0.0',
    license: 'MIT',
    subproject_dir: 'lib',
    default_options: ['c_std=c11', 'default_library=static']
)

cc = meson.get_compiler('c')
dep_m = cc.find_library('m', required : false)

dep_cmocka = subproject('cmocka').get_variable('cmocka_dep')

subdir('src')
