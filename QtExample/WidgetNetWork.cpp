#include "WidgetNetWork.h"

WidgetNetWork::WidgetNetWork(QWidget* parent) : QWidget(parent)
{
	m_hBoxLayout->addStretch(1);
	m_hBoxLayout->addWidget(m_pushButton);
	m_hBoxLayout->addWidget(m_label);
	m_hBoxLayout->addWidget(m_textEdit);
	m_hBoxLayout->addStretch(1);
	m_textEdit->setFixedSize(100, 100);
	setLayout(m_hBoxLayout);
	connect(m_pushButton, SIGNAL(clicked()), this, SLOT(onPushButtonClicked()));

	m_NetworkNanager = new QNetworkAccessManager(this);
	connect(m_NetworkNanager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

WidgetNetWork::~WidgetNetWork()
{

}

void WidgetNetWork::onPushButtonClicked()
{
	//m_label->setText(QStringLiteral("¹þ¹þ¹þ"));
	m_NetworkNanager->get(QNetworkRequest(QUrl("https://www.baidu.com")));
}


void WidgetNetWork::replyFinished(QNetworkReply* reply)
{
	//QTextCodec *codec = QTextCodec::codecForLocale();
	//QString all = codec->toUnicode(reply->readAll().toStdString());
	QString all = QString::fromStdString(reply->readAll().toStdString());
	qDebug() << all;
	//qDebug() << reply->readAll();
	//m_label->setText(all);
	m_textEdit->setText("123" + all + "456");
	reply->deleteLater();

}