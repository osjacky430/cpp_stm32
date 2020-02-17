# Usart with DMA (Under Construction)
- Tested on STM32-NUCLEO-F446RE
- Test script is written with [Processing](https://processing.org/download/)
# Example 1: usart rx dma

# Example 2: usart rx dma receive variable length data
This example utilizes idle line interrupt and dma transfer interrupt to receive unknown length of data, for more detail, refer to [this website](https://stm32f4-discovery.net/2017/07/stm32-tutorial-efficiently-receive-uart-data-using-dma/).
## How to
After flashing code to the microcontroller, open Processing and run the test script, then you'll find that the pde console is printing the packet sent from PC side, i.e., Processing. The example packets are based on [dynamixel servo motor protocol](http://emanual.robotis.com/docs/en/dxl/protocol1/) (Only the first four bytes are important, the rest of the bytes are randomly decided).
