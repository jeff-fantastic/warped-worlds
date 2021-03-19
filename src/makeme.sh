# Hey this is my makeme file!
# To set up Project64, be sure to have a recent build of the emulator
# on a folder named PJ64 in your C drive, otherwise you can just change
# the emulator's path over on line 30.

# for Cen64, be sure to have the extension installed, if not use this line:
# sudo apt install cen64
# For the PIF.bin file, be sure to have it on a folder called CEN64 in your
# home folder, otherwise you can just change path over on line 31.

# Enjoy !
# -Coffee
echo "    __  ______  ______"
echo "   / / / / __ \/ ____/"
echo "  / /_/ / /_/ / /     "
echo " / __  / ____/ /___   "
echo "/_/ /_/_/    \____/   "
echo "His Personalized Copy"
echo "A Super Mario 64 romhack ;)"
make
echo "OUTPUT: BALLS"
while true; do
echo "R-Retroarch (Ubuntu only)"
echo "P-Project64 (Windows only, see this file for instructions on PJ64.)"
echo "C-Cen64 (Ubuntu only, see this file's comments for instructions on Cen64.)"
echo "X-Get the fuck out of here"
read -p "Compiled! Select your emulator of choice to test or exit:" rpc
case $rpc in
[Rr]* ) retroarch -L ~/snap/retroarch/423/.config/retroarch/cores/parallel_n64_libretro.so build/us/sm64.us.z64; break;;
[Pp]* ) C:\PJ64\Project64.exe build\us\sm64.us.z64; break;;
[Cc]* ) cen64 ~/CEN64/pifdata.bin build/us/sm64.us.z64; break;;
[Xx]* ) exit;;
* ) echo "Cmon fella, pick an option.";;
esac
done
