//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_COMMON_ISEXPANDABLE_TO_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_COMMON_ISEXPANDABLE_TO_HPP_INCLUDED

#include <nt2/core/functions/isexpandable_to.hpp>
#include <nt2/include/functions/numel.hpp>
#include <algorithm>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::isexpandable_to_, tag::cpu_
                            , (A0)(A1)
                            , (ast_<A0>)
                              (fusion_sequence_<A1>)
                            )
  {
    typedef bool result_type;

    BOOST_FORCEINLINE
    result_type operator()(const A0& a0, const A1& siz) const
    {
      typename A0::extent_type ex1 = a0.extent();

      size_t sz = nt2::min(ex1.size(), siz.size());
      for(size_t i=0; i < sz; ++i)
      {
        if(ex1[i] != siz[i] && ex1[i] != 1)
          return false;
      }

      for(size_t i=sz; i < ex1.size(); ++i)
      {
        if(ex1[i] != 1)
          return false;
      }

      return true;
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::isexpandable_to_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_<fundamental_<A0> >)
                              (fusion_sequence_<A1>)
                            )
  {
    typedef bool result_type;
    BOOST_FORCEINLINE
    result_type operator()(const A0&, const A1& a1) const
    {
      return nt2::numel(a1) != 0;
    }
  };

} }

#endif
