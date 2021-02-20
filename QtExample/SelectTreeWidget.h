#pragma once
#include <QTreeWidget>

class SelectTreeWidget : public QTreeWidget
{
	Q_OBJECT
public:
	explicit SelectTreeWidget(QTreeWidget *parent = nullptr);
	~SelectTreeWidget();

private:
	void initTreeItem();
	void initTreeStyle();

private:
	QTreeWidgetItem *m_item1 = nullptr;
	QTreeWidgetItem *m_item2 = nullptr;
	QTreeWidgetItem *m_item3 = nullptr;
	QTreeWidgetItem *m_item31 = nullptr;
	QTreeWidgetItem *m_item32 = nullptr;
};

