#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>

class WidgetComponent : public QWidget
{
	Q_OBJECT
public:
	explicit WidgetComponent(QWidget* parent = nullptr);
	~WidgetComponent();

private:
	void initStyleSheet();
	void initLayOut();

private slots:
	void onPushButtonClicked();

private:
	QLineEdit* m_lineEdit = new QLineEdit;
	QComboBox* m_comboBox = new QComboBox;
	QPushButton* m_pushButton = new QPushButton;
	QLabel* m_label = new QLabel;
	QHBoxLayout* m_hBoxLayout = new QHBoxLayout;
};

