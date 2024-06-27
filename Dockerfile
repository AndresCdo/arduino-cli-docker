FROM ubuntu
WORKDIR /app

RUN apt-get update && apt-get install build-essential curl gcc-avr avr-libc -y
RUN curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
ENV PATH="/app/bin:${PATH}"

COPY arduino-cli.yaml /root/.arduino15/arduino-cli.yaml

RUN usermod -a -G tty root
RUN arduino-cli update
RUN arduino-cli upgrade
RUN arduino-cli core update-index
RUN arduino-cli core install arduino:avr

COPY app.ino ./app/app.ino 
RUN arduino-cli compile --fqbn arduino:avr:uno app

CMD ["arduino-cli", "upload", "-p", "/dev/ttyUSB1", "--fqbn", "arduino:avr:uno", "app"]
