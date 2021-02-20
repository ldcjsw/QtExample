#pragma once
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>

class CentralWidget :public QWidget
{
public:
	CentralWidget(QWidget* parent = Q_NULLPTR);
	~CentralWidget();

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

