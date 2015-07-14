//==============================================================================
//          Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_HYP_DERIVATIVES_FUNCTIONS_GENERIC_ATAN_HPP_INCLUDED
#define NT2_HYP_DERIVATIVES_FUNCTIONS_GENERIC_ATAN_HPP_INCLUDED
#include <nt2/include/functions/simd/atanh.hpp>
#include <nt2/include/functions/simd/sinh.hpp>
#include <nt2/include/functions/simd/factorial.hpp>
#include <nt2/include/functions/simd/multiplies.hpp>
#include <nt2/include/functions/simd/oneminus.hpp>
#include <nt2/include/functions/simd/oneplus.hpp>
#include <nt2/include/functions/simd/minusone.hpp>
#include <nt2/include/functions/simd/rec.hpp>
#include <nt2/include/functions/simd/sinh.hpp>
#include <nt2/include/functions/simd/cosh.hpp>
#include <nt2/include/functions/simd/sqr.hpp>
#include <nt2/include/functions/simd/unary_minus.hpp>
#include <nt2/include/constants/two.hpp>
#include <nt2/include/functor.hpp>

namespace nt2
{
  namespace ext
  {

    BOOST_DISPATCH_IMPLEMENT  ( atanh_, tag::cpu_
                              , (order)(A0)
                              , (unspecified_<order>)
                                (generic_<unspecified_<A0>>)
                              )
    {
      typedef A0                                            result_type;
      typedef typename meta::scalar_of<A0>::type                    sA0;
      BOOST_FORCEINLINE result_type operator()(const order&
                                              , const A0& u) const
      {
        return compute(order(), u);
      }
    private:
      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<0>
                                           , const A0& u) const
      {
        return atanh(u);
      }
      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<1>
                                           , const A0& u) const
      {
        return rec(oneminus(sqr(u)));
      }
      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<2>
                                           , const A0& u) const
      {
        return sqr(rec(oneminus(sqr(u))))*Two<result_type>()*u;
      }
      template<long P>
      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<P>
                                             , const A0& u) const
      {
        return compute1(boost::mpl::long_<P>(), u, boost::mpl::long_<P%2>());
      }
      template<long P>
      BOOST_FORCEINLINE result_type compute1(const boost::mpl::long_<P>
                                            , const A0& u
                                            , const boost::mpl::long_<1> ) const
      {
        return factorial(sA0(P-1))*rec(pow<P>(sqrt(oneminus(sqr(u)))))*cosh(sA0(P)*atanh(u));
      }
      template<long P>
      BOOST_FORCEINLINE result_type compute1(const boost::mpl::long_<P>
                                            , const A0& u
                                            , const boost::mpl::long_<0> ) const
      {
        return factorial(sA0(P-1))*rec(pow<P>(sqrt(oneminus(sqr(u)))))*sinh(sA0(P)*atanh(u));
      }
   };
  }
}


#endif
