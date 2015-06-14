//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_EXPONENTIAL_FUNCTIONS_D_EXPX2_HPP_INCLUDED
#define NT2_EXPONENTIAL_FUNCTIONS_D_EXPX2_HPP_INCLUDED
#include <nt2/include/functor.hpp>


namespace nt2 { namespace tag
  {
   /*!
     @brief d_expx2 generic tag

     Represents the d_expx2 function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct d_expx2_ : ext::elementwise_<d_expx2_>
    {
      typedef ext::elementwise_<d_expx2_> parent;
      /// @brief Parent hierarchy
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_d_expx2_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::d_expx2_, Site> dispatching_d_expx2_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::d_expx2_, Site>();
   }
   template<class... Args>
   struct impl_d_expx2_;
  }
  /*!
    Compute the derivative of expx2 at x
    @see @funcref{expx2}

  **/
  NT2_FUNCTION_IMPLEMENTATION(tag::d_expx2_, d_expx2, 1)
  /*!
    exponential of square function: \f$e^{x^2}\f$

    @par Semantic:

    For every parameters of floating type T0

    @code
    T0 r = d_expx2(x, s);
    @endcode

    is similar to:

    @code
    T0 r =  exp(signz(s)*x*x);
    @endcode

    @par Note:
    provisions are made for obtaining correct results for large x

    @see @funcref{exp}
    @param a0
    @param a1

    @return a value of the same type as the parameter
  **/
  NT2_FUNCTION_IMPLEMENTATION(tag::d_expx2_, d_expx2, 2)
}

#endif

