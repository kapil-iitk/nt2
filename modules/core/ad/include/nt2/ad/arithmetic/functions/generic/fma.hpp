//==============================================================================
 //         Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_AD_OPERATOR_FUNCTIONS_GENERIC_FMA_HPP_INCLUDED
#define NT2_AD_OPERATOR_FUNCTIONS_GENERIC_FMA_HPP_INCLUDED

#include <nt2/include/functions/fma.hpp>
#include <nt2/include/functions/is_less.hpp>
#include <nt2/include/functions/if_else_zero.hpp>
#include <nt2/include/functions/if_zero_else.hpp>
#include <nt2/ad/functions/ad.hpp>

namespace nt2
{
  namespace ad
  {
    template < class T1, class T2, class T3> BOOST_FORCEINLINE
    valder<T1> fma(const valder<T1>&u, const valder<T2>&v, const valder<T3>&w)
    {
      return valder<T1>(nt2::fma(u.val(), v.val(), w.val())
                       , nt2::fma(u.der(), v.val(), nt2::fma(u.val(), v.der(), w.der()))
                       );
    };
    template < class T1, class T2, class T3> BOOST_FORCEINLINE
    valder<T2> fma(const T1&u, const valder<T2>&v, const valder<T3>&w)
    {
      return valder<T2>(nt2::fma(u, v.val(), w.val())
                       , nt2::fma(u, v.der(), w.der())
                       );
    };
    template < class T1, class T2, class T3> BOOST_FORCEINLINE
    valder<T1> fma(const valder<T1>&u, const T2&v, const valder<T3>&w)
    {
      return valder<T1>(nt2::fma(u.val(), v, w.val())
                       , nt2::fma(u.der(), v, w.der())
                       );
    };
    template < class T1, class T2, class T3> BOOST_FORCEINLINE
    valder<T1> fma(const valder<T1>&u, const valder<T2>&v, const T3&w)
    {
      return valder<T1>(nt2::fma(u.val(), v.val(), w)
                       , nt2::fma(u.der(), v.val(), u.val()*v.der())
                       );
    };
    template < class T1, class T2, class T3> BOOST_FORCEINLINE
    valder<T3> fma(const T1&u, const T2&v, const valder<T3>&w)
    {
      return valder<T3>(nt2::fma(u, v, w.val()),  w.der());
    };
    template < class T1, class T2, class T3> BOOST_FORCEINLINE
    valder<T2> fma(const T1&u, const valder<T2>&v, const T3&w)
    {
      return valder<T2>(nt2::fma(u, v.val(), w), u*v.der());
    };
    template < class T1, class T2, class T3> BOOST_FORCEINLINE
    valder<T1> fma(const valder<T1>&u, const T2&v, const T3&w)
    {
      return valder<T1>(nt2::fma(u.val(), v, w), u.der()*v);
    };
  }
}

#endif
