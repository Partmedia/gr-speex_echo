/* -*- c++ -*- */
/* 
 * Copyright 2018 Kevin Zheng.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_SPEEX_ECHO_ECHO_CANCELLATION_VSS_IMPL_H
#define INCLUDED_SPEEX_ECHO_ECHO_CANCELLATION_VSS_IMPL_H

#include <speex/speex_echo.h> 

#include <speex_echo/echo_cancellation_vss.h>

namespace gr {
  namespace speex_echo {

    class echo_cancellation_vss_impl : public echo_cancellation_vss
    {
     private:
      SpeexEchoState *d_echo_state;
      int d_frame_size;
      int d_filter_length;

     public:
      echo_cancellation_vss_impl(int frame_size, int filter_length);
      ~echo_cancellation_vss_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace speex_echo
} // namespace gr

#endif /* INCLUDED_SPEEX_ECHO_ECHO_CANCELLATION_VSS_IMPL_H */

