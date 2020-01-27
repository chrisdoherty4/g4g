# Build the GTest sources.
gtest = subproject('gtest')


executable('node-at-even-distance', 
    'Node.cc',
    'main.cc'
)

test = executable(
    'test-node-at-even-distance',
    'Node.cc',
    'test.cc',
    dependencies: gtest.get_variable('gtest_dep')
)

test('node at even distance test', test)