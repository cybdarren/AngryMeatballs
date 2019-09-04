/*
 * MainWindow.h
 *
 *  Created on: May 13, 2019
 *      Author: Microchip
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <egt/ui>
#include <random>
#include <vector>
#include <chrono>
#include <Box2D/Box2D.h>
#include <lab3/Ball.h>

using namespace egt;
using namespace std;

class MainWindow: public TopWindow
{
public:
	MainWindow();
	virtual ~MainWindow() = default;

	int handle(eventid event);
	void update();

protected:
	unique_ptr<b2World> m_world;
	vector<shared_ptr<Ball>> m_objects;

};

#endif /* MAINWINDOW_H_ */
