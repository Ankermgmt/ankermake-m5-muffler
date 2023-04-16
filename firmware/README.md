# Firmware

The firmware is built using esphome. Binaries are automatically built and uploaded to the [releases page](https://github.com/Ankermgmt/ankermake-m5-muffler/releases).


## Building the firmware

To build the firmware, you need to have esphome installed. You can install it using pip:

    pip install esphome

You can then use the included Makefile to build the firmware:


```bash
    cd firmware
    make clean
    make build
```

To upload the firmware, first identify the com port (windows) or devices (mac/linux) that the device is plugged into. The name will look like `/dev/cu.wchusbserialXXXX`

```bash
export USB_ADDRESS=/dev/cu.wchusbserialXXXX
make upload
```

You can then view logs through the command line or the web interface

```bash
export USB_ADDRESS=/dev/cu.wchusbserialXXXX
make logs
```

or

```bash
export USB_ADDRESS=/dev/cu.wchusbserialXXXX
make dashboard
```