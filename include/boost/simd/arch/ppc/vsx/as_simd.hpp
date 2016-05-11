//==================================================================================================
/**
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VSX_AS_SIMD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VSX_AS_SIMD_HPP_INCLUDED

#include <boost/simd/arch/ppc/vmx/as_simd.hpp>

namespace boost { namespace simd
{
  namespace ext
  {
    template<> struct as_simd<double, boost::simd::vsx_>
    {
      using type = __vector double;
    };

    template<> struct as_simd<signed long, boost::simd::vsx_>
    {
      using type = __vector signed long;
    };

    template<> struct as_simd<unsigned long, boost::simd::vsx_>
    {
      using type = __vector unsigned long;
    };
  }
} }

#endif
