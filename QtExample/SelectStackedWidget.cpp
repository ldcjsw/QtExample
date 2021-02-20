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
}