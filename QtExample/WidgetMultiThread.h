#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class WidgetMultiThread : public QWidget
{
	Q_OBJECT
public:
	WidgetMultiThread(QWidget* parent = nullptr);
	~WidgetMultiThread();

private:
	QLabel* m_label = new QLabel(QStringLiteral("���߳�"));
	QHBoxLayout* m_hBoxLayout = new QHBoxLayout;
};

