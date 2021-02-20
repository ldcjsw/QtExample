#pragma once

#include <QtWidgets/QMainWindow>
#include "CentralWidget.h"

class QtExample : public QMainWindow
{
    Q_OBJECT

public:
    QtExample(QWidget *parent = Q_NULLPTR);

private:
	CentralWidget* m_centralWidget = new CentralWidget;
};
