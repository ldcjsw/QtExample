#include "SelectStackedWidget.h"

SelectStackedWidget::SelectStackedWidget(QStackedWidget *parent)
{
	initStackedWidget();
}

SelectStackedWidget::~SelectStackedWidget()
{

}

void SelectStackedWidget::initStackedWidget()
{
	addWidget(m_widgetComponent);
	addWidget(m_widgetMultiThread);
	addWidget(m_widgetNetWork);
	addWidget(m_widgetMedia);
}