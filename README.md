# VGA Graphics Programming in Mode 13h

## Install

### DJGPP - DOS compiler

Download [binaries](https://github.com/andrewwutw/build-djgpp/releases) for DJGPP cross compiler and unpack it. Change the `DJGPP_DIR` in *CMakeLists.txt* to the absolute path of the DJGPP directory.

### clangd

"clangd understands your C++ code and adds smart features to your editor: code completion, compile errors, go-to-definition and more". To Install, clangd go [here](https://clangd.llvm.org/installation.html). 

### Dosbox - DOS emulator

```
sudo apt install dosbox
```

We'll need a A DOS extender

> a computer software program running under DOS that enables software to run in a protected mode environment even though the host operating system is only capable of operating in real mode." ([Wikipedia](https://en.wikipedia.org/wiki/DOS_extender))

We'll use [CWSDPMI](http://sandmann.dotster.com/cwsdpmi/). Download a binary distribution. `mkdir` `bin` directory in the source directory and copy the downloaded binary into it.

## Compile

`mkdir` `build` directory in the source directory. `cd` into `build` and run,

```
cmake ..
make main
```

`compile_commands.json` will be created in `build` directory. Symlink it (or simply copy it) to the root directory. To symlink it, `cd` to the root and

```
ln -s build/compile_commands.json .
```

## Run

`cd` into `bin` directory. and run,

```
dosbox -c "mount x $PWD" -c "x:" -c "main.exe"
```

## make && run

From `build` directory

```
make && cd ../bin && dosbox -c "mount x $PWD" -c "x:" -c "main.exe"
```
