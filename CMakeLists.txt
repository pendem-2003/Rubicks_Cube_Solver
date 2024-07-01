cmake_minimum_required(VERSION 3.28)
project(Rubicks_Cube_Solver)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rubicks_Cube_Solver main.cpp
        model/Rubickscube.cpp
        model/Rubickscube.h
        model/Rubickscube3dArray.cpp
        model/Rubickscube1dArray.cpp
        model/RubickscubeBitboard.cpp
        Solver/DFSSolver.h
        Solver/BFSSolver.h
        Solver/IDDFSSolver.h
        PatternDatabases/NibbleArray.h
        PatternDatabases/NibbleArray.cpp
        PatternDatabases/PatternDatabase.h
        PatternDatabases/PatternDatabase.cpp
        PatternDatabases/CornerPatternDatabase.h
        PatternDatabases/CornerPatternDatabase.cpp
        PatternDatabases/PermutationIndexer.h
        PatternDatabases/math.h
        PatternDatabases/math.cpp
        PatternDatabases/CornerDBMaker.h
        PatternDatabases/CornerDBMaker.cpp
)
