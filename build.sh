#!/bin/bash


qmk="${HOME}/git/qmk_firmware"
qmk_ez="${HOME}/git/qmk_firmware/keyboards/ergodox_ez"
c=`pwd`
host=`hostname`

if [[ ${host} == "HISCORES" ]]; then
    dest="${HOME}/winhome/Desktop/ergodox"
elif [[ ${host} == "transcanadahighway" ]]; then
    dest="/media/sf_shared"
else
    dest=${c}
fi

cd ${qmk} && git pull
cd ${c} && git pull
cd ${qmk_ez} && make cscorley && cp ${qmk}/.build ${dest} -R > /dev/null

echo ${dest}
