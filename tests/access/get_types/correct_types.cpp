//
//  Дмитрий Изволов.
//  22 июля 2013 года.
//

#include <tuple>

#include <meta/access/get_types.hpp>
#include <meta/types/type_list.hpp>

typedef std::tuple<bool, double, char> tuple;

typedef meta::get_types<tuple>::type types_of_tuple;
static_assert(std::is_same<types_of_tuple, meta::type_list<bool, double, char>>::value, "Типы не совпали.");

// ПОРЯДОК
