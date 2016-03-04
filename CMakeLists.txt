# $Id: CMakeLists.txt 1334 2014-11-28 09:14:21Z justin $

add_executable(calculator calculator.cpp)
target_link_libraries(calculator ${LFL_APP_LIB} ${GTEST_LIB} app_null_os app_null_framework app_null_graphics
                      app_null_audio app_null_camera app_opencv_matrix app_null_fft app_simple_loader
                      app_simple_resampler app_iconv_convert app_regexp_regex app_libsregex_sregex
                      app_libpng_png app_null_jpeg app_null_gif app_libcss_css app_null_ttf app_null_ssl)

