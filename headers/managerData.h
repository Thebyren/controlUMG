#ifndef managerData
#define managerData

#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <strings.h>


class SQLiteManager
{
    sqlite3 *db; // puntero a la base de datos
public:
    SQLiteManager(const char *dbname);
    ~SQLiteManager();
    // funciones
    bool openDataBase(const std::string &nombreDB);

    void closeDataBase();

    void querryDataBase(const std::string &texto);
    
};
#endif /* managerData */