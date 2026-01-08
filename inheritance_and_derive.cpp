#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class People
{
protected:
    string name;
    int age;

public:
    People();
    People(string name, int age);
    ~People();

    virtual void display() const;
    virtual void show_salary() = 0;
};

People::People() : name("none"), age(0)
{
    // cout << "执行People类默认构造函数..." << name << endl;
}

People::People(string name, int age) : name(name), age(age)
{
    // cout << "执行People类含参构造函数..." << name << endl;
}

People::~People()
{
    // cout << "执行People类析构函数..." << name << endl;
}

void People::display() const
{
    cout << "name: " << name << ", age: " << age << endl;
}

class Teacher : public People
{
private:
    string working_place;

public:
    Teacher(string name, int age, string w_p);
    ~Teacher();
    void teach();
    void display() const override;
    void show_salary() override;
};

Teacher::Teacher(string name, int age, string w_p) : People(name, age), working_place(w_p)
{
    // cout << "执行Teacher类含参构造函数..." << name << endl;
}

Teacher::~Teacher()
{
    // cout << "执行Teacher类析构函数..." << name << endl;
}

void Teacher::teach()
{
    cout << name << " works in " << working_place << endl;
}

void Teacher::display() const
{
    cout << "name: " << name << ", age: " << age << ", working_place: " << working_place << endl;
}

void Teacher::show_salary(){
    cout << "salary: " << "12w per year." << endl;
}

int main()
{
    People* LiMing = new Teacher("LiMing", 30, "School");
    
    LiMing->display();
    LiMing->show_salary();

    delete LiMing;

    return 0;
}