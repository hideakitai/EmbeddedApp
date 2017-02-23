#include "App.h"

#define APP_FRAME_RATE 40
App app;

int main()
{
    app.setFrameRate(APP_FRAME_RATE);
    app.setup();
    app.bootcheck();
    app.start();

    while(1)
    {
        app.receive();
        app.send();
        while (app.needsUpdate())
        {
            app.update();
            app.setUpdated();
        }
        app.drive();
        if (app.isFinished()) break;
    }

    app.stop();
    app.onFinish();
}
