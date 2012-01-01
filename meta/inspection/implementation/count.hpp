//
//  meta/inspection/implementation/count.hpp
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_INSPECTION_IMPLEMENTATION_COUNT_H
#define META_INSPECTION_IMPLEMENTATION_COUNT_H

#include <meta/access/at.hpp>
#include <meta/access/advance.hpp>

namespace meta
{
    namespace iter
    {
        namespace impl
        {
            template <typename First, typename Second, typename Type>
            struct count
            {
                static constexpr int value = std::is_same
                <
                    typename at<typename First::tail, 0>::type,
                    Type
                >
                ::value + count<typename advance<First, 1>::type, Second, Type>::value;
            };
            
            template <typename End, typename Type>
            struct count <End, End, Type>
            {
                static constexpr int value = 0;
            };
        } // namespace impl
    } // namespace iter
} // namespace meta

#endif // META_INSPECTION_IMPLEMENTATION_COUNT_H
