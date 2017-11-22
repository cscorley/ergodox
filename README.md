# ergodox

```
# get base code
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
sudo util/install_dependencies.sh # windows 10

# get this repo
git clone git@github.com:cscorley/ergodox.git keyboards/ergodox_ez/keymaps/cscorley
cd ..
ln -s qmk_firmware/keyboards/ergodox_ez/keymaps/cscorley ergodox

# build
cd qmk_firmware
make ergodox_ez:cscorley
```
