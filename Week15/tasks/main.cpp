#include <iostream>
#include <cmath>
using namespace std;

struct Student {
    int faculty_number;
    int grades[5] = {0};
    char name[11];

    Student() {
        faculty_number = 0;
        name[0] = '\0';
    }

    Student(int faculty_number, int grades[5]) {
        this->faculty_number = faculty_number;
        for (size_t i = 0; i < 5; i++) {
            this->grades[i] = grades[i];
        }
    }

    void printStudentData() {
        cout << "--------------------------------\n";
        cout << "Faculty number: ";
        cout << this->faculty_number;
        cout << "\nGrades: ";
        for (size_t i = 0; i < 5; i++) {
            cout << this->grades[i] << " "; 
        }
        
        cout << "\n--------------------------------\n";
    }

    int getAverageGrading () {

    }
};

struct Point {
    int x;
    int y;

    Point() {
        x = -1;
        y = -1;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    // Point(int _x, int _y) {
    //     x = _x;
    //     y = _y;
    // }

    void printPoint() {
        cout << "(" << x << " , " << y << ")\n";
    }
};

struct Line {
    Point p1;
    Point p2;

    Line() {
        // p1.x = 0;
        // p2.x = 0;
        // p1.y = 0;
        // p2.y = 0;
    }

    Line(int x1, int y1, int x2, int y2) {
        p1 = Point(x1, y1);
        p2 = Point(x2, y2);
    }

    Line(Point p1, Point p2) {
        this->p1 = p1;
        this->p2 = p2;
    }

    int lengthOfLine() {
       return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
    }

    void printLine() {
        cout << "Length of line: " << this->lengthOfLine() << "\n";
        p1.printPoint();
        p2.printPoint();
    }

    bool isEqual(Line other_line) {
        int length_line = this->lengthOfLine();
        int length_other_line = other_line.lengthOfLine();
        return length_line == length_other_line;
    }
};

struct Triangle {
    Line sideA;
    Line sideB;
    Line sideC;

    Triangle() {}

    Triangle(Line sideA, Line sideB, Line sideC) {
        this->sideA = sideA;
        this->sideB = sideB;
        this->sideC = sideC;
    }

    bool isValidTriangle() {
        int lengthSideA = sideA.lengthOfLine();
        int lengthSideB = sideB.lengthOfLine();
        int lengthSideC = sideC.lengthOfLine();

        return lengthSideA + lengthSideB > lengthSideC && 
               lengthSideC + lengthSideB > lengthSideA &&
               lengthSideC + lengthSideA > lengthSideB;
    }

    int getP() {
        return sideA.lengthOfLine() + sideB.lengthOfLine() + sideC.lengthOfLine();
    }

    int getArea() {
        int p = getP() / 2;
        int area = sqrt(p* (p - sideA.lengthOfLine()) * (p - sideB.lengthOfLine()) * (p - sideC.lengthOfLine()));
        return area;
    }

    void printTriangle() {
        cout << boolalpha << this->isValidTriangle() << "\n";
        cout << this->getP() << "\n";
        cout << this->getArea() << "\n";
    }
};

int main() {
    // int n = 5;
    // int grades[5] = {6,5,6,5,2};
    // Student student1;   
    // student1.printStudentData();
    
    // Student student2(1234, grades);
    // student2.printStudentData();

    Point p1(1,0); // Point p1 = Point(1, 2);
    Point p2(0,2); 
    
    Point p3(-1,0); // Point p1 = Point(1, 2);
    Point p4(0,2);

    Point p5(-1,0); // Point p1 = Point(1, 2);
    Point p6(1,0);

    Line l1(p1, p2);
    Line l2(p3, p4);
    Line l3(p5, p6);

    Triangle triangle(l1, l2, l3);
    triangle.printTriangle();
}