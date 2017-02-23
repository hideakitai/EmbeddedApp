#include "App.h"

App app;

int main()
{
    app.setup();
    app.bootcheck();

    while(1)
    {
        app.receive();
        app.send();
        app.update();
        app.drive();
    }

    app.onFinish();
}
