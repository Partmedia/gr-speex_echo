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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "echo_cancellation_vss_impl.h"

namespace gr {
  namespace speex_echo {

    echo_cancellation_vss::sptr
    echo_cancellation_vss::make(int frame_size, int filter_length)
    {
      return gnuradio::get_initial_sptr
        (new echo_cancellation_vss_impl(frame_size, filter_length));
    }

    /*
     * The private constructor
     */
    echo_cancellation_vss_impl::echo_cancellation_vss_impl(int frame_size, int filter_length)
      : gr::sync_block("echo_cancellation_vss",
              gr::io_signature::make(2, 2, frame_size * sizeof(short)),
              gr::io_signature::make(1, 1, frame_size * sizeof(short)))
    {
        d_echo_state = speex_echo_state_init(frame_size, filter_length);
        d_frame_size = frame_size;
        d_filter_length = filter_length;
    }

    /*
     * Our virtual destructor.
     */
    echo_cancellation_vss_impl::~echo_cancellation_vss_impl()
    {
        speex_echo_state_destroy(d_echo_state);
    }

    int
    echo_cancellation_vss_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const short *input_frame = (const short *) input_items[0];
      const short *echo_frame = (const short *) input_items[1];
      short *out = (short *) output_items[0];
      for (size_t i = 0; i < noutput_items; i++) {
          speex_echo_cancellation(d_echo_state,
                  &input_frame[i*d_frame_size], &echo_frame[i*d_frame_size],
                  &out[i*d_frame_size]);
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace speex_echo */
} /* namespace gr */

