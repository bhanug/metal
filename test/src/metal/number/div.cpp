// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/div.hpp>
#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, VAL(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, VAL(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, VAL(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, VAL(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, VAL(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, VAL(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, NUM(M) COMMA(N) VALS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, NUM(M) COMMA(N) NUMS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, NUM(M) COMMA(N) PAIRS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, NUM(M) COMMA(N) LISTS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, NUM(M) COMMA(N) MAPS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, NUM(M) COMMA(N) LBDS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, PAIR(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, PAIR(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, PAIR(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LIST(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LIST(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LIST(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LIST(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LIST(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LIST(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, MAP(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, MAP(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, MAP(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LBD(M) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LBD(M) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LBD(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LBD(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LBD(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LBD(M) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LBD(_) COMMA(N) VALS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LBD(_) COMMA(N) NUMS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LBD(_) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LBD(_) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LBD(_) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::div>, LBD(_) COMMA(N) LBDS(N)>), (FALSE)); \
    CHECK((metal::div<test::num<test::value_type<NUM(M)>, FACT(M)> COMMA(N) ENUM(N, NUM LIFT(INC))>), (test::num<test::value_type<NUM(M) COMMA(N) ENUM(N, NUM LIFT(INC)) COMMA(N) IF(NOT(N))( , INT(0))>, FACT(M)/FACT(N)>)); \
/**/

GEN(MATRIX)