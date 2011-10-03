//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*!
 * \file
**/
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_ALLBITS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_ALLBITS_HPP_INCLUDED

#include <boost/simd/include/simd.hpp>
#include <boost/simd/sdk/meta/int_c.hpp>
#include <boost/simd/sdk/meta/float.hpp>
#include <boost/simd/sdk/meta/double.hpp>
#include <boost/simd/sdk/constant/common.hpp>
#include <boost/simd/sdk/constant/constant.hpp>

/*!
 * \ingroup boost_simd_constant
 * \defgroup allbits Allbits function
 *
 * \par Description
 * Constant Allbits : all bits set to 1.
 * \par
 * The value of this constant are type dependant. This means that for different
 * types they do not represent the same mathematical number.
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/allbits.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class T,class A0>
 *     meta::call<tag::allbits_(A0)>::type
 *     Allbits();
 * }
 * \endcode
 *
 * 
 * \param T template parameter of Allbits
 * 
 * \return type T value
 *  
 *  
**/

namespace boost { namespace simd
{
  namespace tag
  {
    /*!
     * \brief Define the tag Allbits of functor Allbits 
     *        in namespace boost::simd::tag for toolbox boost.simd.constant
    **/
    struct Allbits 
    { 
      typedef double default_type;
      template<class Target, class Dummy=void> 
      struct  apply 
            : meta::int_c<Target, -1>
      {};
    };

    template<class Dummy>
    struct  Allbits::apply<float,Dummy>
          : meta::single_<apply<uint32_t,Dummy>::value> {};

    template<class Dummy>
    struct  Allbits::apply<double,Dummy>
          : meta::double_<apply<uint64_t,Dummy>::value> {};

    template<class Dummy>
    struct  Allbits::apply<boost::simd::uint8_t,Dummy> 
          : meta::int_c<boost::simd::uint8_t,0xFF> {};

    template<class Dummy>
    struct  Allbits::apply<boost::simd::uint16_t,Dummy> 
          : meta::int_c<boost::simd::uint16_t,0xFFFFU> {};

    template<class Dummy>
    struct  Allbits::apply<boost::simd::uint32_t,Dummy> 
          : meta::int_c<boost::simd::uint32_t,0xFFFFFFFFUL> {};

    template<class Dummy>
    struct  Allbits::apply<boost::simd::uint64_t,Dummy> 
          : meta::int_c<boost::simd::uint64_t,0xFFFFFFFFFFFFFFFFULL> {};

  }

  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::Allbits, Allbits)
} }

#endif
