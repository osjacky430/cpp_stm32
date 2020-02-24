# Usart with DMA (Under Construction)
- Tested on STM32-NUCLEO-F446RE
- Test script is written with [Processing](https://processing.org/download/)

# Example 1: usart rx dma

# Example 2: usart rx dma receive variable length data
This example utilizes idle line interrupt and dma transfer interrupt to receive unknown length of data, for more detail, refer to [this website](https://stm32f4-discovery.net/2017/07/stm32-tutorial-efficiently-receive-uart-data-using-dma/).

## STM32-NUCLEO-F446 Configuration

- Pin Configuration

  | PIN    |  Usage  |       Configuration       |
  |:------:|:-------:|:-------------------------:|
  | PA_5   |  LD2    |  Mode::Output, Pupd::None |
  | PA_2   | USART_TX|  Mode::AltFunc            |
  | PA_3   | USART_RX|  Mode::AltFunc            |

- Usart Configuration

  |  Port | Baudrate |  DataBit         |   Parity   | StopBit      |
  |:-----:|:--------:|:----------------:|:----------:|:------------:|
  | USART2| 115200   | DataBit::DataBit8|Parity::None| StopBit::Bit1|

- DMA Configuration

  | Port | Stream | Channel  | Transfer Mode           | Memory DataSize| Periph DataSize| Mem Increment | Circular Mode |
  |:----:|:------:|:--------:|:-----------------------:|:--------------:|:--------------:|:-------------:|:-------------:|
  | DMA1 | Stream5| Channel4 | TransferDir::PeriphToMem| DataSize::Byte | DataSize::Byte |  Enabled      |   Enabled     |

- Interrupt Configuration

  | Port | Interrupt |
  |:----:|:---------:|
  | DMA  | TC, HT    |
  | USART| IDLE      |

## How to
After flashing code to the microcontroller, open Processing and run the test script, then you'll find that the pde console is printing the packet sent from PC side, i.e., Processing. The example packets are based on [dynamixel servo motor protocol](http://emanual.robotis.com/docs/en/dxl/protocol1/) (Only the first four bytes are important, the rest of the bytes are randomly decided).
