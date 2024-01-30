// GamePad.cpp
#include "GamePad.h"

GamePad::GamePad() : btSerial(2, 3){
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

void GamePad::begin(long baudRate) {
    btSerial.begin(baudRate);
}

void GamePad::processInput() {
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



bool GamePad::updateButtonStates(const char* data) {
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

bool GamePad::isUpPressed() const {
    return upState;
}

bool GamePad::isDownPressed() const {
    return downState;
}

bool GamePad::isLeftPressed() const {
    return leftState;
}

bool GamePad::isRightPressed() const {
    return rightState;
}

bool GamePad::isUpLeftPressed() const {
  return upLeftState;
}

bool GamePad::isUpRightPressed() const {
  return upRightState;
}

bool GamePad::isDownLeftPressed() const {
  return downLeftState;
}

bool GamePad::isDownRightPressed() const {
  return downRightState;
}

bool GamePad::isPlayPressed() const {
  return playState;
}

bool GamePad::isSelectPressed() const {
    return selectState;
}

bool GamePad::isStartPressed() const {
    return startState;
}

bool GamePad::isYPressed() const {
    return yState;
}

bool GamePad::isXPressed() const {
    return xState;
}

bool GamePad::isBPressed() const {
    return bState;
}

bool GamePad::isAPressed() const {
    return aState;
}



