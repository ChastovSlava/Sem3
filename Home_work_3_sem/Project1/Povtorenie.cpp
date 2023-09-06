#include <iostream>
#include <string>
using namespace std;
class FIO {
    std::string firstName;
    std::string secondName;
    std::string lastName;
public:
    FIO() {
        firstName = "No information";
        secondName = "No information";
        lastName = "No information";
    }
    FIO(std::string _firstName, std::string _secondName, std::string _lastName) :firstName(_firstName), secondName(_secondName), lastName(_lastName) {};
    FIO(const FIO& A) {
        firstName = A.firstName;
        secondName = A.secondName;
        lastName = A.lastName;
    }
    bool operator==(const FIO& A) {
        if (firstName==A.firstName) {
            return 1;
        }
        else {
            return 0;
        }
    }

    //Геттеры для полей(нужны для перегрузки вывода)
    std::string get_firstName() const{
        return firstName;
    }
    std::string get_secondName() const {
        return secondName;
    }
    std::string get_lastName() const {
        return lastName;
    }
};

//Перегрузка оператора вывода для ФИО
ostream& operator<<(ostream& oss, const FIO& A) {
    return oss << A.get_firstName()<<'  ' << A.get_secondName()<<'  '<<A.get_lastName()<<'  ';
}
class Student {
    FIO fio;
    int ID;
    float GPA;
    bool form_education;
    bool scholarship;
public:
    Student() {
        ID = 0;
        GPA = 0.0;
        form_education = false;
        scholarship = false;
    }
    Student(FIO fio_, int ID_, float GPA_, bool form_education_, bool scholarship_): fio(fio_), ID(ID_), GPA(GPA_), form_education(form_education_), scholarship(scholarship_){}
    Student(const Student& A) {
        fio = A.fio;
        ID = A.ID;
        GPA = A.GPA;
        form_education = A.form_education;
        scholarship = A.scholarship;
    }
    ~Student();

    //Сравнение по среднему баллу ввиде функции
    float comparison_GPA(float first_count, float second_count) {
        if (first_count > second_count) {
            return first_count;
        }
        else {
            return second_count;
        }
    }

    //Геттеры для полей (нужны для перегрузки вывода)
    int get_ID() const {
        return ID;
    }
    float get_GPA() const{
        return GPA;
    }
    bool get_form_education() const{
        return form_education;
    }
    bool get_scholarship() const{
        return scholarship;
    }
    Student operator=(Student st) {
        fio = st.fio;
        ID = st.ID;
        GPA = st.GPA;
        form_education = st.form_education;
        scholarship = st.scholarship;
        return *this;
    }
    bool operator==(const Student &A) {
        if (fio == A.fio) {
            return 1;
        }
        else {
            return 0;
        }
    }
};

//Перегрузка оператора вывода для ID, среднего балла, формы обучения(платно/бесплатно), наличия стипендии
ostream& operator<<(ostream& os, const Student & A) {
    return os <<A.get_ID()<<'  ' <<A.get_GPA()<<'  ' << A.get_form_education()<<'  '<<'  ' << A.get_scholarship()<<endl;
}
class Archive {
    int size;
    Student *students;
public:
    Archive() :size(0) {}

};
int main() {

	return 0;
}