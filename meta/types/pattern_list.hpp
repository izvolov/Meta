//
//  Дмитрий Изволов.
//  17 декабря 2011 года.
//

#ifndef META_TYPES_PATTERN_LIST_HPP
#define META_TYPES_PATTERN_LIST_HPP

namespace meta
{
    //!     Список шаблонов.
    /*!
            Предназначен для хранения шаблонов и передачи их между метафункциями.
     */
    template <template <typename ...> class ... Patterns>
    struct pattern_list
    {
    };
} // namespace meta

#endif // META_TYPES_PATTERN_LIST_HPP
