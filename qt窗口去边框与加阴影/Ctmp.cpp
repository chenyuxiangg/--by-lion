#include "Ctmp.h"
#include <QGraphicsDropShadowEffect>

Ctmp::Ctmp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	
	QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect;
	shadow->setBlurRadius(30);
	shadow->setColor(Qt::black);
	shadow->setOffset(0);

	ui.shadow_widget->setGraphicsEffect(shadow);
}
