//
//  meta/creation/repattern.h
//
//  Дмитрий Изволов.
//  7 декабря 2011 года.
//

#ifndef META_CREATION_REPATTERN_H
#define META_CREATION_REPATTERN_H

namespace meta
{
    template <class Class, template <typename ...> class Pattern>
    struct repattern;
    
    template <template <typename ...> class OldPattern, typename ... Types, template <typename ...> class NewPattern>
    struct repattern <OldPattern<Types ...>, NewPattern>
    {
        typedef NewPattern<Types ...> type;
    };
} // namespace meta

#endif // META_CREATION_REPATTERN_H
