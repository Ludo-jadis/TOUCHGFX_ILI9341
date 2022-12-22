#include <gui/screen2_screen/Screen2View.hpp>
#include <inttypes.h>

extern uint16_t volume;

Screen2View::Screen2View()
{
	

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}


void Screen2View::handleTickEvent()
{
	boxProgress1.setValue(volume);
	circleProgress1.setValue(volume);

}
