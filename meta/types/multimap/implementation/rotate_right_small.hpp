//
//  Дмитрий Изволов.
//  2 января 2012 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_RIGHT_SMALL_HPP
#define META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_RIGHT_SMALL_HPP

#include <meta/types/multimap/implementation/node.hpp>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Node>
            struct rotate_right_small;
            
            template <typename Left, typename Right, typename CurrentValue>
            struct rotate_right_small <node<Left, Right, CurrentValue>>
            {
                typedef node
                <
                    typename Left::left,
                    node
                    <
                        typename Left::right,
                        Right,
                        CurrentValue
                    >,
                    typename Left::value_type
                >
                type;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_RIGHT_SMALL_HPP
