#ifndef CONSTANTS
#define CONSTANTS
#include <QString>

namespace constants
{
    const QString CONNECTION_NAME = "db_connection";
    const QString DATE_FORMAT = "d/M/yyyy";
    const QString IMPORT_DATE_FORMAT = "yyyy-M-d";
    const std::string MENU_DELIMITER(101, '-');
    const std::string SELECTION_PROMPT = "Enter selection: ";
    const std::string SELECTION_NOT_VALID = "Invalid selection. Please try again.";
    const int MAX_NAME_LENGTH = 36;
    const int MAX_COMP_NAME_LENGTH = 20;
    const QString SCIENTISTS_FILENAME = "scientists.sqlite";
    const QString SEARCH_SCIENTIST_TEMPLATE = "SELECT * FROM scientists WHERE %1 LIKE '%%2%' ";
    const std::string FOUND = "Found entries:";
    const QString SCIENTIST_EDIT = "UPDATE scientists SET %1 = '%2' WHERE id = %3";
    const QString SCIENTIST_FROM_ID = "SELECT * FROM scientists WHERE id LIKE '%%1%'";
    const QString SCIENTISTS_ORDER = "SELECT * FROM scientists WHERE active LIKE 1 ORDER BY %1 ";
    const QString INSERT_FORM =  "INSERT INTO scientists (firstname, lastname, birth, death, gender, alive, active)" 
                                 "VALUES (:first, :last, :b, :d, :g, :a, :act)";
    const QString DATABASE_NAME = "db.sqlite";
    const QString COMPUTERS_ORDER = "SELECT * FROM computers WHERE active LIKE 1 ORDER BY %1";
    const QString COMPUTERS_SEARCH = "SELECT * FROM computers WHERE %1 LIKE '%%2%' ";
    const QString COMPUTERS_EDIT = "UPDATE computers SET %1 = '%2' WHERE id = %3";
    const QString COMPUTER_FROM_ID = "SELECT * FROM computers WHERE id LIKE '%%1%'";
    const QString DELETE_SCIENTIST = "DELETE FROM scientists WHERE id = %1";
    const QString CONNECTED_SCIENTIST_ID = "SELECT scientist_id FROM owners WHERE computer_id LIKE '%%1%'";
    const QString SCIENTIST_JOIN =  "SELECT lastname FROM scientists s, owners o WHERE s.id = o.scientist_id AND %1 = o.computer_id";
    const QString COMPUTER_JOIN =  "SELECT name FROM computers c, owners o WHERE c.id = o.computer_id AND %1 = o.scientist_id";
    const QString ADD_CONNECTION = "INSERT INTO owners (scientist_id, computer_id) VALUES %1, %2";
    const QString MAKE_TABLE = "IF NOT EXISTS (CREATE TABLE Scientists(id INTEGER PRIMARY KEY AUTOINCREMENT, firstname VARCHAR NOT NULL, lastname VARCHAR NOT NULL, birth DATE NOT NULL, death DATE, gender BOOL, alive BOOL, active BOOL); CREATE TABLE Computers(id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR NOT NULL, built_year DATETIME, type ENUM, built BOOL, active BOOL); CREATE TABLE Owners(scientist_id INTEGER, computer_id INTEGER, FOREIGN KEY (scientist_id) REFERENCES Scientists(id), FOREIGN KEY (computer_id) REFERENCES Computers(id), PRIMARY KEY (scientist_id, computer_id))";
}

#endif // CONSTANTS

