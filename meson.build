project('wiyata', 'c',
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
m_dep = cc.find_library('m', required: false)

cmocka_dep = dependency('cmocka')

subdir('advent_of_code')
subdir('codeforces')
subdir('codewars')
subdir('hacker_rank')
subdir('leetcode')
subdir('open_kattis')
subdir('tlx_toki')
