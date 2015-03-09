set(the_description "The ts module")

if(IOS)
  ocv_module_disable(ts)
endif()

set(OPENCV_MODULE_TYPE STATIC)
set(OPENCV_MODULE_IS_PART_OF_WORLD FALSE)
if(WINRT)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /ZW")
  add_env_definitions(OPENCV_TEST_DATA_PATH)
  add_env_definitions(OPENCV_PERF_VALIDATION_DIR)
  if(CMAKE_SYSTEM_NAME MATCHES WindowsStore AND CMAKE_SYSTEM_VERSION MATCHES "8.0")
    add_definitions("-DWIN80")
  endif()
endif()

ocv_warnings_disable(CMAKE_CXX_FLAGS -Wundef)

ocv_add_module(ts opencv_core opencv_imgproc opencv_imgcodecs opencv_videoio)

ocv_glob_module_sources()
ocv_module_include_directories()
ocv_create_module()
