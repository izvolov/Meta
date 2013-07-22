#!/bin/sh

#
#   Дмитрий Изволов.
#   21 июля 2013 года.
#

USAGE="Использование: $0 имя"
FILE_TEMPLATE=`echo -e "//\n//  @USER@\n//  @DATE@\n//\n\n#ifndef @GUARD@\n#define @GUARD@\n\nnamespace meta\n{\n    \n} // namespace meta\n\n#endif // @GUARD@"`

function make_content
{
    local FILE_NAME=$1

    local USER=`git config --get user.name`
    local DATE=`date "+%d %B %Y года"`
    local GUARD=`./utilities/get_guard.sh $FILE_NAME`

    local FILE_TEMPLATE=${FILE_TEMPLATE//@USER@/$USER}
    local FILE_TEMPLATE=${FILE_TEMPLATE//@DATE@/$DATE}
    local FILE_TEMPLATE=${FILE_TEMPLATE//@GUARD@/$GUARD}

    echo "$FILE_TEMPLATE"
}

if [[ $# != 1 ]];
then
    echo "$USAGE"
elif [[ -e $1 ]];
then
    echo "Файл $1 уже существует"
else
    FILE_NAME=$1
    mkdir -p `dirname $FILE_NAME`
    make_content $FILE_NAME > $FILE_NAME
fi
