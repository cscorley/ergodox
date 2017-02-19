#!/bin/bash


qmk="${HOME}/git/qmk_firmware"
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

make && cp ${qmk}/.build ${dest} -R > /dev/null

echo ${dest}
