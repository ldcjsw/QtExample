#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QTableWidget>

struct TableStruct
{
	QString id;
	QString name;
	QString grade;
	QString class_;
	QString score;
};

class WidgetComponent : public QWidget
{
	Q_OBJECT
public:
	explicit WidgetComponent(QWidget* parent = nullptr);
	~WidgetComponent();

private:
	void initStyleSheet();
	void initLayOut();
	void initTableWidget();
	void setTableContent();

private slots:
	void onPushButtonClicked();
	void onItemEntered(QTableWidgetItem*);

private:
	QLineEdit* m_lineEdit = new QLineEdit;
	QComboBox* m_comboBox = new QComboBox;
	QPushButton* m_pushButton = new QPushButton;
	QLabel* m_label = new QLabel;
	QTableWidget* m_tableWidget = new QTableWidget;
	QHBoxLayout* m_hBoxLayout1 = new QHBoxLayout;
	QHBoxLayout* m_hBoxLayout2 = new QHBoxLayout;
	QVBoxLayout* m_vBoxLayoutAll = new QVBoxLayout;
};

