#include "QtExample.h"
#include <windows.h>

QtExample::QtExample(QWidget *parent) : QMainWindow(parent)
{
	initStatus();
	setCentralWidget(m_centralWidget);
}

void QtExample::initStatus()
{
	setWindowTitle((QStringLiteral("v0.0.1 Qt界面功能开发记录")));

	int fullWidth = GetSystemMetrics(SM_CXFULLSCREEN);//获取全屏宽度
	int fullHeight = GetSystemMetrics(SM_CYFULLSCREEN);//获取全屏高度

	int width = fullWidth > 1920 ? 1920 : fullWidth;
	int height = fullHeight > 1080 ? 1080 : fullHeight;

	setMinimumSize(width, height);
	move((fullWidth - width) / 2, (fullHeight - height) / 2);
}