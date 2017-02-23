#include "MainApp.h"
#include "SubApp.h"

#define PROGRAM_CHANGE_PIN 3
EmbeddedBaseApp* app;

int main()
{
    bool app_switch = digitalRead(PROGRAM_CHANGE_PIN);

    if (app_switch) app = (EmbeddedBaseApp*) new MainApp;
    else            app = (EmbeddedBaseApp*) new SubApp;

    app->setup();
    app->bootcheck();

    while(1)
    {
        app->receive();
        app->send();
        app->update();
        app->drive();
    }

    app->onFinish();
    delete app;
}
