# Copyright 2011,2012,2016 Free Software Foundation, Inc.
#
# This file was generated by gr_modtool, a tool from the GNU Radio framework
# This file is a part of gr-speex_echo
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Setup library
########################################################################
include(GrPlatform) #define LIB_SUFFIX

include_directories(${Boost_INCLUDE_DIR} ${SPEEX_INCLUDE_DIRS})
    
link_directories(${Boost_LIBRARY_DIRS} ${SPEEX_LIBRARY_DIRS})

list(APPEND speex_echo_sources
    echo_cancellation_vss_impl.cc
)

set(speex_echo_sources "${speex_echo_sources}" PARENT_SCOPE)
if(NOT speex_echo_sources)
	MESSAGE(STATUS "No C++ sources... skipping lib/")
	return()
endif(NOT speex_echo_sources)

add_library(gnuradio-speex_echo SHARED ${speex_echo_sources})
target_link_libraries(
  gnuradio-speex_echo
  ${Boost_LIBRARIES}
  ${GNURADIO_ALL_LIBRARIES}
  ${SPEEX_LIBRARIES}
)
set_target_properties(gnuradio-speex_echo PROPERTIES DEFINE_SYMBOL "gnuradio_speex_echo_EXPORTS")

if(APPLE)
    set_target_properties(gnuradio-speex_echo PROPERTIES
        INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
    )
endif(APPLE)

########################################################################
# Install built library files
########################################################################
include(GrMiscUtils)
GR_LIBRARY_FOO(gnuradio-speex_echo RUNTIME_COMPONENT "speex_echo_runtime" DEVEL_COMPONENT "speex_echo_devel")

########################################################################
# Build and register unit test
########################################################################
include(GrTest)

include_directories(${CPPUNIT_INCLUDE_DIRS})

list(APPEND test_speex_echo_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/test_speex_echo.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/qa_speex_echo.cc
)

add_executable(test-speex_echo ${test_speex_echo_sources})

target_link_libraries(
  test-speex_echo
  ${GNURADIO_RUNTIME_LIBRARIES}
  ${Boost_LIBRARIES}
  ${CPPUNIT_LIBRARIES}
  ${SPEEX_LIBRARIES}
  gnuradio-speex_echo
)

GR_ADD_TEST(test_speex_echo test-speex_echo)

########################################################################
# Print summary
########################################################################
message(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Building for version: ${VERSION} / ${LIBVER}")

