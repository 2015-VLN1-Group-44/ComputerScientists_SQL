#include "repository.h"


using namespace std;

Repository::Repository()
{
}

vector<Scientist> Repository::read_file(string filename)
{
    Scientist temp;
    vector<Scientist> data;
    ifstream in_file;
    string line;
    char g;
    QDate birth, death;
    QString date, format;
    format = "d.M.yyyy";
    in_file.open(filename.c_str());
    if (in_file.fail())
    {
        cout << "Unable to open file" << endl;
    }
    else
    {
        cout << "File read." << endl;
    }
    while (getline(in_file, line))
    {
        temp.set_first(line);
        getline(in_file, line);
        temp.set_last(line);
        getline(in_file, line);
        date = QString::fromStdString(line);
        temp.set_birth(QDate::fromString(date, format));
        getline(in_file, line);
        date = QString::fromStdString(line);
        temp.set_death(QDate::fromString(date, format));
        // sé einstaklingur lifandi er dagsetning á forminu 0.0.0
        if (!temp.get_death().isValid())
        {
            temp.set_living(true);
        }
        else
        {
            temp.set_living(false);
        }
        getline(in_file, line);
        g = line[0];
        if (g == 'M' || g == 'm')
        {
            temp.set_gender(1);
        }
        else
            temp.set_gender(0);
        data.push_back(temp);
    }
    in_file.close();
    return data;
}

void Repository::print_to_file(string filename, vector<Scientist> s)
{
    ofstream out_file;
    out_file.open(filename.c_str());

    for (unsigned int i = 0; i < s.size(); i++)
    {
        out_file << s[i].get_first()<< endl;
        out_file << s[i].get_last() << endl;
        out_file << s[i].get_birth().day() << "." << s[i].get_birth().month() << "." ;
        out_file << setfill('0') << setw(4) << s[i].get_birth().year() << endl;
        if (!s[i].get_living())
        {
            out_file << s[i].get_death().day() << "." << s[i].get_death().month() << ".";
            out_file << setfill('0') << setw(4) << s[i].get_death().year() << endl;
        }
        else
        {
            out_file << "0.0.0" << endl;
        }
        if (s[i].get_gender())
            out_file << "M" << endl;
        else
            out_file << "F" << endl;
    }
    out_file.close();
}

vector<Scientist> Repository::open_scientist_db(QString sql_command)
{
    vector<Scientist> data;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "db.sqlite";       // Magnea breytti scientists.sqlite í db.sqlite
    db.setDatabaseName(dbName);
    db.open();
    QSqlQuery query(db);

    query.exec(sql_command);
    // qDebug() << query.lastQuery();
    while (query.next())
    {
        string first, last;
        QDate b, d;
        bool g, a;
        int id_n;
        // qDebug() << query.lastQuery();
        first = query.value("firstname").toString().toStdString();
        last = query.value("lastname").toString().toStdString();
        b = QDate::fromString(query.value("birth").toString(), constants::IMPORT_DATE_FORMAT);
        d = QDate::fromString(query.value("death").toString(), constants::IMPORT_DATE_FORMAT);
        id_n = query.value("id").toInt();
        g = query.value("gender").toBool();
        a = query.value("alive").toBool();

        Scientist temp(first, last, g, b, d, a, id_n);
        data.push_back(temp);
    }

    db.close();
    return data;
}
