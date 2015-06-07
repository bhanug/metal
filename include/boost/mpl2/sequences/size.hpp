// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_SEQUENCES_SIZE_HPP
#define BOOST_MPL2_SEQUENCES_SIZE_HPP

#include <boost/mpl2/metafunctional/call.hpp>
#include <boost/mpl2/sequences/tag.hpp>

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        template<typename tag>
        struct size_impl
        {
        private:
            struct empty {};

            template<typename>
            static empty impl(...);
            template<typename x, typename y = typename x::size>
            static std::integral_constant<typename y::value_type, y::value> impl(int);

        public:
            template<typename x>
            struct call :
                    decltype(impl<x>(0))
            {};
        };

        template<typename x>
        struct size :
                call<size_impl<typename tag<x>::type>, x>
        {};
    }
}

#endif