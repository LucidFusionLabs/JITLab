# $Id: CMakeLists.txt 1334 2014-11-28 09:14:21Z justin $

add_executable(calculator calculator.cpp)
target_compile_definitions(calculator PUBLIC -DLFL_CLING)
target_include_directories(calculator PUBLIC ${LIBCLING_INCLUDE})
target_link_libraries(calculator ${LFL_APP_LIB} app_null_os app_null_framework app_null_graphics
                      app_null_audio app_null_camera app_opencv_matrix app_null_fft app_simple_loader
                      app_simple_resampler app_iconv_convert app_stdregex_regex app_null_sregex
                      app_libpng_png app_null_jpeg app_null_gif app_null_ogg app_libcss_css app_null_ttf
                      app_null_ssl app_null_js app_null_tu ${LIBCLING_LIB})
