#include "CentralWidget.h"
#include <QFont>

CentralWidget::CentralWidget(QWidget* parent)
{
	initStyleSheet();
	initLayOut();
}

CentralWidget::~CentralWidget()
{

}

void CentralWidget::initStyleSheet()
{
	QFont font;
	font.setPixelSize(20);
	font.setFamily("ËÎÌå");

	m_pushButton->setText("123456");
	m_pushButton->setStyleSheet("QPushButton{color:red;background-color:blue}QPushButton:hover{color:white;background-color:black}QPushButton:enabled{color:red}");
	m_pushButton->setFont(font);

	m_comboBox->addItem(QStringLiteral("Ã¨Ã¨"));
	m_comboBox->addItem(QStringLiteral("¹·¹·"));
	m_comboBox->setStyleSheet("QComboBox{color:red;background-color:blue}QComboBox:hover{color:white;background-color:black}");
	m_comboBox->setFont(font);

	m_label->setText(QStringLiteral("123abc¼×ÒÒ±û"));
	m_label->setStyleSheet("QLabel{font-family:'ËÎÌå';font-size:30px;color:orange;background-color:green}""QLabel:hover{color:red}");
}

void CentralWidget::initLayOut()
{
	m_hBoxLayout->addWidget(m_pushButton);
	m_hBoxLayout->addWidget(m_lineEdit);
	m_hBoxLayout->addWidget(m_comboBox);
	m_hBoxLayout->addWidget(m_label);
	setLayout(m_hBoxLayout);
}

void CentralWidget::onPushButtonClicked()
{
	m_pushButton->setText("7890");
	//m_pushButton->setEnabled(false);
}