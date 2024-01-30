// GamePad.h
#ifndef GamePadESP32_h
#define GamePadESP32_h

#include <Arduino.h>
#include <BluetoothSerial.h>

class GamePadESP32 {
public:
    GamePadESP32(); // Constructor
    void begin(const char* deviceName);
    void processInput();

    bool isUpPressed() const;
    bool isDownPressed() const;
    bool isLeftPressed() const;
    bool isRightPressed() const;
    bool isUpLeftPressed() const;
    bool isUpRightPressed() const;
    bool isDownLeftPressed() const;
    bool isDownRightPressed() const;
    
    bool isPlayPressed() const;
    bool isSelectPressed() const;
    bool isStartPressed() const;
    bool isYPressed() const;
    bool isXPressed() const;
    bool isBPressed() const;
    bool isAPressed() const;
private:
    BluetoothSerial btSerial; // Cambio a HardwareSerial
    bool upState, downState, leftState, rightState, upLeftState, upRightState, downLeftState, downRightState;
    bool playState, selectState, startState, yState, xState, bState, aState;

    bool updateButtonStates(const char* data);
};

#endif
