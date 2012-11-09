/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::bsxfun function"

#include <nt2/table.hpp>
#include <nt2/include/functions/size.hpp>
#include <nt2/include/functions/bsxfun.hpp>
#include <nt2/include/functions/rif.hpp>
#include <nt2/include/functions/cif.hpp>
#include <nt2/include/functions/ones.hpp>
#include <nt2/include/functions/mean.hpp>
#include <nt2/include/functions/isequal.hpp>
#include <nt2/include/functions/reshape.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <nt2/sdk/unit/tests/exceptions.hpp>

NT2_TEST_CASE_TPL( bsxfun_1, NT2_TYPES)
{
  nt2::table<T> a = nt2::rif(nt2::of_size(3, 1), nt2::meta::as_<T>()),
                b = nt2::cif(nt2::of_size(1, 3), nt2::meta::as_<T>()),
                e;

  e = bsxfun(nt2::functor<nt2::tag::multiplies_>(),  a, b);

  for(unsigned int i=1; i <= length(a); i++)
  {
    for(unsigned int j=1; j <= length(a); j++)
    {
      NT2_TEST_EQUAL(e(i, j), a(i)*b(j));
    }
  }
}

NT2_TEST_CASE_TPL( bsxfun_2, NT2_TYPES)
{
  nt2::table<T> a = nt2::ones(nt2::of_size(3, 1,3,1), nt2::meta::as_<T>()),
                b = nt2::ones(nt2::of_size(1, 3, 1,3), nt2::meta::as_<T>()),
                e;

  e = bsxfun(nt2::functor<nt2::tag::plus_>(),  a, b);

  NT2_TEST_EQUAL( nt2::extent(e), nt2::of_size(3,3,3,3) );

  for(unsigned int i=1; i <= numel(e); i++)
  {
    NT2_TEST_EQUAL(e(i), T(2));
  }
}

NT2_TEST_CASE_TPL( bsxfun_3, NT2_REAL_TYPES)
{
  nt2::table<T> a = nt2::rif(nt2::of_size(8, 1), nt2::meta::as_<T>()),
                     m, c, d;
   m =  nt2::mean(a, 1);
   nt2::functor<nt2::tag::minus_> f;
   c = bsxfun(f,  a, m);
   d = a-m(1);
   NT2_TEST(isequal(c, d));
}
NT2_TEST_CASE_TPL( bsxfun_aliasing, NT2_REAL_TYPES)
{
  nt2::table<T> a = nt2::rif(nt2::of_size(8, 1), nt2::meta::as_<T>()),
                     m, c, d;
   m =  nt2::mean(a, 1);
   nt2::functor<nt2::tag::minus_> f;
   c = bsxfun(f,  a, m);
   a = bsxfun(f,  a, m);
   NT2_TEST(isequal(a, c));
}
NT2_TEST_CASE_TPL( bsxfunc, NT2_REAL_TYPES)
{
  typedef std::complex<T> cT; 
  nt2::table<cT> a = nt2::rif(nt2::of_size(8, 1), nt2::meta::as_<cT>()),
                     m, c, d;
   NT2_DISPLAY(a);
   m =  nt2::mean(a, 1);
   nt2::functor<nt2::tag::minus_> f;
   c = bsxfun(f,  a, m);
   a = bsxfun(f,  a, m);
   NT2_TEST(isequal(a, c));
   NT2_DISPLAY(c);
}
