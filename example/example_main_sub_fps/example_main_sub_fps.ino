#include "MainApp.h"
#include "SubApp.h"

#define PROGRAM_CHANGE_PIN 3
#define APP_FRAME_RATE 40
EmbeddedFPSApp* app;

int main()
{
    bool app_switch = digitalRead(PROGRAM_CHANGE_PIN);

    if (app_switch) app = (EmbeddedFPSApp*) new MainApp;
    else            app = (EmbeddedFPSApp*) new SubApp;

    app->setFrameRate(APP_FRAME_RATE);
    app->setup();
    app->bootcheck();
    app->start();

    while(1)
    {
        app->receive();
        app->send();
        while (app->needsUpdate())
        {
            app->update();
            app->setUpdated();
        }
        app->drive();
        if (app->isFinished()) break;
    }
    app->stop();
    app->onFinish();
    delete app;
}
