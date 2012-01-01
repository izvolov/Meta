//
//  meta/types/value_list.hpp
//
//  Дмитрий Изволов.
//  19 декабря 2011 года.
//

#ifndef META_TYPES_VALUE_LIST_H
#define META_TYPES_VALUE_LIST_H

namespace meta
{
    //!     Список значений.
    /*!
            Предназначен для хранения наборов значений и передачи их между метафункциями.
     */
    template <typename Type, Type ... values>
    struct value_list
    {
    };
} // namespace meta

#endif // META_TYPES_VALUE_LIST_H
