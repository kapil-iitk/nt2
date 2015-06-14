//==============================================================================
//          Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIG_DERIVATIVES_FUNCTIONS_GENERIC_D_CSCPI_HPP_INCLUDED
#define NT2_TRIG_DERIVATIVES_FUNCTIONS_GENERIC_D_CSCPI_HPP_INCLUDED
#include <nt2/trig_derivatives/functions/d_cscpi.hpp>
#include <nt2/include/functions/d_csc.hpp>
#include <nt2/include/constants/pi.hpp>

namespace nt2 { namespace ext
{

  BOOST_DISPATCH_IMPLEMENT  ( d_cscpi_, tag::cpu_
                            , (A0)
                            , (generic_<unspecified_<A0>>)
                            )
  {
    typedef A0 result_type;
    BOOST_FORCEINLINE result_type operator()(const A0& u) const
    {
      return -cscpi(u)*Pi<A0>()*cotpi(u);
    };
  };
} }


#endif
