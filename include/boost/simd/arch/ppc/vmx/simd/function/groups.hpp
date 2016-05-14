//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_GROUPS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_GROUPS_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/dispatch/meta/downgrade.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( groups_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_< ints32_<A0>, bs::vmx_>
                          , bs::pack_< ints32_<A0>, bs::vmx_>
                          )
   {
      using result =  bd::downgrade_t<A0>;
      BOOST_FORCEINLINE result operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        return vec_packs(a0.storage(), a1.storage());
      }
   };

   BOOST_DISPATCH_OVERLOAD( groups_
                          , (typename A0)
                          , bs::vmx_
                          , bs::pack_< ints16_<A0>, bs::vmx_>
                          , bs::pack_< ints16_<A0>, bs::vmx_>
                          )
   {
      using result =  bd::downgrade_t<A0>;
      BOOST_FORCEINLINE result operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        return vec_packs(a0.storage(), a1.storage());
      }
   };

} } }

#endif
