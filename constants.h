#ifndef CONSTANTS
#define CONSTANTS
#include <string>
#include <QString>

namespace constants
{
    const QString DATE_FORMAT = "d/M/yyyy";
    const QString IMPORT_DATE_FORMAT = "yyyy-M-d";
    const std::string MENU_DELIMITER(101, '-');
    const std::string SELECTION_PROMPT = "Enter selection: ";
    const std::string SELECTION_NOT_VALID = "Invalid selection. Please try again.";
    const int MAX_NAME_LENGTH = 36;
    const QString SCIENTISTS_FILENAME = "scientists.sqlite";
    const QString SEARCH_SCIENTIST_TEMPLATE = "SELECT * FROM scientists WHERE %1 LIKE '%%2%' ";
}

#endif // CONSTANTS

