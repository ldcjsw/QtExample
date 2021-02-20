#include "CentralWidget.h"
#include <QFont>

CentralWidget::CentralWidget(QWidget* parent)
{
	m_hBoxLayoutAll->addWidget(m_selectTreeWidget);
	m_hBoxLayoutAll->addWidget(m_selectStackedWidget);
	setLayout(m_hBoxLayoutAll);
}

CentralWidget::~CentralWidget()
{

}