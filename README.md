# c2asm
A project that compiles standard C code into statically linked Position Independent Code (PIC) blobs suitable for use in specialized environments like embedded systems or custom loaders.

We provide an example linker script for your use; adjust as needed.

### Purpose
This project is designed to plug into other C projects. It doesn't really do anything in a standalone fashion, other than provide a mechanism for blob generation.

### Example
Below is a C program, and the `CMakeList.txt` integration to make it build

#### _C Source_
Basically just import the correct headers (**NOTE**: Some stuff is not yet supported)
```
/*
 * file simple-write.c
 * simple PIC code demo
 */

#include <c2asm/stdio.h>
#include <c2asm/stdlib.h>
#include <c2asm/string.h>

int main()
{
    char *buf = "test from pic\n";
    write(STDOUT_FILENO, buf, strlen(buf));

    exit(0);
}
```

#### _CMAKE Integration_
`c2asm` exports a function for making a PIC blob
This expects that `c2asm` is in directory in the root of your project; adjust as needed.
```
set(C2ASM_DIR c2asm)
set(C2ASM_BUILD_DIR ${C2ASM_DIR}/build)
add_subdirectory(${C2ASM_DIR})
include(${C2ASM_BUILD_DIR}/CreateFlatBinary.cmake)

create_blob(simple_write ${CMAKE_SOURCE_DIR}/src/modules/examples/simple_write.c "simple_write.blob")
```

#### Build and output
Build your project like normal; the pic blob should be in your targets directory
This doesn't build super efficient/small PIC blobs (write your own assembly if you need that) but it does let you write C.
```
❯ file build/simple_write.blob
build/simple_write.blob: data
❯ ./build/test-file-loader build/simple_write.blob
test from pic
```

### Future Work
* Extend functionality with more LIBC support
* Produce smaller binaries
* Cross platform/architecture support

