// GamePad.h
#ifndef GamePad_h
#define GamePad_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class GamePad {
public:
    GamePad();
    void begin(long baudRate);
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
    SoftwareSerial btSerial;
    bool upState, downState, leftState, rightState, upLeftState, upRightState, downLeftState, downRightState;
    bool playState, selectState, startState, yState, xState, bState, aState;

    bool updateButtonStates(const char* data);
};

#endif
