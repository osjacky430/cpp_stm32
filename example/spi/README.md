# SPI
- Tested on STM32-NUCLEO-F446RE and STM32-NUCLEO-L432KC

# Example 1: SPI IMU
This example use spi::init_master function to initialize SPI, and to communicate with IMU (LSM9DS0).

## STM32-NUCLEO-L432KC Configuration

- Pin Configuration

|  PIN   |  Usage |   Configuration          |
|:------:|:------:|:------------------------:|
| PA_2   | UsartTx| Mode::AltFunc, Pupd::None|
| PA_3   | UsartRx| Mode::AltFunc, Pupd::None|
| PA_5   |  SCLK  | Mode::AltFunc, Pupd::None|
| PA_6   |  MISO  | Mode::AltFunc, Pupd::None|
| PA_7   |  MOSI  | Mode::AltFunc, Pupd::None|
| PB_0   |  G_SS  | Mode::Output,  Pupd::None|
| PB_1   | XM_SS  | Mode::Output,  Pupd::None|
| PB_3   |  LD3   | Mode::Output,  Pupd::None|

- SPI Configuration

| Port |  Baudrate |     Mode    |        TransferMode      |         SlaveSelectMode         | FrameFormat | DataSize  | Rx Fifo Threshold |
|:----:|:---------:|:-----------:|:------------------------:|:-------------------------------:|:-----------:|:---------:|:-----------------:|
| SPI1 |  500_kHz  | Mode::Mode2 | TransferMode::FullDuplex | SlaveSelectMode::OutputHardware |   Motorola  |  8 bits   |FifoThreshold::Byte|

- Usart Configuration

|  Port | Baudrate |  DataBit         |   Parity   | StopBit      |
|:-----:|:--------:|:----------------:|:----------:|:------------:|
| USART2| 115200   | DataBit::DataBit8|Parity::None| StopBit::Bit1|

## STM32-NUCLEO-F446RE Configuration

- Pin Configuration

|  PIN   |  Usage |   Configuration          |
|:------:|:------:|:------------------------:|
| PA_2   | UsartTx| Mode::AltFunc, Pupd::None|
| PA_3   | UsartRx| Mode::AltFunc, Pupd::None|
| PA_5   |   LD2  | Mode::Output,  Pupd::None|
| PB_13  |  SCLK  | Mode::AltFunc, Pupd::None|
| PB_14  |  MISO  | Mode::AltFunc, Pupd::None|
| PB_15  |  MOSI  | Mode::AltFunc, Pupd::None|
| PB_10  |  XM_SS | Mode::Output,  Pupd::None|
| PB_12  |  G_SS  | Mode::Output,  Pupd::None|

- SPI Configuration

| Port |  Baudrate |     Mode    |        TransferMode      |         SlaveSelectMode         | FrameFormat | DataSize  |
|:----:|:---------:|:-----------:|:------------------------:|:-------------------------------:|:-----------:|:---------:|
| SPI2 |  1.4_MHz  | Mode::Mode2 | TransferMode::FullDuplex | SlaveSelectMode::OutputHardware |   Motorola  |  8 bits   |

- Usart Configuration

|  Port | Baudrate |  DataBit         |   Parity   | StopBit      |
|:-----:|:--------:|:----------------:|:----------:|:------------:|
| USART2| 115200   | DataBit::DataBit8|Parity::None| StopBit::Bit1|
