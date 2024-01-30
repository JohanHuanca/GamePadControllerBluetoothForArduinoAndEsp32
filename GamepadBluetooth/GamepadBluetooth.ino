#include "GamePad.h"

GamePad gamePad; // Ajusta los pines según tu hardware

void setup() {
  Serial.begin(9600);
  gamePad.begin(9600); 
}

void loop() {
  gamePad.processInput();
  
  if (gamePad.isUpPressed()) {
    Serial.println("Up");
  }

  if (gamePad.isDownPressed()) {
    Serial.println("Down");
  }

  if (gamePad.isLeftPressed()) {
    Serial.println("Left");
  }

  if (gamePad.isRightPressed()) {
    Serial.println("Right");
  }

  if (gamePad.isUpLeftPressed()) {
    Serial.println("Up Left");
  }

  if (gamePad.isUpRightPressed()) {
    Serial.println("Up Right");
  }

  if (gamePad.isDownLeftPressed()) {
    Serial.println("Down Left");
  }

  if (gamePad.isDownRightPressed()) {
    Serial.println("Down Right");
  }

  if (gamePad.isPlayPressed()) {
    Serial.println("Play");
  }

  if (gamePad.isStartPressed()) {
    Serial.println("Start");
  }

  if (gamePad.isSelectPressed()) {
    Serial.println("Select");
  }

  if (gamePad.isYPressed()) {
    Serial.println("Y");
  }

  if (gamePad.isXPressed()) {
    Serial.println("X");
  }

  if (gamePad.isBPressed()) {
    Serial.println("B");
  }

  if (gamePad.isAPressed()) {
    Serial.println("A");
  }

  delay(100);
}
