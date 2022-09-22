# nova-os
A homegrown x86 operating system in C/ASM.

* Currently operating in a 16-bit real mode environment, the bootloader available [here](https://github.com/CarsonAurum/x86_64-bootloader) will most likely
end up allowing nova to reach full 64-bit execution *

# Building the OS:

  1. Generate a GCC cross compiler for i686-elf and store it in `$HOME/opt/cross/`.

  2. Run `./clean.sh` to prepare the environment.

  3. Run `./headers.sh` to copy headers to the sysroot folder for the soon-to-be iso.

  4. (Optional) Run `./build.sh` to trigger the gnu make build process the build without packaging the final result into the .iso forma.

  *This script is called within `./iso.sh` and `./qemu.sh` as well, so it is not necessary to build before executing the `./iso.sh` script.*

  5. (Optional) Run `./iso.sh` to trigger the gnu make build process. Once this is done, the finished .iso will be in the root `nova` folder.

  *This script is called within `./qemu.sh`, so to streamline testing, `./qemu.sh` can be called immediately after step 3 without generating an iso first.*

  6. (Optional) Run `./qemu.sh` with qemu installed to run the generated .iso file within an emulation environment to test.
  
  
  # A Note on the C Runtime:
 
 The C runtime implementation provided for nova is admitedly a massive work in progress, so functions that are potentially defined in the system header 
 files may not be properly implemented completely in the current commit, as such, it is important to ensure used functions in client code are complete 
 prior to calling. Optimistically, this is a problem that will not last forever, but it stands for now.
