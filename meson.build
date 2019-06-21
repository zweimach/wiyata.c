project('wiyata',
    'c',
    version : '0.0.0',
    license: 'MIT',
    subproject_dir: 'lib',
    default_options: ['c_std=c11', 'default_library=static']
)

dep_cmocka = subproject('cmocka').get_variable('dep_cmocka')

subdir('src')
