#include "Sqlite.h"
#include <windows.h>
#include <synchapi.h>

Sqlite::Sqlite(string strFileName)
{
	m_passwd = "Thinkit@2020";
    dbFileName = strFileName;
}
Sqlite::~Sqlite()
{
	sqlite3_close(m_sqlite);
}

bool Sqlite::Open(string& errMsg)
{
	int ret = sqlite3_open(dbFileName.c_str(), &m_sqlite);
	if (SQLITE_OK == ret)
	{
        //sqlite3_key(m_sqlite, m_passwd.c_str(), m_passwd.size());
        //string testSql = "SELECT count(*) FROM audioinfo";
        //if (Exec(testSql, errMsg) == false)
        //{
            //return false;
        //}

		return true;
	}

	errMsg = sqlite3_errmsg(m_sqlite);

	return false;
}


bool Sqlite::Exec(const string& sql, string& errMsg)
{
	char* cerrMsg = nullptr;
    //string utf8Sql = TransCode::Asci2Utf8(sql);
    int ret = sqlite3_exec(m_sqlite, sql.c_str(), 0, 0, &cerrMsg);
	if (SQLITE_OK == ret)
	{
		return true;
	}

	errMsg = cerrMsg;
	sqlite3_free(cerrMsg);

    int retryTimes = 0;
	while (retryTimes < 5 && errMsg == "database is locked")
	{
		Sleep(100 * (retryTimes + 1));
        int ret = sqlite3_exec(m_sqlite, sql.c_str(), 0, 0, &cerrMsg);
		if (SQLITE_OK == ret)
		{
			errMsg = " retryTimes: " + std::to_string(retryTimes + 1);
			return true;
		}
		errMsg = cerrMsg;
		sqlite3_free(cerrMsg);
		retryTimes++;
	}

	return false;
}

int Sqlite::select_cb(void* data, int cNum, char* column_values[], char* column_names[])
{
	SqliteSelectResult* selectResult = static_cast<SqliteSelectResult*>(data);
	map<string, string> record;
	for (int i = 0; i < cNum; i++)
	{
		if (column_values[i])
		{
            //record[column_names[i]] = TransCode::Utf82Asci(column_values[i]);
            record[column_names[i]] = column_values[i];
		}
		else
		{
			record[column_names[i]] = "NULL";
		}
	}
	selectResult->push_back(record);

	return 0;
}


bool Sqlite::Query(const string& sql, SqliteSelectResult& selectResult, string& errMsg)
{
	char* cerrMsg = nullptr;
    //string utf8Sql = TransCode::Asci2Utf8(sql);
    int ret = sqlite3_exec(m_sqlite, sql.c_str(), Sqlite::select_cb, (void*)&selectResult, &cerrMsg);
	if (SQLITE_OK == ret)
	{
		return true;
	}

	errMsg = cerrMsg;
	sqlite3_free(cerrMsg);

    int retryTimes = 0;
	while (retryTimes < 5 && errMsg == "database is locked")
	{
		Sleep(100 * (retryTimes + 1));
        int ret = sqlite3_exec(m_sqlite, sql.c_str(), Sqlite::select_cb, (void*)&selectResult, &cerrMsg);
		if (SQLITE_OK == ret)
		{
			errMsg = " retryTimes: " + std::to_string(retryTimes + 1);
			return true;
		}
		errMsg = cerrMsg;
		sqlite3_free(cerrMsg);
		retryTimes++;
	}

	return false;
}
