//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( if_else_
                          , (typename A0, typename A1)
                          , bs::vmx_
                          , bs::pack_< logical_<A0>, bs::vmx_>
                          , bs::pack_< bd::arithmetic_<A1>, bs::vmx_>
                          , bs::pack_< bd::arithmetic_<A1>, bs::vmx_>
                          )
   {
      using result = A1;
     result operator()(const A0& a0, const A1& a1, const A1&a2) const
      {
        return vec_sel(a2(), a1.storage(), a0.storage());
      }
   };

} } }

#endif
