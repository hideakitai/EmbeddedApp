#pragma once

class EmbeddedBaseApp
{
public:
    // ctor
    EmbeddedBaseApp() = default;
    // copy
    EmbeddedBaseApp(const EmbeddedBaseApp&) = default;
    EmbeddedBaseApp& operator= (const EmbeddedBaseApp&) = default;
    // move
    EmbeddedBaseApp(EmbeddedBaseApp&&) noexcept = default;
    EmbeddedBaseApp& operator = (EmbeddedBaseApp&&) noexcept = default;
    // dtor
    virtual ~EmbeddedBaseApp() noexcept = default;

    virtual void setup() = 0;
    virtual void bootcheck() = 0;
    virtual void receive() = 0;
    virtual void update() = 0;
    virtual void drive() = 0;
    virtual void send() = 0;
    virtual void onFinish() = 0;
};
