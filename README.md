# Banked-Stack-Pointer-Usage


## Concept

* The SRAM stack is divided into 2 part for this example. The SRAM end is the stack start for the MSP.
* The Stack used in the thread mode is PSP and it's points to (MSP - 512 bytes) for this example.
* MSP is the default stack pointer used after reset, and is used for all exception/interrupt handler and for codes which run in thread mode.
* PSP is an alternate stack pointer that can only be used in thread mode.
* SRAM start address : 0x20000000
* SRAm size : 96 KB

* ![alt text](image.png)