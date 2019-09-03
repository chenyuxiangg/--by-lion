#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Ctmp.h"

class Ctmp : public QMainWindow
{
	Q_OBJECT

public:
	Ctmp(QWidget *parent = Q_NULLPTR);

private:
	Ui::CtmpClass ui;
};
