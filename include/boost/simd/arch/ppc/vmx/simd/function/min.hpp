//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_MIN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_MIN_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>

#if !defined(BOOST_SIMD_NO_NANS)
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_nan.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( min_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_<bd::arithmetic_<A0>, bs::vmx_>
                          , bs::pack_<bd::arithmetic_<A0>, bs::vmx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        #if !defined(BOOST_SIMD_NO_NANS)
        return if_else(is_nan(a0), a1, A0(vec_min(a0.storage(),a1.storage())));
        #else
        return vec_min(a0.storage(),a1.storage());
        #endif
      }
   };

} } }

#endif
