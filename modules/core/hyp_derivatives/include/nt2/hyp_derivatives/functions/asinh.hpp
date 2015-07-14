//==============================================================================
//        Copyright 2015   J.T. Lapreste
//
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_HYP_DERIVATIVES_FUNCTIONS_ASINH_HPP_INCLUDED
#define NT2_HYP_DERIVATIVES_FUNCTIONS_ASINH_HPP_INCLUDED
#include <nt2/hyperbolic/include/functions/asinh.hpp>
#include <nt2/include/functions/simd/asinh.hpp>
#include <nt2/include/functor.hpp>


namespace nt2
{
  /*!
    Compute the Nth derivative of asinh at x
    by asinh<N>(x)
    @see @funcref{asinh}
  **/
  NT2_FUNCTION_IMPLEMENTATION(tag::asinh_, asinh, 2)


  template < long N, class T> BOOST_FORCEINLINE T asinh(const T & x)
  {
    return asinh(boost::mpl::long_<N>(), x);
  }

}

#endif

