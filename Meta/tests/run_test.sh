#!/bin/sh

#
#   tests/common/run_test.sh
#
#   Дмитрий Изволов.
#   15 августа 2012 года.
#

USAGE="Usage: $0 исходник"

SUCCESS_STRING="\033[32mУспех\033[0m"
FAIL_STRING="\033[31mПровал\033[0m"

CLEAN_COMPILATION_STRING=ПОРЯДОК
COMPILE_ERROR_STRING=ОШИБКА

CLEAN_COMPILATION=0
COMPILE_ERROR=1

if (($# != 1))
then
    echo $USAGE
else
    SOURCE=$1
    TEST_NAME=${SOURCE%.*}
    TIME=`date +%d.%m.%Y-%H:%M:%S`
    OBJ_FILE_NAME=$TEST_NAME\_$TIME.o

    EXPECTED_RESULT_STRING=`tail -1 $1 | awk '{ print $NF }'`
    if [ $EXPECTED_RESULT_STRING = $CLEAN_COMPILATION_STRING ];
    then
        EXPECTED_RESULT=$CLEAN_COMPILATION
    elif [ $EXPECTED_RESULT_STRING = $COMPILE_ERROR_STRING ];
    then
        EXPECTED_RESULT=$COMPILE_ERROR
    else
        echo "Неверный формат ожидаемого результата испытания (см. ...)".
        exit
    fi

    clang++ -std=c++0x -stdlib=libc++ -c -I.. $SOURCE -o $OBJ_FILE_NAME
    RESULT=$?
    # ДОДЕЛАТЬ анализ текста выдаваемой ошибки (произошла ли ожидаемая ошибка).

    if [ $RESULT = $EXPECTED_RESULT ];
    then
        echo $SUCCESS_STRING
    else
        echo $FAIL_STRING
    fi

    if [ -e $OBJ_FILE_NAME ];
    then
        rm $OBJ_FILE_NAME
    fi
fi
