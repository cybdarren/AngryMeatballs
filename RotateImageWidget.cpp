/*
 * RotateImageWidget.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Microchip
 */

#include <Box2D/Box2D.h>
#include <cairo.h>
#include <egt/ui>
#include <lab3/RotateImageWidget.h>

RotateImageWidget::RotateImageWidget() :
	m_shapeSize(0, 0), m_drawBox(false)
{
	set_theme(theme());
	m_image = nullptr;
}

void RotateImageWidget::set_image(cairo_surface_t *image)
{
	// set the image
	m_image = image;

	// update the size
	m_shapeSize.w = cairo_image_surface_get_width(m_image);
	m_shapeSize.h = cairo_image_surface_get_height(m_image);
}

void RotateImageWidget::set_angle(double angle)
{
	if (detail::change_if_diff<>(m_angle, angle))
	{
		damage();
	}
}

void RotateImageWidget::draw(Painter& painter, const Rect&)
{
	auto cr = painter.context().get();

	Point drawPoint1(center());
	drawPoint1.x -= m_shapeSize.w / 2;
	drawPoint1.y -= m_shapeSize.h / 2;
	Point drawPoint2(center());
	drawPoint2.x += m_shapeSize.w / 2;
	drawPoint2.y += m_shapeSize.h / 2;

	// draw the rotate image
	cairo_save(cr);

	cairo_translate(cr, center().x, center().y);
	cairo_rotate(cr, m_angle);
	cairo_set_source_surface(cr, m_image, -(m_shapeSize.w / 2), -(m_shapeSize.h / 2));
	cairo_paint(cr);

	cairo_restore(cr);

	if (m_drawBox)
	{
		// Draw a bounding box to help identify issues
		cairo_save(cr);
		cairo_translate(cr, center().x, center().y);
		cairo_rotate(cr, m_angle);

		Rect drawbox(Point(), m_shapeSize);
		drawbox.x -= m_shapeSize.w / 2;
		drawbox.y -= m_shapeSize.h / 2;
		drawbox.shrink_around_center(4);
		//drawbox.move_to_center(center());

		theme().draw_border_box(painter, drawbox, Color(128, 128, 128));

		cairo_restore(cr);
	}
}

