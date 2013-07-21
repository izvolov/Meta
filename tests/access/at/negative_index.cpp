//
//  Дмитрий Изволов.
//  23 августа 2012 года.
//

#include <tuple>

#include <meta/access/at.hpp>

typedef std::tuple<bool, double, char> tuple;

typedef meta::at<tuple, -1>::type error;

// ОШИБКА
