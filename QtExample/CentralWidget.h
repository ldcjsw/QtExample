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
	SelectStackedWidget* m_selectStackedWidget = new SelectStackedWidget;
	SelectTreeWidget* m_selectTreeWidget = new SelectTreeWidget(nullptr, m_selectStackedWidget);
	QHBoxLayout* m_hBoxLayoutAll = new QHBoxLayout;
};

