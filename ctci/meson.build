project('ctci', ['cpp'])

programs1 = {
    'unique': files(['1/1.1/unique.cc']),
    'permutation': files(['1/1.2/permutation.cc']),
    'urlify': files(['1/1.3/urlify.cc']),
    'palindrome': files(['1/1.4/palindrome.cc']),
    'one-away': files(['1/1.5/one-away.cc']),
    'compression': files(['1/1.6/compression.cc']),
    'rotate90': files(['1/1.7/rotate90.cc']),
}

foreach program, sources : programs1
    exe = executable(program, sources)
endforeach

programs2 = {
    'removedups': files(['2/2.1/remove-dups.cc'])
}

foreach program, sources : programs2
    exe = executable(program, sources)
    test(program, exe, suite: ['2'])
endforeach