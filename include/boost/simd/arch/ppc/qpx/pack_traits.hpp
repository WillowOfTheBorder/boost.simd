//==================================================================================================
/**
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_QPX_PACK_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_QPX_PACK_TRAITS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/arch/common/simd/as_simd.hpp>
#include <boost/simd/detail/pack_traits.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    BOOST_SIMD_DEFINE_PACK_TRAITS(double,  4, vector4double   );
  }

  namespace ext
  {
    template<typename Enable> struct abi_of<double,2,Enable>
    {
      using type = ::boost::simd::vsx_;
    };
  }
} }

#endif
