// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_SEQUENCE_LIST_HPP
#define METAL_SEQUENCE_LIST_HPP

#include <metal/optional/just.hpp>

#include <type_traits>

namespace metal
{
    /// \ingroup sequence
    /// \brief ...
    template<typename... values>
    struct list
    {
        using type = list;
    };

    /// \ingroup sequece
    /// \brief ...
    template<typename seq>
    struct is_list;

    /// \ingroup optional
    /// \brief Eager adaptor for \ref is_list.
    template<typename seq>
    using is_list_t = typename metal::is_list<seq>::type;

    template<typename>
    struct is_list :
            std::false_type
    {};

    template<template<typename...> class list, typename... values>
    struct is_list<list<values...>> :
            is_just_itself<list<values...>>
    {};
}

#endif