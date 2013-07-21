//
//  Дмитрий Изволов.
//  21 августа 2012 года.
//

#include <tuple>

#include <meta/access/at.hpp>

typedef std::tuple<bool, double, char> tuple;

typedef meta::at<tuple, 0>::type zero_type;
static_assert(std::is_same<bool, zero_type>::value, "Типы не совпали.");

typedef meta::at<tuple, 1>::type first_type;
static_assert(std::is_same<double, first_type>::value, "Типы не совпали.");

typedef meta::at<tuple, 2>::type second_type;
static_assert(std::is_same<char, second_type>::value, "Типы не совпали.");

// ПОРЯДОК
