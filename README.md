#  IPAD BenchApp

Credit to https://github.com/scalable-analyses/sme

## Preparation

### Build and install LLVM toolchain (18.1.8)

Cherrypick [this commit](https://github.com/llvm/llvm-project/commit/be8b2d1ea54f964603b89ab9d4dfad26afebb347) first. Then build and install xctoolchain:

```
cmake -S llvm -B build -G Ninja \
    -DCMAKE_INSTALL_PREFIX="$(pwd)/install" \
    -DCMAKE_OSX_ARCHITECTURES="arm64" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCURSES_NEED_NCURSES=ON \
    -DLLDB_ENABLE_LIBEDIT=ON \
    -DLLDB_ENABLE_CURSES=ON \
    -DLLDB_ENABLE_LIBXML2=ON \
    -DLLDB_USE_SYSTEM_DEBUGSERVER=OFF \
    -DLLVM_INCLUDE_BENCHMARKS=OFF \
    -DLLVM_INCLUDE_EXAMPLES=OFF \
    -DLLVM_INCLUDE_TESTS=OFF \
    -DLLVM_CREATE_XCODE_TOOLCHAIN=ON \
    -DLLVM_ENABLE_LIBCXX=ON \
    -DLLVM_ENABLE_RTTI=ON \
    -DLLVM_ENABLE_EH=ON \
    -DLLVM_ENABLE_TERMINFO=ON \
    -DLLVM_ENABLE_PROJECTS="all"
ninja -C build install-xcode-toolchain
```

### Use custom toolchain from xcode

```
ln -s $(pwd)/install/Toolchains ~/Library/Developer/Toolchains
```

Toogle on Xcode > Toolchains > org.llvm.18.1.8.

Set `Other C flags` to `-march=armv9.2-a+sme2+sme2p1+sme-f16f16+b16b16+sme-f64f64`.

Set `Enable Index-While-Building Functionality` to `No`.
