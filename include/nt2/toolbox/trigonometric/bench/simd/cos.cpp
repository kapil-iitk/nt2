//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/trigonometric/include/cos.hpp>
#include <nt2/sdk/simd/native.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <cmath>

//////////////////////////////////////////////////////////////////////////////
// Runtime benchmark for functor<cos_> from trigonometric
//////////////////////////////////////////////////////////////////////////////
using nt2::functors::cos_;

////////////////////////////////////////////////////////////////////////////////
// Symmetric range
////////////////////////////////////////////////////////////////////////////////
#define RS(T,V) ((T, -V , V))

// TODO : what's for Altivec ?
typedef nt2::simd::native<double,nt2::tag::sse_>  vdouble;
typedef nt2::simd::native<float,nt2::tag::sse_>   vfloat;

////////////////////////////////////////////////////////////////////////////////
// Scalar benchmark
////////////////////////////////////////////////////////////////////////////////
NT2_TIMING( cos_ , RS(vdouble,3.1415/4))
NT2_TIMING( cos_ , RS(vfloat,3.1415f/4))
