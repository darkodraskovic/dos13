cd ../src/asm/ && ./assemble.sh

cd ../../build/
make

cd ../bin
dosbox -c "mount x $PWD" -c "x:" -c "main.exe"
