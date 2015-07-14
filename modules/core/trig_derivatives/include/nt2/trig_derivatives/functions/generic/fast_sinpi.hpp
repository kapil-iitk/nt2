//==============================================================================
//          Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIG_DERIVATIVES_FUNCTIONS_GENERIC_FAST_SINPI_HPP_INCLUDED
#define NT2_TRIG_DERIVATIVES_FUNCTIONS_GENERIC_FAST_SINPI_HPP_INCLUDED
#include <nt2/trigonometric/include/functions/fast_sinpi.hpp>
#include <nt2/include/functions/simd/fast_sinpi.hpp>
#include <nt2/include/functions/simd/fast_cospi.hpp>
#include <nt2/include/functions/simd/pow.hpp>
#include <nt2/include/functions/simd/unary_minus.hpp>
#include <nt2/include/constants/invpi.hpp>
#include <nt2/include/functor.hpp>

namespace nt2
{
  namespace ext
  {

    BOOST_DISPATCH_IMPLEMENT  ( fast_sinpi_, tag::cpu_
                              , (order)(A0)
                              , (unspecified_<order>)
                                (generic_<unspecified_<A0>>)
                              )
    {
      typedef A0                                            result_type;
      typedef typename meta::scalar_of<A0>::type                    sA0;
      typedef typename boost::mpl::long_<order::value % 4>     ordermod4;
      BOOST_FORCEINLINE result_type operator()(const order&
                                              , const A0& u) const
      {
        return compute(order(), u)*pow<order::value>(Invpi<sA0>());
      }
    private:
      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<0>
                                           , const A0& u) const
      {
        return fast_sinpi(u);
      }
      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<1>
                                           , const A0& u) const
      {
        return fast_cospi(u);
      }
      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<2>
                                           , const A0& u) const
      {
        return -fast_sinpi(u);
      }
      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<3>
                                           , const A0& u) const
      {
        return -fast_cospi(u);
      }
   };
  }
}


#endif
