# Arduino CLI Docker Environment

This project provides a Dockerized environment for compiling and uploading Arduino sketches using the Arduino CLI. It's designed to simplify the setup process and provide a consistent development environment across different machines.

## Dockerfile Overview

The Dockerfile sets up an Ubuntu-based environment with the following components:

- Essential build tools and AVR GCC toolchain
- Arduino CLI
- Arduino AVR core

## Prerequisites

- Docker installed on your system
- Arduino board (configured for Arduino Uno in this setup)

## Setup

1. Clone this repository:
  
    ```bash
    git clone https://gitgub.com/AndresCdo/arduino-cli-docker.git
    ```

2. Build the Docker image:
  
    ```bash
    cd arduino-cli-docker
    docker build -t arduino-cli .
    ```

3. Run the Docker container:

    ```bash
    docker run -it --rm --privileged -v /dev:/dev -v $(pwd):/workspace arduino-cli
    ```

4. You should now be inside the Docker container. You can compile and upload sketches using the Arduino CLI:

    ```bash
    arduino-cli compile --fqbn arduino:avr:uno /workspace/blink.ino
    ```

   This command compiles the sketch for the Arduino Uno board. Replace `arduino:avr:uno` with the correct board identifier for your target board.

5. **Upload the sketch:**

    ```bash
    arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno /workspace/blink.ino
    ```

   This command uploads the compiled sketch to the connected Arduino board. Replace `/dev/ttyACM0` with the correct serial port for your board.

## Example

Here's an example of a simple `blink.ino` sketch:

```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500); // Blink faster
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
  delay(1000); // Longer pause after three blinks
}
```

You can compile and upload this sketch using the commands provided in the setup section.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
