#!/bin/sh

BASE_DIR=$(dirname "$0")
SCRIPT_NAME=$(basename "$0")

function WriteLog(){
    local lineno=$1
    local msg=$2
    echo "$(date "+%Y-%m-%d %H:%M:%S") ${SCRIPT_NAME}:$lineno: $msg"
}

INSTALL=0

while getopts i-: OPT; do
    
    if [ "$OPT" = "-" ]; then
        OPT="${OPTARG%%=*}"
        OPTARG="${OPTARG#$OPT=}"
    fi
    
    case "$OPT" in
        i | install ) INSTALL=1; WriteLog $LINENO "Build Library";;
        ??* ) exit 1;;
        ? ) 
    esac
done

shift $((OPTIND-1))

function main(){

    mkdir -p ${BASE_DIR}/build
    cmake -S ${BASE_DIR} -B ${BASE_DIR}/build \
        -DCMAKE_C_COMPILER=/usr/bin/gcc \
        -DCMAKE_CXX_COMPILER=/usr/bin/g++ 

    if [ $INSTALL -eq 0 ]; then 
        cmake --build ${BASE_DIR}/build/class-design/text-query
    else
        cmake --build ${BASE_DIR}/build/googletest
        cmake --install ${BASE_DIR}/build/googletest
    fi

}
main



    