//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 ieee toolbox - bitfloating/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of ieee components in simd mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/ieee/include/bitfloating.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;

//////////////////////////////////////////////////////////////////////////////
// simd runtime benchmark for functor<bitfloating_> from ieee
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::bitfloating_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, (V1) ,(V2))

namespace n1 {
  typedef uint32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(bitfloating_,(RS(vT,0,100)))
}
namespace n2 {
  typedef uint64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(bitfloating_,(RS(vT,0,100)))
}
namespace n3 {
  typedef int32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(bitfloating_,(RS(vT,-100,100)))
}
namespace n4 {
  typedef int64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(bitfloating_,(RS(vT,-100,100)))
}

#undef RS
