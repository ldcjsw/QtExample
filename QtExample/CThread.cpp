#include "CThread.h"
#include <QDebug>

CThread::CThread()
{

}

CThread::~CThread()
{

}

void CThread::SetThreadStatus(bool status)
{
	m_run = status;
}

void CThread::AddMeta(QString strMeta)
{
	QMutexLocker locker(&m_mutex);
	m_strVec.push_back(strMeta);
}

void CThread::run()
{
	int counter = 1;
	while (m_run)
	{
		QString tmpStr = -1;
		int vecSize = 0;
		{
			QMutexLocker locker(&m_mutex);
			vecSize = m_strVec.size();
			if (vecSize != 0)
			{
				tmpStr = m_strVec.front();
				m_strVec.pop_front();
			}
		}

		if (vecSize == 0)
		{
			QThread::sleep(1);
		}
		else
		{
			qDebug() << tmpStr << "size:" << vecSize;
			emit threadSignal(tmpStr);
		}
	}
}