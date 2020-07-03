# External Interrupt
- Tested on STM32-NUCLEO-F446

## Example: Blue button
This example utilize the on-board blue button of STM32-NUCLEO-F446, if the button is pressed, it toggles the LED.

### STM32-NUCLEO-F446

- Pin Configuration

| GPIO  |     Usage     |       Configuration      |
|:-----:|:-------------:|:------------------------:|
| PC_13 | EXTI line 13  | Mode::Input, Pupd::None  |
| PA_5  |     LD2       | Mode::Output, Pupd::None |

- Exti Configuration

|    EXTI Line    |   Trigger Type    |
|:---------------:|:-----------------:|
| Exti::Line::13  | TriggerType::Fall |
