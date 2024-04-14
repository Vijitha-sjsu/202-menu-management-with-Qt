# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/menu-management_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/menu-management_autogen.dir/ParseCache.txt"
  "menu-management_autogen"
  )
endif()
