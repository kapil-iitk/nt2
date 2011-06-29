//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_FAST_FREXP_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_FAST_FREXP_HPP_INCLUDED
#include <boost/mpl/vector.hpp>
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/at.hpp>
#include <math.h>
/////////////////////////////////////////////////////////////////////////////
// Compute fast_frexp(const A0& a0)
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION(tag::fast_frexp_, tag::cpu_,
                            (A0),
                            (double_<A0>)
                           )
  {
      typedef typename meta::result_of<meta::floating(A0)>::type mantissa;
      typedef typename meta::as_integer<A0,signed>::type          exponent;
      typedef boost::fusion::vector<mantissa,exponent>             result_type;
    
    NT2_FUNCTOR_CALL(1)
    {
      typename NT2_RETURN_TYPE(1)::type res;
      int r1t;
      boost::fusion::at_c<0>(res) = ::frexp(a0, &r1t);
      boost::fusion::at_c<1>(res) = r1t;
      return res;
    }
  };



  NT2_FUNCTOR_IMPLEMENTATION(tag::fast_frexp_, tag::cpu_,
                            (A0),
                            (float_<A0>)
                           )
  {
      typedef typename meta::result_of<meta::floating(A0)>::type mantissa;
      typedef typename meta::as_integer<A0,signed>::type          exponent;
      typedef boost::fusion::vector<mantissa,exponent>             result_type;
    
    NT2_FUNCTOR_CALL(1)
    {
      typename NT2_RETURN_TYPE(1)::type res;
      boost::fusion::at_c<0>(res) = ::frexpf(a0, &boost::fusion::at_c<1>(res));
      return res;
    }
  };
} }
#endif
