#pragma once
#include <QStackedWidget>
#include "SelectStackedWidget.h"
#include "WidgetComponent.h"

class SelectStackedWidget : public QStackedWidget
{
	Q_OBJECT
public:
	explicit SelectStackedWidget(QStackedWidget *parent = nullptr);
	~SelectStackedWidget();
	void initStackedWidget();

private:
	WidgetComponent* m_widgetComponent = new WidgetComponent;
};

