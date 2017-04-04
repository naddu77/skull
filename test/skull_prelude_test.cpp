#include "catch.hpp"

#include <type_traits>
#include <tuple>
#include <string>


#include "skull/prelude.h"
using namespace skull::prelude;


TEST_CASE("id", "[prelude]")
{
    static_assert(std::is_same_v<int, id_t<int>>);
}

TEST_CASE("length", "[prelude]")
{
    static_assert(0 == length_v<TL<>>);
    static_assert(3 == length_v<TL<int, double, std::string>>);
}

TEST_CASE("head", "[prelude}")
{
    static_assert(
        std::is_same_v<
                int,
                head_t<TL<int, double, std::string>>
        >
    );

    static_assert(
        !std::is_same_v<
                double,
                head_t<TL<int, double, std::string>>
        >
    );

    static_assert(std::is_same_v<int, head_t<TL<int>>>);

    // NOTE: this is an expected compile error
    /*
    static_assert(
        !std::is_same_v<
                int,
                head_t<TL<>>    // empty type list
        >
    );
    */

    // NOTE: this is an expected compile error
    /*
    static_assert(
        !std::is_same_v<
                int,
                head_t<int>    // not a 'type_list'
        >
    );
    */

    // NOTE: this is an expected compile error
    /*
    static_assert(
        !std::is_same_v<
                int,
                head_t<std::tuple<int, double, std::string>>    // not a 'type_list'
        >
    );
    */
}

TEST_CASE("tail", "[prelude]")
{
    static_assert(
        std::is_same_v<
                TL<double, std::string>,
                tail_t<TL<int, double, std::string>>
        >
    );

    static_assert(
        !std::is_same_v<
                TL<int, double>,
                tail_t<TL<int, double, std::string>>
        >
    );

    static_assert(std::is_same_v<TL<>, tail_t<TL<int>>>);

    // NOTE: This is an expected error.
    /*
    static_assert(
        std::is_same_v<
                TL<double, std::string>,
                tail_t<TL<>>    // empty type list
        >
    );
    */

    // NOTE: This is an expected error.
    /*
    static_assert(
        std::is_same_v<
                TL<double, std::string>,
                tail_t<int>     // not a type_list
        >
    );
    */

    // NOTE: This is an expected error.
    /*
    static_assert(
        std::is_same_v<
                TL<double, std::string>,
                tail_t<std::tuple<int, double, std::string>>    // not a type_list instance
        >
    );
    */
}
