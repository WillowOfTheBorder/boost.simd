//==================================================================================================
/**
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_MEMORY_FUNCTIONS_SIMD_PPC_VMX_LOAD_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_FUNCTIONS_SIMD_PPC_VMX_LOAD_HPP_INCLUDED

//#include <boost/simd/memory/functions/details/char_helper.hpp>
//#include <boost/simd/meta/is_pointing_to.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Pointer)
                          , bs::vmx_
                          , bd::pointer_<bd::scalar_<bd::arithmetic_<Pointer>>,1u>
                          , bd::target_<bs::pack_<bd::arithmetic_<Target>,bs::vmx_>>
                          )
  {
    BOOST_FORCEINLINE typename Target::type operator()(Pointer a0, Target const&) const
    {
      //typename char_helper_impl<value_t>::type* ptr = char_helper(a0);
      auto  ptr = a0;
      return vec_perm(vec_ld(0, ptr), vec_ld(15, ptr), vec_lvsl(0, ptr));
    }
  };
} } }

#endif
