#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include "CThread.h"

class WidgetMultiThread : public QWidget
{
	Q_OBJECT
public:
	WidgetMultiThread(QWidget* parent = nullptr);
	~WidgetMultiThread();

private slots:
	void onThreadSignal(QString);
	void onPushButtonClicked();

private:
	QLabel* m_label = new QLabel(QStringLiteral("∂‡œﬂ≥Ã"));
	QLineEdit* m_lineEdit = new QLineEdit;
	QPushButton* m_pushButton = new QPushButton;
	QHBoxLayout* m_hBoxLayout = new QHBoxLayout;
	CThread* m_Thread = nullptr;
};

