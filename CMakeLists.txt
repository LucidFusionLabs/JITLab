# $Id: CMakeLists.txt 1334 2014-11-28 09:14:21Z justin $

if(LFL_LIBCLING)
lfl_add_target(calculator EXECUTABLE SOURCES calculator.cpp
               COMPILE_DEFINITIONS -DLFL_CLING
               INCLUDE_DIRECTORIES ${LIBCLING_INCLUDE}
               LINK_LIBRARIES ${LFL_APP_LIB} app_null_framework app_null_graphics
               app_null_audio app_null_camera app_opencv_matrix app_null_fft app_simple_loader
               app_simple_resampler app_iconv_convert app_stdregex_regex app_null_sregex
               app_libpng_png app_null_jpeg app_null_gif app_null_ogg app_libcss_css app_null_ttf
               app_null_ssl app_null_js app_null_tu ${LIBCLING_LIB} ${LFL_APP_OS})
endif()
