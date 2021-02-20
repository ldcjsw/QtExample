#pragma once
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include "SelectTreeWidget.h"
#include "SelectStackedWidget.h"

class CentralWidget :public QWidget
{
	Q_OBJECT
public:
	explicit CentralWidget(QWidget* parent = Q_NULLPTR);
	~CentralWidget();

private:
	SelectTreeWidget* m_selectTreeWidget = new SelectTreeWidget;
	SelectStackedWidget* m_selectStackedWidget = new SelectStackedWidget;
	QHBoxLayout* m_hBoxLayoutAll = new QHBoxLayout;
};

