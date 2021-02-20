#include "WidgetMultimedia.h"

WidgetMultimedia::WidgetMultimedia(QWidget* parent) : QWidget(parent)
{
	m_hBoxLayout->addWidget(m_label);
	setLayout(m_hBoxLayout);
}

WidgetMultimedia::~WidgetMultimedia()
{

}