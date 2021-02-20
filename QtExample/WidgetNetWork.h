#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class WidgetNetWork : public QWidget
{
	Q_OBJECT
public:
	explicit WidgetNetWork(QWidget* parent = nullptr);
	~WidgetNetWork();

private:
	QLabel* m_label = new QLabel(QStringLiteral("ÍøÂç"));
	QHBoxLayout* m_hBoxLayout = new QHBoxLayout;
};

