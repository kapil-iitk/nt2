//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012        MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================

#include <nt2/sdk/magma/magma.hpp>

#include <nt2/table.hpp>
#include <nt2/include/functions/lu.hpp>
#include <nt2/include/functions/rand.hpp>
#include <nt2/include/functions/zeros.hpp>
#include <nt2/linalg/details/utility/f77_wrapper.hpp>
#include "../../flops/lu.hpp"
#include "details.hpp"

#include <nt2/sdk/bench/benchmark.hpp>
#include <nt2/sdk/bench/metric/gflops.hpp>
#include <nt2/sdk/bench/protocol/max_duration.hpp>
#include <nt2/sdk/bench/setup/geometric.hpp>
#include <nt2/sdk/bench/setup/constant.hpp>
#include <nt2/sdk/bench/setup/combination.hpp>
#include <nt2/sdk/bench/stats/median.hpp>

using namespace nt2::bench;
using namespace nt2;

template<typename T> struct lu1_float_nt2
{
  lu1_float_nt2(std::size_t n)
              :  size_(n)
              , result(of_size(n,n))
  {
    input  = nt2::rand(n,n, nt2::meta::as_<T>());
  }

  void operator()()
  {
    h1 = size_;
    w1 = size_;
    jpvt.resize(nt2::of_size(std::min(h1, w1), 1) );
    magma_sgetrf( h1, w1, input.data(), h1, jpvt.data(), &i);
    result = input;
  }

  friend std::ostream& operator<<(std::ostream& os, lu1_float_nt2<T> const& p)
  {
    return os << "(" << p.size() << ")";
  }

  std::size_t size() const { return size_*size_; }
  std::size_t flops() const { return FLOPS_GETRF(size_,size_); }

private:
  std::size_t size_;
  nt2_la_int i,h1,w1;
  nt2::table<T> input, result;
  nt2::table<nt2_la_int> jpvt;
};

NT2_REGISTER_BENCHMARK_TPL( lu1_float_nt2, (float) )
{
  std::size_t size_min = args("size_min", 16);
  std::size_t size_max = args("size_max", 4096);
  std::size_t size_step = args("size_step", 10);

  run_during_with< lu1_float_nt2<T> > ( 1.
                                ,  geometric(size_min,size_max,size_step)
                                , gflops<stats::median_>()
                                );
}



template<typename T> struct lu1_double_nt2
{
  lu1_double_nt2(std::size_t n)
              :  size_(n)
              , result(of_size(n,n))
  {
    input  = nt2::rand(n,n, nt2::meta::as_<T>());
  }

  void operator()()
  {
    h1 = size_;
    w1 = size_;
    jpvt.resize(nt2::of_size(std::min(h1, w1), 1) );
    magma_dgetrf( h1, w1, input.data(), h1, jpvt.data(), &i);
    result = input;
  }

  friend std::ostream& operator<<(std::ostream& os, lu1_double_nt2<T> const& p)
  {
    return os << "(" << p.size() << ")";
  }

  std::size_t size() const { return size_*size_; }
  std::size_t flops() const { return FLOPS_GETRF(size_,size_); }

private:
  std::size_t size_;
  nt2_la_int i,h1,w1;
  nt2::table<T> input, result;
  nt2::table<nt2_la_int> jpvt;
};

NT2_REGISTER_BENCHMARK_TPL( lu1_double_nt2, (double) )
{
  std::size_t size_min = args("size_min", 16);
  std::size_t size_max = args("size_max", 4096);
  std::size_t size_step = args("size_step", 10);

  run_during_with< lu1_double_nt2<T> > ( 1.
                                ,  geometric(size_min,size_max,size_step)
                                , gflops<stats::median_>()
                                );
}
