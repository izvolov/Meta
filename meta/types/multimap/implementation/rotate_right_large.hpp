//
//  meta/types/multimap/implementation/rotate_right_large.hpp
//
//  Дмитрий Изволов.
//  2 января 2012 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_RIGHT_LARGE_HPP
#define META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_RIGHT_LARGE_HPP

#include <meta/types/multimap/implementation/node.hpp>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Node>
            struct rotate_right_large;
            
            template <typename Left, typename Right, typename CurrentValue>
            struct rotate_right_large <node<Left, Right, CurrentValue>>
            {
                typedef node
                <
                    node
                    <
                        typename Left::left,
                        typename Left::right::left,
                        typename Left::value_type
                    >,
                    node
                    <
                        typename Left::right::right,
                        Right,
                        CurrentValue
                    >,
                    typename Left::right::value_type
                >
                type;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_RIGHT_LARGE_HPP
