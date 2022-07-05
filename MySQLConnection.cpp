#include "MySQLConnection.h"

MySQLConnection::MySQLConnection()
{
    //Default Port and Protocol
    this->PORT  = "3306";
    this->PROTO = "tcp";
    this->IP_SERVER = "127.0.0.1";
}

string MySQLConnection::getIP_SERVER() const{ return IP_SERVER;   }
string MySQLConnection::getDATABASE()  const{ return DATABASE;    }

void MySQLConnection::setIP_SERVER(const string &value){ IP_SERVER = value; }

void MySQLConnection::setDATABASE(const string &value)
{
    DATABASE = value;
}

string MySQLConnection::getPASSWORD() const
{
    return PASSWORD;
}

void MySQLConnection::setPASSWORD(const string &value)
{
    PASSWORD = value;
}

string MySQLConnection::getUSERNAME() const
{
    return USERNAME;
}

void MySQLConnection::setUSERNAME(const string &value)
{
    USERNAME = value;
}

string MySQLConnection::getPROTO() const
{
    return PROTO;
}

void MySQLConnection::setPROTO(const string &value)
{
    PROTO = value;
}

string MySQLConnection::getPORT() const
{
    return PORT;
}

void MySQLConnection::setPORT(const string &value)
{
    PORT = value;
}

int MySQLConnection::connectServer()
{
    try {
        this->driver = get_driver_instance();
        this->connection = this->driver->connect( PROTO+"://"+IP_SERVER+":"+PORT, this->USERNAME, this->PASSWORD );

        //Seleccion de la DB
        connection->setSchema(this->DATABASE);

        //Parte del consulta
        this->stmt = this->connection->createStatement();

    } catch (sql::SQLException &e) {
        cout << "ERROR: " << e.what() << endl;
        cout << "MySQL error code: " << e.getErrorCode() << endl;
        cout << "SQLState: " << e.getSQLState() << endl;
    }
    return EXIT_SUCCESS;
}

sql::ResultSet* MySQLConnection::executeQuery(const string &value)
{
    return this->resultset = this->stmt->executeQuery(value);
}

void MySQLConnection::executeCommand(const string &value){
    this->stmt->execute(value);
}

MySQLConnection::~MySQLConnection()
{
    delete stmt;
    delete resultset;
    delete connection;
}
