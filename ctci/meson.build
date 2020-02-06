project('ctci', ['cpp'])

programs = {
    'unique': files(['1/1.1/unique.cc']),
    'permutation': files(['1/1.2/permutation.cc']),
    'urlify': files(['1/1.3/urlify.cc']),
    'palindrome': files(['1/1.4/palindrome.cc']),
    'one-away': files(['1/1.5/one-away.cc']),
    'compression': files(['1/1.6/compression.cc'])
}

foreach program, sources : programs
    executable(program, sources)
endforeach