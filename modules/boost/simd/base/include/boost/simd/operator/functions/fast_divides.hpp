//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_OPERATOR_FUNCTIONS_FAST_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_OPERATOR_FUNCTIONS_FAST_DIVIDES_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
   /*!
     @brief fast_divides generic tag

     Represents the fast_divides function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct fast_divides_ : ext::elementwise_<fast_divides_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<fast_divides_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_fast_divides_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::fast_divides_, Site> dispatching_fast_divides_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::fast_divides_, Site>();
   }
   template<class... Args>
   struct impl_fast_divides_;
  }
  /*!

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    T0 r = fast_divides(a0,a1);
    @endcode

    is similar to:

    @code
    T0 r = a0*fast_rec(a1);
    @endcode

    @par Alias:
    @c fast_div, @c fast_rdiv

    @see  @funcref{divides}, @funcref{rec}, @funcref{fast_rec}, @funcref{divs}, @funcref{divfloor},
    @funcref{divceil}, @funcref{divround}, @funcref{divround2even}, @funcref{divfix}
    @param a0

    @param a1

    @return a value of the same type as the second parameter
  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::fast_divides_ , fast_divides  , 2)

  /// INTERNAL ONLY
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::fast_divides_ , fast_div      , 2)

  /// INTERNAL ONLY
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::fast_divides_ , fast_rdiv     , 2)
} }

#endif
