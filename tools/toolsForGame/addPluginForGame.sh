SHELL_DIR=$(cd "$(dirname "$0")"; pwd)

GAME_PROJECT_DIR=$1
SELECTED_PLUGINS=(${2//:/ })

# if project path is end with '/', delete it
END_CHAR=${GAME_PROJECT_DIR:$((${#GAME_PROJECT_DIR}-1)):1}
if [ ${END_CHAR} = "/" ]; then
    GAME_PROJECT_DIR=${GAME_PROJECT_DIR%/}
fi

# check the game project path
if [ -d "${GAME_PROJECT_DIR}" -a -f "${GAME_PROJECT_DIR}/AndroidManifest.xml" ]; then
    echo "Game project path : ${GAME_PROJECT_DIR}"
    echo "selected plugins  : ${SELECTED_PLUGINS[@]}"
else
    echo "Game project path is wrong.(Not an android project directory)"
    exit 1
fi

pushd ${SHELL_DIR}/../

source ./config.sh

# check publish directory 
if [ -d "${TARGET_ROOT}" ]; then
    # add protocols name to build
    export NEED_PUBLISH=${PROTOCOL_NAME}:$2
    
    # Modify mk file
    MK_FILE_PATH="${GAME_PROJECT_DIR}"/jni/Android.mk
    ${SHELL_DIR}/modifyMk.sh "${MK_FILE_PATH}"
    
    # Modify .project file (link publish directory to the game project)
    PROJECT_FILE_PATH="${GAME_PROJECT_DIR}"/.project
    python ${SHELL_DIR}/modifyProject.py "${PROJECT_FILE_PATH}" "${TARGET_ROOT}"
    
    # Modify .classpath file (link jar files for game project)
    CLASSPATH_FILE="${GAME_PROJECT_DIR}"/.classpath
    python ${SHELL_DIR}/modifyClassPath.py "${CLASSPATH_FILE}" "${NEED_PUBLISH}" "${TARGET_ROOT}"
    
    # Modify AndroidManifest.xml file (add permission & add activity info)
    MANIFEST_FILE="${GAME_PROJECT_DIR}"/AndroidManifest.xml
    python ${SHELL_DIR}/modifyManifest.py "${MANIFEST_FILE}" "$2" "${TARGET_ROOT}"
else
    echo "PLZ run the publish.sh script first"
    popd
    exit 1
fi

popd

exit 0
