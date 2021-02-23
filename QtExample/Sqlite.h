#pragma once
#define SQLITE_HAS_CODEC
#include "sqlite3.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;

using std::string;
using std::cout;
using std::endl;

typedef vector<map<string, string>> SqliteSelectResult;

class Sqlite
{
public:
    Sqlite(string strFileName);
	~Sqlite();

    bool Open(string& errMsg);
	bool Exec(const string& sql, string& errMsg);
    bool Query(const string& sql, SqliteSelectResult& selectResult, string& errMsg);
    bool Close()
    {
        sqlite3_close(m_sqlite);
        return false;
    }
	static int select_cb(void* data, int cNum, char* column_values[], char* column_names[]);
private:
	sqlite3* m_sqlite;
	string m_passwd;
    string dbFileName;
};

