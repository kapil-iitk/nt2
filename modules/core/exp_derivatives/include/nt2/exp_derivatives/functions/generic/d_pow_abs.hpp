//==============================================================================
//          Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_EXP_DERIVATIVES_FUNCTIONS_GENERIC_D_POW_ABS_HPP_INCLUDED
#define NT2_EXP_DERIVATIVES_FUNCTIONS_GENERIC_D_POW_ABS_HPP_INCLUDED
#include <nt2/exp_derivatives/functions/d_pow_abs.hpp>

namespace nt2 { namespace ext
{

  BOOST_DISPATCH_IMPLEMENT  ( d_pow_abs_, tag::cpu_
                            , (A0)
                            , (generic_<unspecified_<A0>>)
                            )
  {
    typedef A0 result_type;
    BOOST_FORCEINLINE result_type operator()(const A0& u) const
    {
      return ;
    }
  };
} }


#endif
