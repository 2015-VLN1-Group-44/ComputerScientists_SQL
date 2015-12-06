#ifndef CONSTANTS
#define CONSTANTS
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
    const std::string FOUND = "Found entries:";
    const QString SCIENTIST_EDIT = "UPDATE scientists SET %1 = '%2' WHERE id = %3";
    const QString SCIENTIST_FROM_ID = "SELECT * FROM scientists WHERE id LIKE '%%1%'";
    const QString SCIENTISTS_ORDER = "SELECT * FROM scientists ORDER BY %1";
}

#endif // CONSTANTS

