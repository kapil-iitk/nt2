//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_TABLE_DETAILS_MAKE_SIZE_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_TABLE_DETAILS_MAKE_SIZE_HPP_INCLUDED

#include <nt2/sdk/meta/is_colon.hpp>
#include <nt2/core/settings/size.hpp>
#include <nt2/include/functions/numel.hpp>
#include <nt2/include/functions/extent.hpp>
#include <nt2/include/functions/relative_size.hpp>

#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/include/mpl.hpp>
#include <boost/fusion/include/at_c.hpp>
#include <boost/dispatch/meta/strip.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

namespace nt2 { namespace details
{
  /// INTERNAL ONLY
  /// Build a of_size for size_of
  template< int N
          , class Domain
          , class Indexed
          , class Sizes, class Bases
          , class Children
          >
  struct make_size;

  #define M1(z,n,t)                                                     \
  mpl_value                                                             \
  < typename meta::                                                     \
    call< tag::relative_size_                                           \
        ( typename  boost::proto::result_of::child_c<Children, n>::type \
        , typename  boost::fusion::result_of::                          \
                    at_c<typename meta::strip<Sizes>::type, n>::type    \
        , typename  boost::fusion::result_of::                          \
                    at_c<typename meta::strip<Bases>::type, n>::type    \
        )                                                               \
        >::type                                                         \
  >::value                                                              \
  /**/

  #define M2(z,n,t)                                                 \
  that[n] = nt2::relative_size( boost::proto::child_c<n>(children)  \
                              , boost::fusion::at_c<n>(sz)          \
                              , boost::fusion::at_c<n>(bs)          \
                              );                                    \
  /**/

  #define M3(z,n,t)                                                 \
  template<class Dummy>                                             \
  struct impl<n, Dummy>                                             \
  {                                                                 \
    BOOST_DISPATCH_FORCE_INLINE                                     \
    static result_type call(Sizes sz, Bases bs, Children children)  \
    {                                                               \
      result_type that;                                             \
      BOOST_PP_REPEAT(n, M2, t)                                     \
      return that;                                                  \
    }                                                               \
  };                                                                \
  /**/

  #define M0(z,n,t)                                                     \
  template< class Domain                                                \
          , class Indexed, class Sizes, class Bases                     \
          , class Children                                              \
          >                                                             \
  struct make_size<n, Domain, Indexed, Sizes, Bases, Children>          \
  {                                                                     \
    typedef of_size_<BOOST_PP_ENUM(n, M1, n)> result_type;              \
                                                                        \
    template<int N, class Dummy = void>                                 \
    struct impl {};                                                     \
                                                                        \
    BOOST_PP_REPEAT(BOOST_PP_INC(n), M3, n)                             \
                                                                        \
    BOOST_DISPATCH_FORCE_INLINE result_type                             \
    operator()(Indexed, Sizes s, Bases b, Children children) const      \
    {                                                                   \
      return impl<result_type::static_size>::call(s, b, children);      \
    }                                                                   \
  };                                                                    \
  /**/

  BOOST_PP_REPEAT_FROM_TO(2,BOOST_PP_INC(NT2_MAX_DIMENSIONS), M0, ~)
  #undef M0
  #undef M1
  #undef M2
  #undef M3

  template< class Domain
          , class Indexed, class Sizes, class Bases
          , class Children
          >
  struct make_size<1, Domain, Indexed, Sizes, Bases, Children>
  {
    typedef typename boost::proto::result_of::child_c<Children, 0>::type  idx_t;

    template<bool B, class Dummy = void> struct apply {};

    // Case of colon indexer
    template<class Dummy> struct apply<true, Dummy>
    {
      typedef typename meta::call<tag::numel_(Indexed)>::type num;
      typedef of_size_< mpl_value<num>::value > result_type;

      template<class I, class C>
      BOOST_FORCEINLINE result_type operator()(I& i, C&) const
      {
        return result_type(numel(i));
      }
    };

    // Case of non-colon indexer
    template<class Dummy> struct apply<false, Dummy>
    {
      typedef typename
              container::size_transform<Domain>::template
              result<container::size_transform<Domain>(idx_t)>::type result_type;

      template<class I, class C>
      BOOST_FORCEINLINE result_type operator()(I&, C& c) const
      {
        return container::size_transform<Domain>()(boost::proto::child_c<0>(c));
      }
    };

    typedef apply< meta::is_colon<idx_t>::value > impl;
    typedef typename impl::result_type            result_type;

    BOOST_DISPATCH_FORCE_INLINE
    result_type operator()(Indexed i, Sizes, Bases, Children children) const
    {
      return impl()(i, children);
    }
  };
} }

#endif
