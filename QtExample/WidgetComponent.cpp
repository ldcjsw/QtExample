#include "WidgetComponent.h"
#include <QHeaderView>

WidgetComponent::WidgetComponent(QWidget* parent) : QWidget(parent)
{
	initTableWidget();
	initStyleSheet();
	initLayOut();
}

WidgetComponent::~WidgetComponent()
{

}

void WidgetComponent::initStyleSheet()
{
	QFont font;
	font.setPixelSize(20);
	font.setFamily("����");

	m_pushButton->setText("123456");
	m_pushButton->setStyleSheet("QPushButton{color:red;background-color:blue}QPushButton:hover{color:white;background-color:black}QPushButton:enabled{color:red}");
	m_pushButton->setFont(font);
	connect(m_pushButton, SIGNAL(clicked()), this, SLOT(onPushButtonClicked()));

	m_comboBox->addItem(QStringLiteral("èè"));
	m_comboBox->addItem(QStringLiteral("����"));
	m_comboBox->setStyleSheet("QComboBox{color:red;background-color:blue}QComboBox:hover{color:white;background-color:black}");
	m_comboBox->setFont(font);

	m_label->setText(QStringLiteral("123abc���ұ�"));
	m_label->setStyleSheet("QLabel{font-family:'����';font-size:30px;color:orange;background-color:green}""QLabel:hover{color:red}");

	setAttribute(Qt::WA_StyledBackground);
	if (objectName().isEmpty())
	{
		setObjectName("WidgetComponent");
	}
	setStyleSheet("QWidget#WidgetComponent{background-color:green}");
}

void WidgetComponent::initLayOut()
{
	m_hBoxLayout1->addWidget(m_pushButton);
	m_hBoxLayout1->addWidget(m_lineEdit);
	m_hBoxLayout1->addWidget(m_comboBox);
	m_hBoxLayout1->addWidget(m_label);
	m_hBoxLayout1->addStretch(1);

	m_hBoxLayout2->addWidget(m_tableWidget);
	m_hBoxLayout2->addStretch(1);

	m_vBoxLayoutAll->addLayout(m_hBoxLayout1);
	m_vBoxLayoutAll->addLayout(m_hBoxLayout2);
	m_vBoxLayoutAll->addStretch(1);

	setLayout(m_vBoxLayoutAll);
}

void WidgetComponent::initTableWidget()
{
	m_tableWidget->setColumnCount(5);
	/*m_tableWidget->setStyleSheet("QTableWidget{border-image:url(:/res/WidgetComponent/tableBG.png);}"
		"QTableWidget::Item{border:0px solid rgb(69, 145, 229);"
		"border-bottom:1px solid rgb(69, 145, 229);}");*/
	m_tableWidget->setStyleSheet("QTableWidget{border:none;gridline-color:rgb(83,104,137);selection-background-color:rgb(30,144,255);border-image:url(:/res/WidgetComponent/tableBG.png);}"//����ͼƬ
		"QTableWidget::Item{padding-bottom:10px;}");
	QHeaderView *vHeader = m_tableWidget->verticalHeader();
	//�����к�
	vHeader->setHidden(true);
	QHeaderView *hHeader = m_tableWidget->horizontalHeader();
	//���ò����Ե����пռ��С
	//hHeader->setSectionResizeMode(QHeaderView::Fixed);
	hHeader->setStretchLastSection(true);//���һ����������
	//����ʾĬ��������
	//m_QTableWidget->setShowGrid(false);
	m_tableWidget->setFocusPolicy(Qt::NoFocus);
	//���ò��ɱ༭
	m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	m_tableWidget->setMouseTracking(true);
	connect(m_tableWidget, SIGNAL(itemEntered(QTableWidgetItem*)), this, SLOT(onItemEntered(QTableWidgetItem*)));

	//m_tableWidget->setWindowFlags(Qt::FramelessWindowHint);
	//m_tableWidget->verticalHeader()->setHidden(true);
	//m_tableWidget->horizontalHeader()->setHidden(true);
	//m_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	//m_tableWidget->horizontalHeader()->setStretchLastSection(true);
	//m_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	////m_tableWidget->setShowGrid(false);
	//m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//m_tableWidget->setFocusPolicy(Qt::NoFocus);
	//m_tableWidget->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
	m_tableWidget->setFixedSize(192 * 4, 108 * 3);

	setTableContent();
}

void WidgetComponent::setTableContent()
{
	m_tableWidget->setRowCount(0);
	m_tableWidget->clearContents();

	auto pSetItem = [&](QString str, int rowCount, int index)
	{
		QTableWidgetItem *item = new QTableWidgetItem(str);
		item->setForeground(QBrush(QColor(255, 255, 255)));
		item->setTextAlignment(Qt::AlignCenter);

		m_tableWidget->setItem(rowCount, index, item);
	};

	m_tableWidget->insertRow(0);
	pSetItem(QStringLiteral("ID"), 0, 0);
	pSetItem(QStringLiteral("�ͺ�"), 0, 1);
	pSetItem(QStringLiteral("��λ"), 0, 2);
	pSetItem(QStringLiteral("����(����)"), 0, 3);
	pSetItem(QStringLiteral("���Ŷ�"), 0, 4);

	for (size_t rowCount = 0; rowCount < 4; rowCount++)
	{
		m_tableWidget->insertRow(rowCount + 1);
		pSetItem(QString::number(rowCount), rowCount + 1, 0);
		pSetItem(QString::number(rowCount * 2), rowCount + 1, 1);
		pSetItem(QString::number(rowCount * 3), rowCount + 1, 2);
		pSetItem(QString::number(rowCount * 4), rowCount + 1, 3);
		pSetItem(QString::number(rowCount * 5), rowCount + 1, 4);
	}
}

void WidgetComponent::onPushButtonClicked()
{
	m_pushButton->setText("7890");
}

void WidgetComponent::onItemEntered(QTableWidgetItem* enteredItem)
{
	int clickedLineNums = enteredItem->row();
	int rowLineNums = m_tableWidget->rowCount();
	int columnLineNums = m_tableWidget->columnCount();
	for (int i = 0; i < rowLineNums; i++)
	{
		if (i == clickedLineNums)
		{
			for (int j = 0; j < columnLineNums; j++)
			{
				m_tableWidget->item(i, j)->setBackground(Qt::black);
			}
		}
		else
		{
			for (int j = 0; j < columnLineNums; j++)
			{
				m_tableWidget->item(i, j)->setBackground(QColor(0, 0, 0, 0));
			}
		}
	}
}