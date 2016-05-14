//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_REC_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/function/simd/copysign.hpp>
#include <boost/simd/function/simd/fast_rec.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_eqz.hpp>

#if !defined( BOOST_SIMD_NO_INFINITIES )
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/simd/is_inf.hpp>
#endif
 
namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( rec_
                          , (typename A0)
                          , bs::vmx_
                          , , bs::pack_< bd::floating_<A0>, bs::vmx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        A0 estimate = fast_rec(a0);
        // fix rec(+/-0)
        estimate = if_else( is_eqz(a0)
                          , copysign(Inf<A0>(),a0)
                          , estimate
                          );
        // fix rec(+/-inf)
        #if !defined( BOOST_SIMD_NO_INFINITIES )
        estimate = if_else( is_inf(a0)
                          , copysign(Zero<A0>(),a0)
                          , estimate
                          );
        #endif
        return estimate;
      }
   };

} } }

#endif
