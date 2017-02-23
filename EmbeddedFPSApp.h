#pragma once
#include <Arduino.h>
#include "EmbeddedBaseApp.h"
#include "FPSTimer.h"

class EmbeddedFPSApp : public EmbeddedBaseApp, public FPSTimer
{
public:
    // ctor
    EmbeddedFPSApp(size_t fps = 40)
    : FPSTimer(fps)
    { }
    // copy
    EmbeddedFPSApp(const EmbeddedFPSApp&) = default;
    EmbeddedFPSApp& operator= (const EmbeddedFPSApp&) = default;
    // move
    EmbeddedFPSApp(EmbeddedFPSApp&&) noexcept = default;
    EmbeddedFPSApp& operator = (EmbeddedFPSApp&&) noexcept = default;
    // dtor
    virtual ~EmbeddedFPSApp() noexcept = default;

    virtual void setup() = 0;
    virtual void bootcheck() = 0;
    virtual void receive() = 0;
    virtual void update() = 0;
    virtual void drive() = 0;
    virtual void send() = 0;
    virtual void onFinish() = 0;

    int32_t getGlobalFrame() { return getCurrentFrame(); }
    void setGlobalFrame(size_t frame) { setCurrentFrame(frame); }

};
