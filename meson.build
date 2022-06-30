project('wiyata',
    'c',
    version : '0.0.0',
    license: 'MIT',
    subproject_dir: 'third-party',
    default_options: [
        'c_std=c11',
        'default_library=static',
        'warning_level=2',
        'werror=true',
    ],
)

cc = meson.get_compiler('c')
dep_m = cc.find_library('m', required: false)

dep_cmocka = dependency('cmocka', fallback: ['cmocka', 'cmocka_dep'])

subdir('advent_of_code')
subdir('codeforces')
subdir('codewars')
subdir('hacker_rank')
subdir('leetcode')
subdir('open_kattis')
subdir('tlx_toki')
