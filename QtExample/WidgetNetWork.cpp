#include "WidgetNetWork.h"

WidgetNetWork::WidgetNetWork(QWidget* parent) : QWidget(parent)
{
	m_hBoxLayout->addWidget(m_label);
	setLayout(m_hBoxLayout);
}

WidgetNetWork::~WidgetNetWork()
{

}