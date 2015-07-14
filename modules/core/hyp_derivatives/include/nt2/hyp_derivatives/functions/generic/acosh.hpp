//==============================================================================
//          Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_HYP_DERIVATIVES_FUNCTIONS_GENERIC_ACOSH_HPP_INCLUDED
#define NT2_HYP_DERIVATIVES_FUNCTIONS_GENERIC_ACOSH_HPP_INCLUDED
#include <nt2/hyperbolic/include/functions/acosh.hpp>
#include <nt2/include/functions/simd/acosh.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/include/functions/simd/multiplies.hpp>
#include <nt2/include/functions/simd/plus.hpp>
#include <nt2/include/functions/simd/pow.hpp>
#include <nt2/include/functions/simd/minusone.hpp>
#include <nt2/include/functions/simd/rec.hpp>
#include <nt2/include/functions/simd/sqr.hpp>
#include <nt2/include/functions/simd/sqrt.hpp>
#include <nt2/include/functions/cospi.hpp>

namespace nt2
{
  namespace ext
  {

    BOOST_DISPATCH_IMPLEMENT  ( acosh_, tag::cpu_
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
        return acosh(u);
      }
      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<1>
                                           , const A0& u) const
      {
        return  rec(sqrt(minusone(sqr(u))));
      }

      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<2>
                                           , const A0& u) const
      {
        result_type tmp0 = rec(minusone(sqr(u)));
        result_type tmp = sqrt(tmp0);
        return -u*tmp*tmp0;
      }
//       BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<3>
//                                            , const A0& u) const
//       {
//         result_type u2 = sqr(u);
//         result_type tmp0 = rec(minusone(u2));
//         result_type tmp = sqrt(tmp0);
//         return oneplus(Two<sA0>()*u2)*tmp*sqr(tmp0);
//       }
//       BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<4>
//                                            , const A0& u) const
//       {
//         result_type u2 = sqr(u);
//         result_type tmp0 = minusone(u2);
//         return -rec(sqrt(tmp0)*pow<3>(tmp0))*Three<sA0>()*u*fma(Two<sA0>(), u2, Three<sA0>());
//       }
      template<long P>
      BOOST_FORCEINLINE result_type compute(const boost::mpl::long_<P>
                                           , const A0& u) const
      {
        A0 tmp0 = minusone(sqr(u));
        A0 tmp = sqrt(tmp0);
        return cospi(P-1)*rec(tmp*pow<P-1>(tmp0))*K( boost::mpl::long_<P>(), u, oneminus(sqr(u)));
      }

      BOOST_FORCEINLINE result_type K(const boost::mpl::long_<0>
                                           , const A0&
                                           , const A0&) const
      {
        return Zero<result_type>(); ;
      }
      BOOST_FORCEINLINE result_type K(const boost::mpl::long_<1>
                                           , const A0&
                                           , const A0& ) const
      {
        return One<result_type>();
      }
      template<long P>
      BOOST_FORCEINLINE result_type K(const boost::mpl::long_<P>
                                     , const A0& x, const A0 & omx2) const
      {
        return fma(omx2, sqr(sA0(P-2))*K(boost::mpl::long_<P-2>(), x, omx2), sA0(2*P-3)*x*K(boost::mpl::long_<P-1>(), x, omx2));
      }
   };
  }
}


#endif
