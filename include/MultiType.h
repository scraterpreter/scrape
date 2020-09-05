#include <string>
#include <iostream>

class MultiType
{
public:
    MultiType(const std::string &s);
    std::string getString();
    double getDouble();
    void setString(const std::string &s);
    void setDouble(const double &d);
private:
    enum Type {STRING,DOUBLE};
    std::string stringVar;
    double doubleVar;
    Type type;
};
