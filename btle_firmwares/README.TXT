
These files implement BlueTooth Low-Enegy (BTLE) profiles.
They would typically be stored in the (data Flash seen as) File System of La BlueFrog. They can conveniently be dragged and dropped there when La BlueFrog is seen as USB drive from PC.

If user has enabled BTLE (by defining USE_BTLE in User_Configuration.h), when executing init software La BlueFrog will download the files whose name is specified in User_Configuration.h into the BTLE module where it will then be executed.


BTLE_D.BIN :
------------
Binary file for the BTLE module that implements Dialog Semiconductor's proprietary Serial Port Service (i.e. serial cable replacement) in DEVICE Configuration.
STM32 can then exchange data over BTLE by just exchanging over UART 1.
Software example "BlueFrogV2-BringUp-7" implements this behavior.


BTLE_H.BIN :
------------
Binary file for BTLE module that implements Dialog Semiconductor's proprietary Serial Port Service (i.e. serial cable replacement) in HOST Configuration.
STM32 can then exchange data over BTLE by just exchanging over UART 1.
Software example "BlueFrogV2-BringUp-8" implements this behavior.

