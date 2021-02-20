#include "SelectTreeWidget.h"

SelectTreeWidget::SelectTreeWidget(QTreeWidget *parent) : QTreeWidget(parent)
{
	initTreeItem();
	initTreeStyle();
}

SelectTreeWidget::~SelectTreeWidget()
{

}

void SelectTreeWidget::initTreeItem()
{
	setColumnCount(1);
	setHeaderHidden(true);
	m_item1 = new QTreeWidgetItem(this, QStringList(QString(QStringLiteral("基础控件style"))));
	m_item2 = new QTreeWidgetItem(this, QStringList(QString(QStringLiteral("多线程"))));
	m_item3 = new QTreeWidgetItem(this, QStringList(QString(QStringLiteral("网络"))));
	m_item31 = new QTreeWidgetItem(m_item3, QStringList(QString(QStringLiteral("服务器"))));
	m_item32 = new QTreeWidgetItem(m_item3, QStringList(QString(QStringLiteral("客户端"))));
	m_item3->addChild(m_item31);
	m_item3->addChild(m_item32);
}

void SelectTreeWidget::initTreeStyle()
{
	setFixedWidth(150);
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	expandAll();
}