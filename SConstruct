src_files = []
libs = []
cpp_flags = []
opt_flags = []

src_files += [
    'src/ExprSysEnums.cpp',
    'src/Fact.cpp',
    'src/LogicOperations.cpp',
    'src/Node.cpp',
    'src/Operation.cpp',
    'src/Tree.cpp',
    'src/backwardChainingAlgo.cpp',
    'src/visual.cpp',
    'src/Exceptions.cpp',
    'lex.yy.cpp',
    'main.cpp',
]

libs += [
    'fl',
]

cpp_flags += [
    '-I.',
    '-Isrc',
]

opt_flags += [
    '-O0',
    '-std=c++11',
]

Program(target='build/main',
        source=src_files,
        CPPFLAGS=cpp_flags,
        LIBS=libs,
        #LIBPATH=['/usr/local/lib'],
)
