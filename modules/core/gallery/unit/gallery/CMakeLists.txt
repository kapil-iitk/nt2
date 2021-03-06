##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

SET( SOURCES
  bandred.cpp
  binomial.cpp
  cauchy.cpp
  chebspec.cpp
  chebvand.cpp
  chow.cpp
  circul.cpp
  clement.cpp
  compar.cpp
  condex.cpp
  cycol.cpp
  dorr.cpp
  dramadah.cpp
  fiedler.cpp
  forsythe.cpp
  frank.cpp
  gcdmat.cpp
  gearmat.cpp
  grcar.cpp
  hadamard.cpp
  hankel.cpp
  hanowa.cpp
  hilb.cpp
  house.cpp
  invhess.cpp
  invol.cpp
  invhilb.cpp
  ipjfact.cpp
  jordbloc.cpp
  kahan.cpp
  kms.cpp
  krylov.cpp
  lauchli.cpp
  lehmer.cpp
  leslie.cpp
  lesp.cpp
  lotkin.cpp
  magic.cpp
  minij.cpp
  moler.cpp
  orthog.cpp
  parter.cpp
  pascal.cpp
  pei.cpp
  prolate.cpp
  qmult.cpp
  randcolu.cpp
  randcorr.cpp
  randhess.cpp
  randjorth.cpp
  rando.cpp
  randsvd.cpp
  redheff.cpp
  riemann.cpp
  ris.cpp
  sampling.cpp
  smoke.cpp
  toeplitz.cpp
  toeppd.cpp
  toeppen.cpp
  tridiag.cpp
  triw.cpp
  vandermonde.cpp
  sobol.cpp
  wilkinson.cpp
  )

nt2_module_add_tests(core.gallery.gallery.unit ${SOURCES})
