cmake_minimum_required(VERSION 3.0.0)
project(project_name VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${PROJECT_SOURCE_DIR}/src/include)
include(GoogleTest)

add_library(project_library src/add.cpp)


enable_testing()
function(create_test name files)
    add_executable(${name} ${files})
    target_link_libraries(${name}  project_library GTest::gtest_main)
  
endfunction(create_test)

create_test(add_test tests/add_test.cpp)