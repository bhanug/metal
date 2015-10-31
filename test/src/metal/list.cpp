// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list.hpp>
#include <metal/lambda/lambda.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::flatten_t<metal::transform_t<LIST(M), metal::lambda<metal::list>>>), (LIST(M))); \
    ASSERT((metal::flatten_t<metal::list<metal::reduce_t<LIST(INC(M)), metal::lambda<metal::list>>>>), (metal::list<VALS(INC(M))>)); \
    ASSERT((metal::slice_t<LIST(M), metal::size_t<LIST(M)>, metal::size_t<LIST(M)>>), (LIST(M))); \
    ASSERT((metal::transform_t<SEQ(M)<NUMS(M)>, metal::at<metal::quote_t<LIST(M)>, ARG(0)>>), (LIST(M))); \
    ASSERT((metal::reduce_t<SEQ()<VECS(INC(M))>, metal::lambda<metal::join>, NUM(INC(M)), NUM(0)>), (metal::reduce_t<metal::reverse_t<SEQ()<VECS(INC(M))>>, metal::lambda<metal::join>>)); \
    ASSERT((metal::insert_t<VEC(M), NUM(M), VAL(N)>), (metal::push_back_t<VEC(M), VAL(N)>)); \
    ASSERT((metal::insert_t<VEC(M), NUM(0), VAL(N)>), (metal::push_front_t<VEC(M), VAL(N)>)); \
    ASSERT((metal::erase_t<VEC(INC(M)), NUM(M)>), (metal::pop_back_t<VEC(INC(M))>)); \
    ASSERT((metal::erase_t<VEC(INC(M)), NUM(0)>), (metal::pop_front_t<VEC(INC(M))>)); \
/**/

GEN(MATRIX)
