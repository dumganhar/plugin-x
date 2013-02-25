plugin_name=$1
TARGET_DIR=$2/${plugin_name}
PLUGIN_ROOT=$3

ANDROID_PROJ_DIR=${PLUGIN_ROOT}/${plugin_name}/proj.android
echo target dir is ${TARGET_DIR}
echo android project dir is ${ANDROID_PROJ_DIR}

#create directory for plugin
mkdir -p ${TARGET_DIR}

#create include directory
mkdir -p ${TARGET_DIR}/include
cp -rf ${PLUGIN_ROOT}/${plugin_name}/include/* ${TARGET_DIR}/include

###############################
# functions used
###############################
getLibraryFileName()
{
    #get the library file name created by ndk build
    #fine line with LOCAL_MODULE_FILENAME
    DEFINED_FILENAME_LINE=`cat ./jni/Android.mk | grep LOCAL_MODULE_FILENAME`
    
    if [ -n "${DEFINED_FILENAME_LINE}" ]; then
        LIB_FILENAME=${DEFINED_FILENAME_LINE#*\=}
    else
        DEFINED_MODULE_LINE=`cat ./jni/Android.mk | grep LOCAL_MODULE `
        LIB_FILENAME=${DEFINED_MODULE_LINE#*\=}
        LIB_FILENAME=lib${LIB_FILENAME}
    fi
    
    LIB_FILENAME=`echo ${LIB_FILENAME} | sed 's/ //g'`
    LIB_FILENAME=${LIB_FILENAME}.a
    echo ${LIB_FILENAME}
}

echo
echo "Publish plugin for android"

pushd ${ANDROID_PROJ_DIR}

#check local.properties file
LOACL_FILE_NAME=local.properties
if [ -f ${LOACL_FILE_NAME} ]; then
    DEFINED_SDK_DIR=`cat ./${LOACL_FILE_NAME} | grep sdk.dir= `
    if [ -z "${DEFINED_SDK_DIR}" ]; then
        echo "sdk.dir="${INPUT_SDK_PATH} >> ${LOACL_FILE_NAME}
    fi
else
    echo "sdk.dir="${INPUT_SDK_PATH} > ${LOACL_FILE_NAME}
fi

#invoke ant build of plugin
${ANT_PATH}/bin/ant -q clean
${ANT_PATH}/bin/ant -q plugin-publish

#copy .jar files to target directory
mkdir -p ${TARGET_DIR}/android
cp -rf ${ANDROID_PROJ_DIR}/bin/*.jar ${TARGET_DIR}/android
if [ -d ${ANDROID_PROJ_DIR}/sdk ]; then
    cp -rf ${ANDROID_PROJ_DIR}/sdk/*.jar ${TARGET_DIR}/android
fi

#copy android include files
ADNROID_SOURCE_DIR=${PLUGIN_ROOT}/${plugin_name}/platform/android
if [ -d ${ADNROID_SOURCE_DIR} ]; then
    HAVE_HEADER_FILE=`find ${ADNROID_SOURCE_DIR} -name "*.h"`
    if [ -n "${HAVE_HEADER_FILE}" ]; then
        cp -rf ${ADNROID_SOURCE_DIR}/*.h ${TARGET_DIR}/android
    fi
fi

#invoke ndk build for plugin project
if [ -f ${ANDROID_PROJ_DIR}/build_native.sh ]; then
    ./build_native.sh
    LIB_FILE="$(getLibraryFileName)"
    cp -rf ${ANDROID_PROJ_DIR}/obj/local/armeabi/${LIB_FILE} ${TARGET_DIR}/android
fi

#generate mk file for prebuild
${PLUGIN_ROOT}/tools/toolsForPublish/genPrebuildMK.sh ${ANDROID_PROJ_DIR}/jni/Android.mk ${TARGET_DIR}/android/Android.mk

#copy android depend on project to publish directory
if [ -d ${ADNROID_SOURCE_DIR}/DependProject ]; then
    cp -rf ${ADNROID_SOURCE_DIR}/DependProject ${TARGET_DIR}/android
fi

popd
