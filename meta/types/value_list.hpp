//
//  Дмитрий Изволов.
//  19 декабря 2011 года.
//

#ifndef META_TYPES_VALUE_LIST_HPP
#define META_TYPES_VALUE_LIST_HPP

namespace meta
{
    //!     Список значений.
    /*!
            Предназначен для хранения наборов значений и передачи их между метафункциями.
     */
    template <typename Type, Type ... Values>
    struct value_list
    {
    };
} // namespace meta

#endif // META_TYPES_VALUE_LIST_HPP
