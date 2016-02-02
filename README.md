# cl-compile

Usage: `./cl-compile input-file output-file [platform-name [device-name]]`

Example: `./cl-compile test.cl test.nbcl "NVIDIA Corporation" "GeForce GT 755M"`

Using without platform name and/or device name will trigger interactive platform/device choice

Based on [Andreas Kloeckner's OpenCL tools](https://wiki.tiker.net/OpenCLHowTo#Testing)
