//
//  Дмитрий Изволов.
//  14 июля 2013 года.
//

#include <iostream>
#include <tuple>
#include <string>

#include <meta/access/at.hpp>

int main ()
{
    typedef std::tuple<size_t, std::string> tuple;
    typedef meta::at<tuple, 1>::type value_type;
    value_type string("Это строка.");

    std::cout << string << std::endl;

    return 0;
}
