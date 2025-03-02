
cmake_minimum_required(VERSION 3.25)
project(Competitions)

set(CMAKE_CXX_STANDARD 17)

# Включаем санитайзеры
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -fno-omit-frame-pointer")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address,undefined")
endif()

#add_executable(Competitions coding/Leetcode/Data_Stream/task_1352.cpp)
#add_executable(Competitions coding/Leetcode/DS_A/task_1143.cpp)
#add_executable(Competitions coding/Leetcode/Dynamic_Programming/task_121.cpp)
#add_executable(Competitions coding/Leetcode/Design/task_432.cpp)
#add_executable(Competitions coding/Leetcode/Tasks/task_1474.cpp) linked list
#add_executable(Competitions coding/Leetcode/Tasks/task_2460.cpp)
#add_executable(Competitions coding/Leetcode/BitManip/task_762.cpp)
#add_executable(Competitions coding/Leetcode/prefix_sum/task_3028.cpp)
#add_executable(Competitions coding/Leetcode/Biweekly_Leetcode/Biweekly_Contest_151/q2_2.cpp)
add_executable(Competitions coding/Leetcode/Weekly_Leetcode/Weekly_Contest_439/q2.cpp)
#add_executable(Competitions coding/Codeforces/round_955/ta/sk_A.cpp)
#add_executable(Competitions coding/Codeforces/ed_round_167/task_A.cpp)

#add_executable(Competitions coding/CodeRun/back/task_257.cpp)
