#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
class WidgetMultimedia : public QWidget
{
public:
	explicit WidgetMultimedia(QWidget* parent = nullptr);
	~WidgetMultimedia();

private:
	QLabel* m_label = new QLabel(QStringLiteral("��ý��"));
	QHBoxLayout* m_hBoxLayout = new QHBoxLayout;
};

