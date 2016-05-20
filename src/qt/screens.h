// GB Enhanced+ Copyright Daniel Baxter 2015
// Licensed under the GPLv2
// See LICENSE.txt for full license text

// File : screens.h
// Date : February 29, 2015
// Description : Software and OpenGL rendering widgets
//
// Widgets for rendering via software, or OpenGL for HW acceleration

#ifndef SCREENS_GBE_QT
#define SCREENS_GBE_QT

#include <QtGui>
#include <QGLWidget>

#include "common/common.h"

class soft_screen : public QWidget
{
	Q_OBJECT
	
	public:
	soft_screen(QWidget *parent = 0);

	u32 resize_wait;
	u32 last_width;
	u32 last_height;

	protected:
	void paintEvent(QPaintEvent* event);
};

class hard_screen : public QGLWidget
{
	Q_OBJECT
	
	public:
	hard_screen(QWidget *parent = 0);
	GLuint lcd_texture;

	u32 resize_wait;
	u32 last_width;
	u32 last_height;

	protected:
	void initializeGL();
	void paintGL();
};

#endif //SCREENS_GBE_QT 
