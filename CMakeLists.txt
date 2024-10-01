cmake_minimum_required(VERSION 3.30.0)

project(design_patterns)

set(patterns "")

add_subdirectory(behavioral/visitor)

message("Adding the following patterns")
foreach(pattern IN ITEMS ${patterns})
    message("- ${pattern}")
endforeach()