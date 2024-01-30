// GamePad.cpp
#include "GamePadESP32.h"

GamePadESP32::GamePadESP32() {
    upState = false;
    downState = false;
    leftState = false;
    rightState = false;
    upLeftState = false;
    upRightState = false;
    downLeftState = false;
    downRightState = false;

    playState = false;
    selectState = false;
    startState = false;
    yState = false;
    xState = false;
    bState = false;
    aState = false;
}

void GamePadESP32::begin(const char* deviceName) {
    btSerial.begin(deviceName); // Bluetooth device name
}

void GamePadESP32::processInput() {
    static char buffer[20]; // Buffer para acumular los datos
    static int bufferIndex = 0; // Índice para la posición actual en el buffer

    while (btSerial.available()) {
        char c = btSerial.read();
        if (bufferIndex < (sizeof(buffer) - 1)) {
            buffer[bufferIndex] = c;
            bufferIndex++;
        }
        if (c == ';') {
            buffer[bufferIndex] = '\0'; // Termina la cadena
            //Serial.println(buffer);
            if (updateButtonStates(buffer)) {
              btSerial.println("ACK"); 
            }
            bufferIndex = 0;
        }
    }
}



bool GamePadESP32::updateButtonStates(const char* data) {
    //Serial.println(strlen(data));
    if (strlen(data) != 16) {
        Serial.println("Error: Invalid message length");
        return false;
    }
    // Actualizar los estados de los botones según el formato recibido
    upState = data[0] == '1';
    downState = data[1] == '1';
    leftState = data[2] == '1';
    rightState = data[3] == '1';
    upLeftState = data[4] == '1';
    upRightState = data[5] == '1';
    downLeftState = data[6] == '1';
    downRightState = data[7] == '1';

    playState = data[8] == '1';
    selectState = data[9] == '1';
    startState = data[10] == '1';
    yState = data[11] == '1';
    xState = data[12] == '1';
    bState = data[13] == '1';
    aState = data[14] == '1';
    return true;
}

bool GamePadESP32::isUpPressed() const {
    return upState;
}

bool GamePadESP32::isDownPressed() const {
    return downState;
}

bool GamePadESP32::isLeftPressed() const {
    return leftState;
}

bool GamePadESP32::isRightPressed() const {
    return rightState;
}

bool GamePadESP32::isUpLeftPressed() const {
  return upLeftState;
}

bool GamePadESP32::isUpRightPressed() const {
  return upRightState;
}

bool GamePadESP32::isDownLeftPressed() const {
  return downLeftState;
}

bool GamePadESP32::isDownRightPressed() const {
  return downRightState;
}

bool GamePadESP32::isPlayPressed() const {
  return playState;
}

bool GamePadESP32::isSelectPressed() const {
    return selectState;
}

bool GamePadESP32::isStartPressed() const {
    return startState;
}

bool GamePadESP32::isYPressed() const {
    return yState;
}

bool GamePadESP32::isXPressed() const {
    return xState;
}

bool GamePadESP32::isBPressed() const {
    return bState;
}

bool GamePadESP32::isAPressed() const {
    return aState;
}


