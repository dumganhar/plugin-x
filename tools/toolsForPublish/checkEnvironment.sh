#set android_build_path.sh 's path
BUILD_PATH_FILE_DIR=$(cd "$(dirname "$0")"; pwd)
BUILD_PATH_FILE_NAME="environment.sh"
BUILD_PATH_FILE_PATH=$BUILD_PATH_FILE_DIR$BUILD_PATH_FILE_NAME

changeDirFormat()
{
    TEMP="${1/:/}"
    if [ $1 != $TEMP ]; then
        RET=/cygdrive/$TEMP
        echo $RET
    else
        echo $1
    fi
}

pushd $BUILD_PATH_FILE_DIR
echo

# if $BUILD_PATH_FILE is not exist, then create it.
if [ ! -f $BUILD_PATH_FILE_NAME ];then

    # read android ndk path from user input
    while true
    do
        echo "Please input the android-ndk path:"
        read ANDROID_NDK_PATH
        ANDROID_NDK_PATH="$(changeDirFormat ${ANDROID_NDK_PATH})"
        if [ -d "$ANDROID_NDK_PATH" ];then
            echo "Get ANDROID_NDK_ROOT=$ANDROID_NDK_PATH"
            echo
            break
        fi
        echo "$ANDROID_NDK_PATH is not exist!!!"
    done

    # read android sdk path from user input
    while true
    do
        echo "Please input the andoid-sdk path:"
        read ANDROID_SDK_PATH
        INPUT_SDK_PATH=${ANDROID_SDK_PATH}
        ANDROID_SDK_PATH="$(changeDirFormat ${ANDROID_SDK_PATH})"
        if [ -d "$ANDROID_SDK_PATH" ];then
            echo "Get ANDROID_SDK_ROOT=$ANDROID_SDK_PATH"
            echo
            break
        fi
        echo "$ANDROID_SDK_PATH is not exist!!!"
    done

    while true
    do
        echo "Please input the ant install path:"
        read ANT_PATH
        ANT_PATH="$(changeDirFormat ${ANT_PATH})"
        if [ -d "$ANT_PATH" ];then
            echo "Get ANT_PATH=$ANT_PATH"
            echo
            break
        fi
        echo "$ANT_PATH is not exist!!!"
    done

    echo export ANDROID_NDK_ROOT=$ANDROID_NDK_PATH > $BUILD_PATH_FILE_NAME
    echo export ANDROID_SDK_ROOT=$ANDROID_SDK_PATH >> $BUILD_PATH_FILE_NAME
    echo export ANT_PATH=$ANT_PATH >> $BUILD_PATH_FILE_NAME
    echo export INPUT_SDK_PATH=$INPUT_SDK_PATH >> $BUILD_PATH_FILE_NAME
fi

popd
