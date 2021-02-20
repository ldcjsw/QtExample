#pragma once
#include <QStackedWidget>
#include "SelectStackedWidget.h"
#include "WidgetComponent.h"
#include "WidgetMultiThread.h"
#include "WidgetNetWork.h"
#include "WidgetMultimedia.h"

class SelectStackedWidget : public QStackedWidget
{
	Q_OBJECT
public:
	explicit SelectStackedWidget(QStackedWidget *parent = nullptr);
	~SelectStackedWidget();
	void initStackedWidget();

private:
	WidgetComponent* m_widgetComponent = new WidgetComponent;
	WidgetMultiThread* m_widgetMultiThread = new WidgetMultiThread;
	WidgetNetWork* m_widgetNetWork = new WidgetNetWork;
	WidgetMultimedia* m_widgetMedia = new WidgetMultimedia;
};

