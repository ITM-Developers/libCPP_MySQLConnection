#include <iostream>
#include "MySQLConnection.h"

using namespace std;

int main()
{
    /* // Conexion MySQL
      ____                      _             __  __       ____   ___  _
     / ___|___  _ __   _____  _(_) ___  _ __ |  \/  |_   _/ ___| / _ \| |
    | |   / _ \| '_ \ / _ \ \/ / |/ _ \| '_ \| |\/| | | | \___ \| | | | |
    | |__| (_) | | | |  __/>  <| | (_) | | | | |  | | |_| |___) | |_| | |___
     \____\___/|_| |_|\___/_/\_\_|\___/|_| |_|_|  |_|\__, |____/ \__\_\_____|
                                                     |___/
    */
    MySQLConnection mysql;
    sql::ResultSet  *resultSet;
    string sql = "SELECT * FROM users";
    mysql.setDATABASE("itm_matematicas");
    mysql.setUSERNAME("itm_matematicas");
    mysql.setPASSWORD("paramore1196");
    mysql.setIP_SERVER("127.0.0.1");
    mysql.connectServer();

    resultSet = mysql.executeQuery( sql );
    cout << "ID\t" << "Name" << endl;
    while (resultSet->next()) {
      cout << resultSet->getInt(1) << "\t" << resultSet->getString("name") << endl;
    }
    delete resultSet;

    return 0;
}
