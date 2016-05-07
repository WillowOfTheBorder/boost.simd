//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_NONE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_NONE_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/simd/function/definition/logical_andnot.hpp>
#include <boost/simd/constant/definition/true.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, none_, (boost::dispatch::reduction_<none_, logical_andnot_, true_>));
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, none_);
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::none_,none);


} }

#endif
