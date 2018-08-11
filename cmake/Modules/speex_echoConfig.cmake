INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_SPEEX_ECHO speex_echo)

FIND_PATH(
    SPEEX_ECHO_INCLUDE_DIRS
    NAMES speex_echo/api.h
    HINTS $ENV{SPEEX_ECHO_DIR}/include
        ${PC_SPEEX_ECHO_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    SPEEX_ECHO_LIBRARIES
    NAMES gnuradio-speex_echo
    HINTS $ENV{SPEEX_ECHO_DIR}/lib
        ${PC_SPEEX_ECHO_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SPEEX_ECHO DEFAULT_MSG SPEEX_ECHO_LIBRARIES SPEEX_ECHO_INCLUDE_DIRS)
MARK_AS_ADVANCED(SPEEX_ECHO_LIBRARIES SPEEX_ECHO_INCLUDE_DIRS)

