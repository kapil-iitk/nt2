//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_EXPONENTIAL_FUNCTIONS_D_SQRT1PM1_HPP_INCLUDED
#define NT2_EXPONENTIAL_FUNCTIONS_D_SQRT1PM1_HPP_INCLUDED
#include <nt2/include/functor.hpp>


namespace nt2 { namespace tag
  {
   /*!
     @brief d_sqrt1pm1 generic tag

     Represents the d_sqrt1pm1 function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct d_sqrt1pm1_ : ext::elementwise_<d_sqrt1pm1_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<d_sqrt1pm1_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_d_sqrt1pm1_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::d_sqrt1pm1_, Site> dispatching_d_sqrt1pm1_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::d_sqrt1pm1_, Site>();
   }
   template<class... Args>
   struct impl_d_sqrt1pm1_;
  }
  /*!
    Compute the derivative of sqrt1pm1 at x
    @see @funcref{sqrt1pm1}
  **/
  NT2_FUNCTION_IMPLEMENTATION(tag::d_sqrt1pm1_, d_sqrt1pm1, 1)
}

#endif

