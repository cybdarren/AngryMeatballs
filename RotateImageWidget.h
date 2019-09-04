/*
 * RotateImageWidget.h
 *
 *  Created on: May 15, 2019
 *      Author: Microchip
 */

#ifndef ROTATEIMAGEWIDGET_H_
#define ROTATEIMAGEWIDGET_H_

#include <Box2D/Box2D.h>
#include <egt/ui>
#include <cairo.h>

using namespace egt;
using namespace std;

inline double to_meter(double x)
{
	return x * 0.01;
}

inline double from_meter(double x)
{
	return x * 100.0;
}

class RotateImageWidget: public Widget
{
public:
	explicit RotateImageWidget();

	void set_angle(double angle);
	void set_image(cairo_surface_t *image);
	void set_drawBoundingBox(bool bDraw) { m_drawBox = bDraw; }
	virtual void draw(Painter& painter, const Rect&) override;

protected:
	cairo_surface_t *m_image;
	double m_angle{0.0};
	Size m_shapeSize;
	bool m_drawBox;
};

#endif /* ROTATEIMAGEWIDGET_H_ */
