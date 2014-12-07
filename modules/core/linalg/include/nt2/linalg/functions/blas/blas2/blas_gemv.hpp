//==============================================================================
//         Copyright 2013 - 2014   Jean-Thierry Laprest�
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_LINALG_FUNCTIONS_BLAS_BLAS2_GEMV_HPP_INCLUDED
#define NT2_LINALG_FUNCTIONS_BLAS_BLAS2_GEMV_HPP_INCLUDED

#include <nt2/linalg/functions/blas_rotm.hpp>
#include <nt2/linalg/details/blas/blas2.hpp>
#include <nt2/include/functions/height.hpp>
#include <nt2/include/functions/width.hpp>
#include <nt2/linalg/details/utility/f77_wrapper.hpp>
#include <boost/dispatch/attributes.hpp>
#include <nt2/sdk/memory/container.hpp>

namespace nt2 { namespace ext
{
// _GEMV (        TRANS,      M, N,         ALPHA, A, LDA, X, INCX, BETA,  Y, INCY ) S, D, C, Z
// /---------------------------------------------Real-single------------------------------------------------//

  BOOST_DISPATCH_IMPLEMENT  ( blas_gemv_, tag::cpu_
                            , (T)(ALPHA)(A)(SA)(X)(SX)(INCX)(BETA)(Y)(SY)(INCY)
                            , (scalar_<int8_<T>>)// n
                              (scalar_<single_<ALPHA>>)//alpha
                              ((container_<nt2::tag::table_,  single_<A>, SA >)) //a
                              ((container_<nt2::tag::table_,  single_<X>, SX >)) //x
                              (scalar_<integer_<INCX>>)// incx
                              (scalar_<single_<BETA>>)// beta
                              ((container_<nt2::tag::table_,  single_<Y>, SY >)) //y
                              (scalar_<integer_<INCY>>)// incy
                            )
  {
    typedef void result_type;

    BOOST_FORCEINLINE void operator()( const T& trans
                                     , const ALPHA& alpha
                                     , const A& a
                                     , const X& x, const INCX & incx
                                     , const BETA beta
                                     , Y& y, const INCY & incy
                                     ) const
    {
      nt2_la_int n = height(a);
      nt2_la_int m = width(a);
      nt2_la_int lda = n;
      nt2_la_int ix= incx;
      nt2_la_int iy= incy;
      NT2_F77NAME(sgemv) (&trans, &n, &m, &alpha, a.raw(), &lda, x.raw(), &ix, &beta, y.raw(), &iy);
    }
  };

// /---------------------------------------------Real-double------------------------------------------------//
  BOOST_DISPATCH_IMPLEMENT  ( blas_gemv_, tag::cpu_
                            , (T)(ALPHA)(A)(SA)(X)(SX)(INCX)(BETA)(Y)(SY)(INCY)
                            , (scalar_<int8_<T>>)// n
                              (scalar_<double_<ALPHA>>)//alpha
                              ((container_<nt2::tag::table_,  double_<A>, SA >)) //a
                              ((container_<nt2::tag::table_,  double_<X>, SX >)) //y
                              (scalar_<integer_<INCX>>)// incx
                              (scalar_<double_<BETA>>)// beta
                              ((container_<nt2::tag::table_,  double_<Y>, SY >)) //dparam
                              (scalar_<integer_<INCY>>)// incy
                            )
  {
    typedef void result_type;

    BOOST_FORCEINLINE void operator()( const T& trans
                                     , const ALPHA& alpha
                                     , const A& a
                                     , const X& x, const INCX & incx
                                     , const BETA& beta
                                     , Y& y, const INCY & incy
                                     ) const
    {
      nt2_la_int n = height(a);
      nt2_la_int m = width(a);
      nt2_la_int lda = n;
      nt2_la_int ix= incx;
      nt2_la_int iy= incy;
      NT2_F77NAME(dgemv) (&trans, &n, &m, &alpha, a.raw(), &lda, x.raw(), &ix, &beta, y.raw(), &iy);
    }
  };



// /---------------------------------------------Complex-single------------------------------------------------//

  BOOST_DISPATCH_IMPLEMENT  ( blas_gemv_, tag::cpu_
                            , (T)(ALPHA)(A)(SA)(X)(SX)(INCX)(BETA)(Y)(SY)(INCY)
                            , (scalar_<int8_<T>>)// n
                              (scalar_<complex_<single_<ALPHA>>>)//alpha
                              ((container_<nt2::tag::table_,  complex_<single_<A>>, SA >)) //a
                              ((container_<nt2::tag::table_,  complex_<single_<X>>, SX >)) //y
                              (scalar_<integer_<INCX>>)// incx
                              (scalar_<complex_<single_<BETA>>>)// beta
                              ((container_<nt2::tag::table_,  complex_<single_<Y>>, SY >)) //dparam
                              (scalar_<integer_<INCY>>)// incy
                            )
  {
    typedef void result_type;

    BOOST_FORCEINLINE void operator()( const T& trans
                                     , const ALPHA& alpha
                                     , const A& a
                                     , const X& x, const INCX & incx
                                     , const BETA& beta
                                     , Y& y, const INCY & incy
                                     ) const
    {
      nt2_la_int n = height(a);
      nt2_la_int m = width(a);
      nt2_la_int lda = n;
      nt2_la_int ix= incx;
      nt2_la_int iy= incy;
      NT2_F77NAME(cgemv) (&trans, &n, &m, &alpha, a.raw(), &lda, x.raw(), &ix, &beta, y.raw(), &iy);
    }
  };

// /---------------------------------------------Complex-double------------------------------------------------//
  BOOST_DISPATCH_IMPLEMENT  ( blas_gemv_, tag::cpu_
                            , (T)(ALPHA)(A)(SA)(X)(SX)(INCX)(BETA)(Y)(SY)(INCY)
                            , (scalar_<int8_<T>>)// n
                              (scalar_<complex_<double_<ALPHA>>>)//alpha
                              ((container_<nt2::tag::table_,  complex_<double_<A>>, SA >)) //a
                              ((container_<nt2::tag::table_,  complex_<double_<X>>, SX >)) //y
                              (scalar_<integer_<INCX>>)// incx
                              (scalar_<complex_<double_<BETA>>>)// beta
                              ((container_<nt2::tag::table_,  complex_<double_<Y>>, SY >)) //dparam
                              (scalar_<integer_<INCY>>)// incy
                            )
  {
    typedef void result_type;

    BOOST_FORCEINLINE void operator()( const T& trans
                                     , const ALPHA& alpha
                                     , const A& a
                                     , const X& x, const INCX & incx
                                     , const BETA& beta
                                     , Y& y, const INCY & incy
                                     ) const
    {
      nt2_la_int n = height(a);
      nt2_la_int m = width(a);
      nt2_la_int lda = n;
      nt2_la_int ix= incx;
      nt2_la_int iy= incy;
      NT2_F77NAME(zgemv) (&trans, &n, &m, &alpha, a.raw(), &lda, x.raw(), &ix, &beta, y.raw(), &iy);
    }
  };


} }

#endif