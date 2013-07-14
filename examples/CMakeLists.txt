###################################################################################################
##
##      Информация о проекте
##
###################################################################################################

project(Meta)
cmake_minimum_required(VERSION 2.8)

###################################################################################################
##
##      Сборка примеров
##
###################################################################################################

file(GLOB_RECURSE EXAMPLE_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} *.cpp)

foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    set(EXAMPLE ${EXAMPLE_SOURCE})

    string(REPLACE ".cpp" "" EXAMPLE ${EXAMPLE})
    string(REPLACE "/" "_" EXAMPLE ${EXAMPLE})
    string(REPLACE "examples_" "" EXAMPLE ${EXAMPLE})

    add_executable(${EXAMPLE} ${CMAKE_SOURCE_DIR}/${EXAMPLE_SOURCE})

    set(EXAMPLES ${EXAMPLES} ${EXAMPLE})
endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})

add_custom_target(eg DEPENDS ${EXAMPLES})
