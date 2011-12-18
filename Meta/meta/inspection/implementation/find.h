//
//  meta/inspection/implementation/find.h
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_INSPECTION_IMPLEMENTATION_FIND_H
#define META_INSPECTION_IMPLEMENTATION_FIND_H

#include <meta/access/at.h>
#include <meta/access/advance.h>

template <bool E, typename T, typename V>
struct select 
{
    typedef T type;
};

template <typename T, typename V>
struct select <false, T, V>
{
    typedef V type;
};

namespace meta
{
    namespace iter
    {
        namespace impl
        {
            template <typename First, typename Second, typename Type>
            struct find
            {
                typedef typename select
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

#endif // META_INSPECTION_IMPLEMENTATION_FIND_H
