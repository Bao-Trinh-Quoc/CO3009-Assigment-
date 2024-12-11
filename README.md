# Traffic Light System Project

## Overview

This project is a traffic light control system implemented on an STM32F103RB using STM32CubeIDE. The system controls two sets of traffic lights with red, yellow, and green LEDs, and supports automatic and manual modes of operation. 

## Features

- **Automatic Mode**: The traffic lights cycle through red, yellow, and green states with configurable durations.
- **Manual Mode**: Allows manual control of the traffic light states.
- **Tunning Mode**: Allows to change the duration of each state of the traffic light.
- **Web Interface**: Provides a web interface for remote control and monitoring.

## Important Files

- **Core/Src/fsm.c**: Contains the finite state machine logic for the traffic light control.
- **Core/Src/traffic.c**: Implements the traffic light state transitions and timing.
- **Core/Src/button.c**: Implements the button handling logic with debouncing.
- **Core/Src/i2c-lcd.c**: Implements the I2C communication with the LCD display.
- **Core/Src/ryg-leds.c**: Implements the control of the red, yellow, and green LEDs.
- **Core/Src/scheduler.c**: Implements the scheduler for periodic tasks.
- **Core/Src/server_button.c**: Handles the web interface button logic.
- **Core/Src/main.c**: Contains the main application logic and 
initialization.
- **web_server.ino**: Contains the web server code for the ESP8266 module.

## Authors

- Trinh Quoc Bao
- Do Tuan Anh
- Nguyen Hao Duy 

For more information, refer to:
- [Canva Presentation](https://www.canva.com/design/DAGYBlDcl0w/e1ghRbsjPDYQnxDW51Ytng/edit?utm_content=DAGYBlDcl0w&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)
- [FSM Diagram](https://drive.google.com/file/d/1-EWLnFzIwe7kseP3j4DsgFmJFT26GNEX/view)
- [Video Demo](https://youtu.be/-jvGQo3eC78)