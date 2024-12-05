#ifndef STARTVIEW_HPP
#define STARTVIEW_HPP

#include <gui_generated/start_screen/startViewBase.hpp>
#include <gui/start_screen/startPresenter.hpp>
#include<touchgfx/containers/clock/AnalogClock.hpp>

class startView : public startViewBase
{
public:
    startView();
    virtual ~startView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    void handleTickEvent();

    int tickCounter;
    float lastTemperature;

};

#endif // STARTVIEW_HPP
