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


#ifndef INCLUDED_SPEEX_ECHO_ECHO_CANCELLATION_VSS_H
#define INCLUDED_SPEEX_ECHO_ECHO_CANCELLATION_VSS_H

#include <speex_echo/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace speex_echo {

    /*!
     * \brief Wrapper for speex_echo_cancellation in libspeexdsp
     * \ingroup speex_echo
     *
     */
    class SPEEX_ECHO_API echo_cancellation_vss : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<echo_cancellation_vss> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of speex_echo::echo_cancellation_vss.
       *
       * To avoid accidental use of raw pointers, speex_echo::echo_cancellation_vss's
       * constructor is in a private implementation
       * class. speex_echo::echo_cancellation_vss::make is the public interface for
       * creating new instances.
       */
      static sptr make(int frame_size, int filter_length);
    };

  } // namespace speex_echo
} // namespace gr

#endif /* INCLUDED_SPEEX_ECHO_ECHO_CANCELLATION_VSS_H */

