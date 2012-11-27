/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::globalmax function"

#include <nt2/table.hpp>
#include <nt2/include/functions/globalmax.hpp>
#include <nt2/include/functions/zeros.hpp>
#include <nt2/include/constants/true.hpp>
#include <nt2/include/constants/false.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <nt2/sdk/unit/tests/exceptions.hpp>
#include <nt2/table.hpp>

NT2_TEST_CASE_TPL( globalmax, NT2_TYPES )
{
  nt2::table<T> a = nt2::reshape(nt2::_(T(1), T(9)), 3, 3);
  NT2_TEST_EQUAL( nt2::globalmax(a), T(9));
  NT2_TEST_EQUAL( nt2::globalmax(T(1)), T(1)); 
  a(3, 1) = T(27); 
  NT2_TEST_EQUAL( nt2::globalmax(a), T(27));
  int32_t i; 
  NT2_TEST_EQUAL( nt2::globalmax(a, i), T(27)); 
  NT2_TEST( i == 3);               
}

