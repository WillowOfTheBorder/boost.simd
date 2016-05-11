//==================================================================================================
/**
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VSX_PACK_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VSX_PACK_TRAITS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/arch/ppc/vmx/pack_traits.hpp>
#include <boost/simd/detail/pack_traits.hpp>
#include <type_traits>


namespace boost { namespace simd
{
  namespace detail
  {
    BOOST_SIMD_DEFINE_PACK_TRAITS(double        ,  2, __vector double         );
    BOOST_SIMD_DEFINE_PACK_TRAITS(std::int64_t  ,  2, __vector signed   long   );
    BOOST_SIMD_DEFINE_PACK_TRAITS(std::uint64_t ,  2, __vector unsigned long   );

    // Match also the bool funky types from VMX
    BOOST_SIMD_DEFINE_PACK_TRAITS(double        ,  2, __vector __bool long );
    BOOST_SIMD_DEFINE_PACK_TRAITS(std::int64_t  ,  2, __vector __bool long );
    BOOST_SIMD_DEFINE_PACK_TRAITS(std::uint64_t ,  2, __vector __bool long );

  }

  namespace ext
  {
    template<typename Enable> struct abi_of<double,2,Enable>
    {
      using type = ::boost::simd::vsx_;
    };

    template<typename T, std::size_t N>
    struct abi_of<  T, N
                  , typename std::enable_if<   std::is_integral<T>::value
                                            && (N*sizeof(T) == 16) && (N == 2)
                                            >::type
                  >
    {
      using type = ::boost::simd::vsx_;
    };
  }
} }

#endif
