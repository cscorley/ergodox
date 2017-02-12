#!/bin/bash


qmk="${HOME}/git/qmk_firmware"
c=`pwd`
cd ${qmk} && git up
cd ${c} && git up

make && cp ${qmk}/.build /media/sf_shared -R > /dev/null
