#pragma once
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include "Sqlite.h"

class MVCControl;
class MVCModel;

class MVCModel
{
public:
	MVCModel();
	~MVCModel();

public:
	bool Connect();
	QString GetValue();
	void SetValue(QString value);

private:
	Sqlite* m_sqliteModel = nullptr;
	QString m_value;
};


class WidgetMVC : public QWidget
{
	Q_OBJECT
public:
	explicit WidgetMVC(QWidget* parent = nullptr);
	~WidgetMVC();
	void UpdateView(QString value);

private slots:
	void onChangeValue();

private:
	QLabel* m_label = new QLabel(QStringLiteral("123"));
	QLineEdit* m_lineEdit = new QLineEdit;
	QPushButton* m_pushButton = new QPushButton;
	QHBoxLayout* m_hBoxLayoutAll = new QHBoxLayout;
	MVCControl* m_control = nullptr;
	MVCModel* m_model = nullptr;
};

class MVCControl
{
public:
	MVCControl(MVCModel* mvcModel, WidgetMVC* mvcView);

	void UpdateView();
	void SetValue(QString value);
	QString GetValue();

private:
	MVCModel* m_mvcModel = nullptr;
	WidgetMVC* m_mvcView = nullptr;
};