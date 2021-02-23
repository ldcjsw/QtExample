#include "WidgetMVC.h"

MVCModel::MVCModel()
{
	m_sqliteModel = new Sqlite("./sqlite.db");
}

MVCModel::~MVCModel()
{
	delete m_sqliteModel;
}

bool MVCModel::Connect()
{
	string errMsg;
	if (m_sqliteModel->Open(errMsg) == false)
	{
		return false;
	}

	return true;
}

QString MVCModel::GetValue()
{
	string errMsg;
	string sql = "select remark from sys_config where id = 1";
	SqliteSelectResult selectResult;
	if (m_sqliteModel->Query(sql, selectResult, errMsg) == false)
	{
		return "";
	}

	m_value = selectResult.front().at("remark").c_str();

	return m_value;

}

void MVCModel::SetValue(QString value)
{
	string errMsg;
	string sql = "update sys_config set remark = '" + value.toStdString() + "' where id = 1";
	SqliteSelectResult selectResult;
	if (m_sqliteModel->Exec(sql, errMsg) == false)
	{
		return;
	}

	m_value = value;
}

WidgetMVC::WidgetMVC(QWidget* parent) : QWidget(parent)
{
	m_model = new MVCModel;
	m_model->Connect();
	m_control = new MVCControl(m_model, this);

	m_control->UpdateView();

	m_pushButton->setText(QStringLiteral("¸Ä±äÖµ"));
	m_lineEdit->setFixedWidth(100);
	m_label->setFixedWidth(100);
	m_hBoxLayoutAll->addStretch(1);
	m_hBoxLayoutAll->addWidget(m_pushButton);
	m_hBoxLayoutAll->addWidget(m_lineEdit);
	m_hBoxLayoutAll->addWidget(m_label);
	m_hBoxLayoutAll->addStretch(1);
	setLayout(m_hBoxLayoutAll);
	connect(m_pushButton, SIGNAL(clicked()), this, SLOT(onChangeValue()));
}

WidgetMVC::~WidgetMVC()
{
	delete m_model;
	delete m_control;
}

void WidgetMVC::onChangeValue()
{
	m_control->SetValue(m_lineEdit->text());
	m_control->UpdateView();
}

void WidgetMVC::UpdateView(QString value)
{
	m_label->setText(value);
}

MVCControl::MVCControl(MVCModel* mvcModel, WidgetMVC* mvcView) : m_mvcModel(mvcModel), m_mvcView(mvcView)
{

}

void MVCControl::UpdateView()
{
	m_mvcView->UpdateView(m_mvcModel->GetValue());
}

void MVCControl::SetValue(QString value)
{
	m_mvcModel->SetValue(value);
}

QString MVCControl::GetValue()
{
	return m_mvcModel->GetValue();
}
