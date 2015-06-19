set(the_description "The ts module")

if(IOS)
  ocv_module_disable(ts)
endif()

set(OPENCV_MODULE_TYPE STATIC)
set(OPENCV_MODULE_IS_PART_OF_WORLD FALSE)

if(WINRT)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /ZW")
endif()

ocv_warnings_disable(CMAKE_CXX_FLAGS -Wundef)

if(NOT WINRT)
  ocv_add_module(ts INTERNAL opencv_core opencv_imgproc opencv_imgcodecs opencv_videoio opencv_highgui)
else()
  ocv_add_module(ts INTERNAL opencv_core opencv_imgproc opencv_imgcodecs opencv_videoio)
endif()

ocv_glob_module_sources()
ocv_module_include_directories()
ocv_create_module()
