/* -*- c++ -*- */

#define SPEEX_ECHO_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "speex_echo_swig_doc.i"

%{
#include "speex_echo/echo_cancellation_vss.h"
%}


%include "speex_echo/echo_cancellation_vss.h"
GR_SWIG_BLOCK_MAGIC2(speex_echo, echo_cancellation_vss);
