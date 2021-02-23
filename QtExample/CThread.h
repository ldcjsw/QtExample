#pragma once
#include <QThread>
#include <QMutex>
#include <QAtomicInteger>
#include <QVector>

class CThread : public QThread
{
	Q_OBJECT
public:
	CThread();
	~CThread();
	void SetThreadStatus(bool status);
	void AddMeta(QString);
protected:
	virtual void run();

signals:
	void threadSignal(QString string);

private:
	QMutex m_mutex;
	QAtomicInteger<bool> m_run = true;
	QVector<QString> m_strVec;
};

