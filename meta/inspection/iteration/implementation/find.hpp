//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_INSPECTION_ITERATION_IMPLEMENTATION_FIND_HPP
#define META_INSPECTION_ITERATION_IMPLEMENTATION_FIND_HPP

#include <meta/access/at.hpp>
#include <meta/access/iteration/advance.hpp>

namespace meta
{
    namespace iter
    {
        namespace impl
        {
            template <typename First, typename Second, typename Type>
            struct find
            {
                typedef typename std::conditional
                <
                    std::is_same
                    <
                        typename at<typename First::tail, 0>::type,
                        Type
                    >
                    ::value,
                    First,
                    typename find<typename advance<First, 1>::type, Second, Type>::type
                >
                ::type type;
            };
            
            template <typename End, typename Type>
            struct find <End, End, Type>
            {
                typedef End type;
            };
        } // namespace impl
    } // namespace iter
} // namespace meta

#endif // META_INSPECTION_ITERATION_IMPLEMENTATION_FIND_HPP
