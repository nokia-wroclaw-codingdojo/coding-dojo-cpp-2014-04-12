cmake_minimum_required(VERSION 2.8)

project(SoundexDojo)
set(applicatioName "SoundexDojo")

set(boostHeaders $ENV{BOOST_ROOT})

#library headers
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "--std=c++11")
endif()

message("-- Boost path: " ${boostHeaders})

#linking library
set(boostLib ${boostHeaders}/stage/lib)

#to build test -Dtarget=test
set(target release CACHE STRING "release")

#common headers
include_directories(
  ${boostHeaders}
  ${CMAKE_CURRENT_SOURCE_DIR}/application
)

#common source - to see headers in IDE
file(GLOB_RECURSE appHeader ${CMAKE_CURRENT_SOURCE_DIR}/application/*.hpp)

#common source
file(GLOB_RECURSE appSrc ${CMAKE_CURRENT_SOURCE_DIR}/application/class/*.cpp)

link_directories(${boostLib})

if(${target} STREQUAL "test")
  message("-- Target Test")
  set(applicatioName "SoundexDojoTests")
  if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    #i dont know why find_package wont work with gcc/clang
    set(targetSpecyficLib ${boostLib}/libboost_test_exec_monitor.a)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
  else()  
    find_package(Boost COMPONENTS unit_test_framework)
  endif()
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)
  set(mainFile  ${CMAKE_CURRENT_SOURCE_DIR}/test/main_test.cpp)
  file(GLOB_RECURSE targetSpecSrc ${CMAKE_CURRENT_SOURCE_DIR}/test/testCase/*.cpp)
  file(GLOB_RECURSE targetSpecHeader ${CMAKE_CURRENT_SOURCE_DIR}/test/*.hpp)

else()

  message("-- Target Release")
  set(mainFile ${CMAKE_CURRENT_SOURCE_DIR}/application/main.cpp)
  set(targetSpecyficLib "") #add lib only for release
  set(targetSpecSrc "")
  set(targetSpecHeader "")

endif()

add_executable(
  ${applicatioName}
  ${mainFile} 
  ${targetSpecOwnLib}
  ${targetSpecSrc}
  ${appSrc}

  ${targetSpecHeader}
  ${appHeader}
)

target_link_libraries(${applicatioName} ${targetSpecyficLib} ${targetSpecOwnLib})

