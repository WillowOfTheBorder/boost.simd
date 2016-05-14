//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_SPLIT_HIGH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_SPLIT_HIGH_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/simd/bitwise_and.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/dispatch/meta/as_signed.hpp>
#include <boost/dispatch/meta/upgrade.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

   BOOST_DISPATCH_OVERLOAD( split_high_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_< bd::int8_<A0>, bs::vmx_>
                          )
   {
      using result =  bd::upgrade_t<A0>;

      BOOST_FORCEINLINE result operator()(const A0& a0) const
      {
        return vec_unpackl( a0.storage() );
      }
   };

   BOOST_DISPATCH_OVERLOAD( split_high_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_< bd::uint8_<A0>, bs::vmx_>
                          )
   {
      using result =  bd::upgrade_t<A0>;

      BOOST_FORCEINLINE result operator()(const A0& a0) const
      {
        using s_t =  meta::as_signed<A0>;
        using sr_t =  bd::upgrade_t<A0,signed>;
        using r_t =  result::value_type;
        sr_t that = vec_unpackl( bitwise_cast<s_t>(a0)() );
        return  bitwise_cast<result>(that) & r_t(0x00FF);
      }
   };

   BOOST_DISPATCH_OVERLOAD( split_high_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_< bd::int16_<A0>, bs::vmx_>
                          )
   {
      using result =  bd::upgrade_t<A0>;

      BOOST_FORCEINLINE result operator()(const A0& a0) const
      {
        return vec_unpackl( a0.storage() );
      }
   };

   BOOST_DISPATCH_OVERLOAD( split_high_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_< bd::uint16_<A0>, bs::vmx_>
                          )
   {
      using result =  bd::upgrade_t<A0>;

      BOOST_FORCEINLINE result operator()(const A0& a0) const
      {
        using s_t =  meta::as_signed<A0>;
        using sr_t =  bd::upgrade_t<A0,signed>;
        using r_t =  result::value_type;
        sr_t that = vec_unpackl( bitwise_cast<s_t>(a0)() );
        return  bitwise_cast<result>(that) & r_t(0x0000FFFF);
      }
   };
} } }

#endif
