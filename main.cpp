/*
 * RotateImageWidget.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Microchip
 */

#include <egt/ui>
#include "MainWindow.h"

using namespace egt;

int main(int argc, const char **argv) {
	Application app(argc, argv);

	MainWindow win;
	win.show();

	PeriodicTimer animatetimer(std::chrono::milliseconds(30));
	animatetimer.on_timeout([&win]()
	{
		win.update();
	});
	animatetimer.start();

	return app.run();
}

