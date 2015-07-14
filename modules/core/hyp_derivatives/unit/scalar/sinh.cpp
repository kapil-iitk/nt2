//==============================================================================
//         Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/hyperbolic/include/functions/sinh.hpp>
#include <nt2/hyp_derivatives/include/functions/sinh.hpp>
#include <nt2/include/functions/sinh.hpp>
#include <nt2/include/functions/cos.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>
#include <boost/simd/sdk/config.hpp>

 #include <nt2/include/constants/one.hpp>


NT2_TEST_CASE_TPL ( sinh,  NT2_REAL_TYPES)
{
  using nt2::sinh;

  NT2_TEST_ULP_EQUAL(sinh<1>(nt2::One<T>()),
                     T(1.543080634815244), 1.5);
  NT2_TEST_ULP_EQUAL(sinh<2>(nt2::One<T>()),
                     T(1.175201193643801), 1.5);
  NT2_TEST_ULP_EQUAL(sinh<3>(nt2::One<T>()),
                     T(1.543080634815244), 1.5);

}

