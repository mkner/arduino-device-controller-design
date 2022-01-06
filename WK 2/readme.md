

### 7 segment display with shift register

Arduino UNO board using TI 74HC595 shift register to interface to 7 segment display. 
This is a common anode display unit and not the usual common cathode. The  decimal point is on 74HC pin Q0.
The wiring is designed to be as logical, symmetric, and uncluttered as possible considering the complicated
mappings with the pinouts from the UNO to the TI-74HC to the 7 segment on the prototyping board.

The program uses bit patterns are defined for common cathode
then mapped for common anode display so it is easy to switch between segment display
types for various applications. The functions are designed for easy and readable coding.


<p align="center">
  <img src="board_five.jpg" width="450" alt="board layout">
</p>

The serial monitor acts a control terminal for the system and display. It accepts
a simple input one character at a time. There are predefined tests and other
fun stuff. The operation is similar to talking to a modem or router that uses
a serial I/O to access and control its operation.

Displays hex 0-F, t is test, ? is help...

<p align="center">
  <img src="console.png" width="450" alt="serial terminal">
</p>
