//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/splat.hpp>
#include <boost/dispatch/meta/as_unsigned.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( shift_right_
                          , (typename A0, typename A1)
                          , bs::vmx_
                          , bs::pack_<int_<A0>, bs::vmx_>
                          , bs::pack_<bd::integer_<A1>, bs::vmx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        BOOST_ASSERT_MSG( assert_good_shift<A0>(a1)
                        , "shift_right: a shift is out of range"
                        );
       using type =  bd::as_unsigned_t<A1>;
       return vec_sra(a0.storage(), bitwise_cast<type>(a1)());
      }
   };

   BOOST_DISPATCH_OVERLOAD( shift_right_
                          , (typename A0, typename A1)
                          , bs::vmx_
                          , bs::pack_<uint_<A0>, bs::vmx_>
                          , bs::pack_<bd::integer_<A1>, bs::vmx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        BOOST_ASSERT_MSG( assert_good_shift<A0>(a1)
                        , "shift_right: a shift is out of range"
                        );
       using type =  bd::as_unsigned_t<A1>;
       return vec_sr(a0.storage(), bitwise_cast<type>(a1)());
      }
   };

   BOOST_DISPATCH_OVERLOAD( shift_right_
                          , (typename A0, typename A1)
                          , bs::vmx_
                          , bs::pack_<bd::integer_<A0>, bs::vmx_>
                          , scalar_<bd::integer_<A1>>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        return a0 >> splat<A0>(a1);
      }
   };

} } }

#endif
