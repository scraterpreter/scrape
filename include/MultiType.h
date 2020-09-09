#pragma once

#include <string>
#include <stdexcept>

enum Type {STRING,DOUBLE};

class MultiType
{
public:
    MultiType(const std::string &s);
    MultiType(double d);
    std::string getString();
    double getDouble();
    void setString(const std::string &s);
    void setDouble(const double &d);
    bool operator==(const MultiType &other) const;
    bool operator<(const MultiType &other) const;
    bool operator>(const MultiType &other) const;
private:
    friend std::ostream& operator<<(std::ostream& out, const MultiType& obj);
    enum CompareResult {EQUAL,LESS,GREATER};
    static CompareResult stringDoubleCompare(std::string s,double d);
    std::string stringVar;
    double doubleVar;
    Type type;
};
