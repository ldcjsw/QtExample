#include "WidgetMultiThread.h"

WidgetMultiThread::WidgetMultiThread(QWidget* parent) : QWidget(parent)
{
	m_Thread = new CThread;
	connect(m_Thread, SIGNAL(threadSignal(QString)), this, SLOT(onThreadSignal(QString)));
	connect(m_pushButton, SIGNAL(clicked()), this, SLOT(onPushButtonClicked()));
	m_hBoxLayout->addStretch(1);
	m_hBoxLayout->addWidget(m_pushButton);
	m_hBoxLayout->addWidget(m_lineEdit);
	m_hBoxLayout->addWidget(m_label);
	m_hBoxLayout->addStretch(1);
	setLayout(m_hBoxLayout);
	m_Thread->start();
}

WidgetMultiThread::~WidgetMultiThread()
{
	m_Thread->SetThreadStatus(false);
	m_Thread->wait();
	delete m_Thread;
}

void WidgetMultiThread::onThreadSignal(QString signalInfo)
{
	m_label->setText(signalInfo);
}

void WidgetMultiThread::onPushButtonClicked()
{
	QString lineStr = m_lineEdit->text();
	for (int i = 0; i < 100000; i++)
	{
		m_Thread->AddMeta(lineStr + QString::number(i));
	}
}
