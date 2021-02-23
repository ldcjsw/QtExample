#include "SelectTreeWidget.h"

SelectTreeWidget::SelectTreeWidget(QTreeWidget *parent, SelectStackedWidget *selectStackedWidget)
	: QTreeWidget(parent), m_selectStackedWidget(selectStackedWidget)
{
	initTreeItem();
	initTreeStyle();
	initSignalSlot();
}

SelectTreeWidget::~SelectTreeWidget()
{

}

void SelectTreeWidget::initTreeItem()
{
	setColumnCount(1);
	setHeaderHidden(true);
	m_item1 = new QTreeWidgetItem(this, QStringList(QString(QStringLiteral("�����ؼ�style"))));
	m_item2 = new QTreeWidgetItem(this, QStringList(QString(QStringLiteral("���߳�"))));
	m_item3 = new QTreeWidgetItem(this, QStringList(QString(QStringLiteral("����"))));
	m_item31 = new QTreeWidgetItem(m_item3, QStringList(QString(QStringLiteral("������"))));
	m_item32 = new QTreeWidgetItem(m_item3, QStringList(QString(QStringLiteral("�ͻ���"))));
	m_item4 = new QTreeWidgetItem(this, QStringList(QString(QStringLiteral("��ý��"))));
	m_item5 = new QTreeWidgetItem(this, QStringList(QString(QStringLiteral("MVC"))));
}

void SelectTreeWidget::initTreeStyle()
{
	setFixedWidth(150);
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	expandAll();
}

void SelectTreeWidget::initSignalSlot()
{
	connect(this, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(onTreeWidgetItemClicked(QTreeWidgetItem*, int)));
}

void SelectTreeWidget::onTreeWidgetItemClicked(QTreeWidgetItem* item, int count)
{
	if (item->text(count) == QStringLiteral("�����ؼ�style"))
	{
		m_selectStackedWidget->setCurrentIndex(0);
	}else if (item->text(count) == QStringLiteral("���߳�"))
	{
		m_selectStackedWidget->setCurrentIndex(1);
	}
	else if (item->text(count) == QStringLiteral("����"))
	{
		m_selectStackedWidget->setCurrentIndex(2);
	}
	else if (item->text(count) == QStringLiteral("��ý��"))
	{
		m_selectStackedWidget->setCurrentIndex(3);
	}else if (item->text(count) == QStringLiteral("MVC"))
	{
		m_selectStackedWidget->setCurrentIndex(4);
	}
}
