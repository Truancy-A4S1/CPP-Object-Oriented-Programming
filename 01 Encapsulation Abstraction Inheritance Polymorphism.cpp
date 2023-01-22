#include <iostream>
using namespace std;

//abstraction
class AbstracEmployee{
    virtual void askForPromotion()=0;
};

class Employee : AbstracEmployee {
//access modifiers
private:    //can only be accessed inside the class
    string name{};
    string company{};

protected:  //can also be accessed inside child class
    int age{};

public:     //public haha
    // member functions AKA method
    // constructor, a special type of function automatically executed when the function is called tf we need to pass these values when making a new object
    Employee(string name_p, string company_p, int age_p){
        name = name_p;
        company = company_p;
        age = age_p;
    }
    void setName(string n){
        name = n;
    }
    string getName(){
        return name;
    }
    void setCompany(string c){
        company = c;
    }
    string getCompany(){
        return company;
    }
    void setAge(int a){
        age = a;
    }
    int getAge(){
        return age;
    }
    void introduceYourself()
    {
        cout << "Hi! I'm " << name << " from " << company << ". " << age << " years old.\n";
    }

    void askForPromotion(){
        //complex logic here (perforamance/contributions for the company, relationship with other employee, making deadlines, how long is he working to the company, etc.)
        if(age > 30)
            cout << name << " got a promotion." << endl;
        else
            cout << name << ", no promotion for you" << endl;
    }

    //'virtual' will check if there are the similar functions in child class, and if there is, execute those instead
    virtual void isWorking()
    {
        cout << name << " is working." << endl;
    }


};

//Developer is now a child class of employee, developer inherits all the functions/datatypes inside employee
class Developer : public Employee{
private:
    string favoriteLang;

public:
    // constructor for child class; Developer
    Developer(string name_p, string company_p, int age_p, string favLan_p)
        :Employee(name_p, company_p, age_p) //set name, company, age by passing it to employee constructor
    {
        favoriteLang = favLan_p;    //we only need to set the child class favLang.
    }


/* we use getName() and getCompany() in this function because it is declared as private in the parent class we can directly call the age variable from parent class because its access modifier is set to protected. see employee declarations */
    void introduceDeveloper(){
        cout << "Hi! I'm " << getName() << " from " << getCompany() << ", " << age
        << " years old. My favorite language is " << favoriteLang << endl;

    }

    void isWorking(){
        cout << getName() << " is writing code in " << favoriteLang << endl;
    }
};

class Janitor : public Employee{
private:
    string weapon;
public:
    //constructor
    Janitor(string name_p, string company_p, int age_p, string weapon_p)
        :Employee(name_p, company_p, age_p) // call the constructor of parent class
    {
        weapon = weapon_p;
    }

    void printWeapon()
    {
        cout << "I use " << weapon << " for cleaning." << endl;
    }

    void isWorking(){
        cout << getName() << " is cleaning using " << weapon << endl;
    }

};

int main()
{
    //declare employee1
    cout << "Constructor & Encapsulation\n";
    Employee employee1 = Employee("Frey", "Troumen's Rings", 4035);
    employee1.introduceYourself();

    //declare employee2
    Employee employee2 = Employee("Beniang", "Troumen's Rings", 21);
    employee2.introduceYourself();

    employee1.setName("Lukas");
    employee1.introduceYourself();



    cout << "\nAbstraction (if age > 30)\n";
    employee1.askForPromotion();
    employee2.askForPromotion();



    cout << "\nInheritance\n";
    Developer dev1 = Developer("Tao", "Raizel Knight", 25, "C++");
    dev1.introduceDeveloper();

    //we can call parent functions by assigning parent class as public in declaring child class. line 60
    dev1.introduceYourself();

    Janitor jan1 = Janitor("Mr Dayun", "KRP LGU", 59, "long broom");
    jan1.printWeapon();



    //polymorphism is commonly used when a parent class reference is used to refer a child class object
    cout << "\nPolymorphism\n";
    //step 1: declare an object pointer of type parent class
    Employee* empPtr1 = &dev1;
    Employee* empPtr2 = &jan1;

    //step 2: call the function inside the pointer
    empPtr1 -> isWorking();
    empPtr2 -> isWorking();

    cout << endl;
    //actually working din to, di ko alam kung bakit di ganito ginamit  niya
    dev1.isWorking();
    jan1.isWorking();


}

//how to create new object automatically while the program is running
