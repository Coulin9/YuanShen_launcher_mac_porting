#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "openjp2" for configuration "Release"
set_property(TARGET openjp2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(openjp2 PROPERTIES
  IMPORTED_LOCATION_RELEASE "/Users/gcenx/Documents/GitHub/cerbero/build/dist/darwin_x86_64/lib/libopenjp2.2.5.2.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libopenjp2.7.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS openjp2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_openjp2 "/Users/gcenx/Documents/GitHub/cerbero/build/dist/darwin_x86_64/lib/libopenjp2.2.5.2.dylib" )

# Import target "openjp2_static" for configuration "Release"
set_property(TARGET openjp2_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(openjp2_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "/Users/gcenx/Documents/GitHub/cerbero/build/dist/darwin_x86_64/lib/libopenjp2.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS openjp2_static )
list(APPEND _IMPORT_CHECK_FILES_FOR_openjp2_static "/Users/gcenx/Documents/GitHub/cerbero/build/dist/darwin_x86_64/lib/libopenjp2.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
