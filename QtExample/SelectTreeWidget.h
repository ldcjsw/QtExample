#pragma once
#include <QTreeWidget>
#include "SelectStackedWidget.h"

class SelectTreeWidget : public QTreeWidget
{
	Q_OBJECT
public:
	explicit SelectTreeWidget(QTreeWidget *parent = nullptr, SelectStackedWidget *selectStackedWidget = nullptr);
	~SelectTreeWidget();

private:
	void initTreeItem();
	void initTreeStyle();
	void initSignalSlot();

private slots:
	void onTreeWidgetItemClicked(QTreeWidgetItem* item, int count);

private:
	QTreeWidgetItem *m_item1 = nullptr;
	QTreeWidgetItem *m_item2 = nullptr;
	QTreeWidgetItem *m_item3 = nullptr;
	QTreeWidgetItem *m_item31 = nullptr;
	QTreeWidgetItem *m_item32 = nullptr;
	QTreeWidgetItem *m_item4 = nullptr;
	QTreeWidgetItem *m_item5 = nullptr;

	SelectStackedWidget *m_selectStackedWidget = nullptr;
};

