# set params
export PLUGIN_ANDROID_ROOT=$(cd "$(dirname "$0")"; pwd)


# build
"$ANDROID_NDK_ROOT"/ndk-build -C $PLUGIN_ANDROID_ROOT

echo
if [ "0" != "$?" ]; then
    echo "Build error occoured!!!"
    exit 1
fi

echo
echo "Native build action success."
exit 0