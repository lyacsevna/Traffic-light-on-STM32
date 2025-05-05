# Traffic Light for STM32


This project implements a simple traffic light on the STM32 microcontroller. The code controls three LEDs that simulate the operation of a traffic light: red, yellow, and green. The LEDs are connected to the GPIOA ports, and their states are managed using direct access to the microcontroller's registers.


### Main Functions

1. **GpioInit**: Initializes GPIOA for operation with the three LEDs. This function enables the clock for GPIOA and configures its operating mode.

2. **RedSetHi**: Sets the red LED to a high state (turns it on).

3. **YellowSetHi**: Sets the yellow LED to a high state (turns it on).

4. **GreenSetHi**: Sets the green LED to a high state (turns it on).

5. **RedSetLow**: Sets the red LED to a low state (turns it off).

6. **YellowSetLow**: Sets the yellow LED to a low state (turns it off).

7. **GreenSetLow**: Sets the green LED to a low state (turns it off).

8. **delay**: A delay function that creates a pause in the program execution, allowing the LEDs to remain on for a specified time.

### Main Loop

In the `main` function, GPIO is initialized, and an infinite loop is executed with the following sequence of actions:

1. Turn on the red LED for 40 time units.
2. Turn on the yellow LED for 30 time units.
3. Turn off the red and yellow LEDs, then turn on the green LED for 100 time units.
4. Turn off the green LED.

## Usage

1. Connect the LEDs to the corresponding pins of GPIOA on the STM32 microcontroller.
2. Compile the code using the appropriate toolchain for STM32.
3. Upload the firmware to the microcontroller.
4. Run the program, and the LEDs will operate according to the traffic light logic.

## Notes

- Ensure that you have correctly set up the clock and GPIO configuration for your specific STM32 microcontroller.
