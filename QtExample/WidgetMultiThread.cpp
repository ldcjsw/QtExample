#include "WidgetMultiThread.h"

WidgetMultiThread::WidgetMultiThread(QWidget* parent) : QWidget(parent)
{
	m_hBoxLayout->addWidget(m_label);
	setLayout(m_hBoxLayout);
}

WidgetMultiThread::~WidgetMultiThread()
{

}