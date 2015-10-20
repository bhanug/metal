// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_INDICES_HPP
#define METAL_LIST_INDICES_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list>
    struct indices
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref indices.
    template<typename list>
    using indices_t = typename indices<list>::type;
}

#include <metal/list/size.hpp>
#include <metal/list/swap.hpp>
#include <metal/number/enumerate.hpp>

namespace metal
{
    template<template<typename...> class list, typename... vals>
    struct indices<list<vals...>> :
        swap<list<vals...>, enumerate_t<size_t<list<vals...>>>>
    {};
}

#endif