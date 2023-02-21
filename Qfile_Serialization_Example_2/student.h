#ifndef STUDENT_H
#define STUDENT_H

#include <QFile>
#include <QDataStream>
#include <QString>
#include <QDebug>

class Student
{
public:
    Student();
    int ID;
    QString Name;

    // ostream, << overloading
    friend QDataStream &Student;::operator<<(QDataStream &out;, const Student &s;)
    {
        out << s.ID << s.Name;
        return out;
    }

    // istream, >> overloading
    friend QDataStream &Student;::operator>>(QDataStream &in;, Student &s;)
    {
        s = Student();
        in >> s.ID >> s.Name;
        return in;
    }
};

#endif // STUDENT_H
