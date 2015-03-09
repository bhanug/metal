/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_DATATYPES_INTEGRAL_HPP_
#define _BOOST_MPL2_DATATYPES_INTEGRAL_HPP_

#include <boost/config.hpp>

namespace boost
{
    namespace mpl2
    {
        struct integral_tag;

        template<typename integer, integer constant>
        struct integral
        {
            typedef integral_tag    tag;
            typedef integral        type;
            typedef integer         value_type;

            enum {value = constant};

            typedef integral<integer, static_cast<integer>(constant + 1)> next;
            typedef integral<integer, static_cast<integer>(constant - 1)> prior;

            BOOST_CONSTEXPR operator integer () const
            {
                return constant;
            }
        };
    }
}

#endif
