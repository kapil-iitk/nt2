//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_META_REMOVE_POINTERS_HPP_INCLUDED
#define NT2_SDK_META_REMOVE_POINTERS_HPP_INCLUDED

#include <boost/type_traits/remove_pointer.hpp>

namespace nt2 { namespace meta
{
  template<typename T, unsigned N>
  struct  remove_pointers 
        : remove_pointers< typename boost::remove_pointer<T>::type, N-1>
  {};

  template<typename T> struct remove_pointers<T,1> : boost::remove_pointer<T> {};

  template<typename T> struct remove_pointers<T,0> { typedef T type; };
} } 

#endif
