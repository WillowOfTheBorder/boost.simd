//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_ABSS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_ABSS_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( abss_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_< int_<A0>, bs::vmx_>
                          )
  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
    {
      return vec_abss( a0.storage() );
    }
  };
} } }

#endif
