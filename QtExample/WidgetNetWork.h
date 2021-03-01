#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QTextCodec>
#include <QTextBrowser>
#include <QTextEdit>

class WidgetNetWork : public QWidget
{
	Q_OBJECT
public:
	explicit WidgetNetWork(QWidget* parent = nullptr);
	~WidgetNetWork();

private slots:
	void onPushButtonClicked();
	void replyFinished(QNetworkReply*);

private:
	QLabel* m_label = new QLabel(QStringLiteral("ÍøÂç"));
	QPushButton* m_pushButton = new QPushButton;
	QHBoxLayout* m_hBoxLayout = new QHBoxLayout;
	//QTextBrowser* m_textBrowser = new QTextBrowser;
	QTextEdit* m_textEdit = new QTextEdit;

private:
	QNetworkAccessManager *m_NetworkNanager;
};

