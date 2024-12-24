#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mongo::bsoncxx_shared" for configuration "Release"
set_property(TARGET mongo::bsoncxx_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(mongo::bsoncxx_shared PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libbsoncxx.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "mongo::bson_shared"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libbsoncxx.dll"
  )

list(APPEND _cmake_import_check_targets mongo::bsoncxx_shared )
list(APPEND _cmake_import_check_files_for_mongo::bsoncxx_shared "${_IMPORT_PREFIX}/lib/libbsoncxx.dll.a" "${_IMPORT_PREFIX}/bin/libbsoncxx.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
