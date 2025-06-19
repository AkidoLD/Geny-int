# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Geny-int_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Geny-int_autogen.dir/ParseCache.txt"
  "Geny-int_autogen"
  )
endif()
