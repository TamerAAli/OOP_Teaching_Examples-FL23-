#include <iostream>
#include <string>
#include <list>
#include <fstream>
//#include <stdexcept>
using namespace std;

void doSomeOtherWorkThatNeedsBigAmuontOfMemory()
{
	int dummyArray[5000]; // This could potentially overwrite the previous array's memory
}

namespace past
{
	namespace Lec1
	{
		namespace Ex1
		{
			int main()
			{
				cout << "Size of short: " << sizeof(short) << endl;
				cout << "Size of int: " << sizeof(int) << endl;
				cout << "Size of long: " << sizeof(long) << endl;
				cout << "Size of long long: " << sizeof(long long) << endl;
				cout << "Size of double: " << sizeof(double) << endl;
				cout << "Size of long double: " << sizeof(long double) << endl;
				cout << "Size of float: " << sizeof(float) << endl;
				return 0;
			}
		} // namespace Ex1
		namespace Ex2
		{
			int main()
			{
				int sec = 0;
				cout << "Enter seconds: ";
				cin >> sec;
				cout << "Minuets: " << sec / 60;
				cout << ", Seconds: " << sec % 60;
				return 0;
			}
		} // namespace Ex2
	} // namespace Lec1

	namespace Lec2
	{
		namespace Ex1
		{
			const int MAX_TV_CHANNEL = 100;
			bool getTvStatus(const char* tvName)
			{
				return true;
			}
			int getTvCurrentChannel(const char* tvName)
			{
				return 0;
			}
			int main()
			{
				auto tv1 = "tv1";
				bool isTvOpen = getTvStatus(tv1);
				int currentChannel = getTvCurrentChannel(tv1);
				if (isTvOpen)
					if (currentChannel <= MAX_TV_CHANNEL)
						currentChannel++;
				if (isTvOpen && currentChannel <= MAX_TV_CHANNEL)
					currentChannel++;
				return 0;
			}
		} // namescpace Ex1
		namespace Ex2
		{
			int main()
			{
				cout << boolalpha << (1 < 4 > 3) << endl;
				cout << boolalpha << (1 == 2 == 0) << endl;
				return 0;
			}
		} // namespace Ex2
		namespace Ex3
		{
			int main()
			{
				int x = 10;
				float y = 5.5;

				x += 10;
				y += 10;
				cout << x << " " << y;

				//x += 10;
				//y += 10.0;
				//cin >> x >> " " >> y;
				//
				//x += 10;
				//y += 10;
				//print << x << " " << y;

				return 0;
			}
		} // namespace Ex3
	} // namespace Lec2

	namespace Lec3
	{
		namespace Ex1
		{
			void modifyValues(int a, int b)
			{
				a = 0;
				b = 0;
			}

			void updateNumbers(const int& m, int& n)
			{
				modifyValues(m, n);
			}

			int main()
			{
				int x = 5, y = 5;
				updateNumbers(x, y);
				cout << x << " " << y;
				return 0;
			}
		} // namespace Ex1
		namespace Ex2
		{
		}
	} // namespace Lec3

	namespace Lec4
	{
		namespace Ex1
		{
			enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY };
			int main()
			{
				Day day; // Declare
				day = MONDAY; // Assign to one of the values
				cout << day;
				Day day2 = WEDNESDAY; // Declare and Assign 
				//cin >> day2;
				return 0;
			}
		} // namespace Ex1

	} // namespace Lec4

	namespace Lec5
	{
		namespace Ex1
		{
			class Demo
			{
			public:
				Demo() // Constructor
				{
					cout << "1. Welcome to the constructor!\n";
				}
				~Demo() // Destructor
				{
					cout << "2. The destructor is now running.\n";
				}
			};

			int main()
			{
				Demo demoObject; // Define a demo object;

				cout << "A. This program demonstrates an object\n";
				cout << "B. To demo the constructor / destructor.\n";
				return 0;
			}
		} // Ex1
		namespace Ex2
		{
			class Demo
			{
			public:
				Demo() // Constructor
				{
					cout << "1. Welcome to the constructor!\n";
				}
				~Demo() // Destructor
				{
					cout << "2. The destructor is now running.\n";
				}
			};

			void SomeGlobalFunction()
			{
				Demo demoObject; // Define a demo object;
			}

			int main()
			{
				SomeGlobalFunction();

				cout << "A. This program demonstrates an object\n";
				cout << "B. To demo the constructor / destructor.\n";
				return 0;
			}
		} // Ex2

		namespace freeEx
		{

			int main()
			{
				return 0;
			}
		} // freeEx
	} // namespace Lec5

	namespace Lec6
	{
		namespace Ex1
		{
			int main()
			{
				string s1 = "CIE202", s2 = "CIE 202";
				bool check = s1 == s2; // abstraction example: == is a function
				return 0;
			}
		} // namespace Ex1

		namespace Ex2
		{
			class GeometricObject
			{
			public: string getColor() const { return "red"; };
			};

			class Circle : public GeometricObject
			{
			public: double getRadius() const { return 1; };
			};

			void dispData(const GeometricObject& o)
			{
				cout << o.getColor();
			}

			int main()
			{
				Circle c;
				dispData(c);
				return 0;
			}
		} // namespaceEx2

		namespace Ex3
		{
#include <iostream>

			class BankAccount
			{
			private: double balance;

			public:
				BankAccount(double initBal) : balance(initBal) {}

				bool hasSameBalance(const BankAccount& other) const
				{
					return balance == other.balance;
				}
			};

			int main() {
				BankAccount account1(5000.00), account2(3000.00);

				if (account1.hasSameBalance(account2))
					cout << "Same balance." << endl;
				else
					cout << "Different balances." << endl;

				return 0;
			}

		} // namespace Ex3
		namespace Ex4
		{
			class ClassB;
			class ClassA
			{
			public:	int dataA = 1;
				  //private:	int dataA = 1;
			public:
				bool isEqualToDataB(const ClassB& b);
			};

			class ClassB
			{
			public:
				int dataB = 2;
				bool isEqualToDataA(const ClassA& a)
				{
					return dataB == a.dataA; // Line 2
				}
			};

			bool ClassA::isEqualToDataB(const ClassB& b)
			{
				return dataA == b.dataB; // Line 1
			}
			int main()
			{
				ClassA objA;
				ClassB objB;
				cout << boolalpha << objB.isEqualToDataA(objA) << endl;

				return 0;
			}
		} // namespace Ex4

		namespace Ex5
		{
			class Instructor
			{
			private: string _name = "Default Name";
			public:
				void setName(string newName) { _name = newName; }
				string getName() const { return _name; }
			};

			class Student
			{
			private: Instructor* _instr = nullptr;
			public:
				void setInstr(Instructor& instr) { _instr = &instr; }
				string getInstrName() const
				{
					if (_instr) return _instr->getName();
					return "N/A";
				}
			};
			int main()
			{
				Instructor instr;
				cout << "Instr name: " << instr.getName() << endl;
				cout << string(24, '-') << endl;

				Student st1; st1.setInstr(instr);
				Student st2; st2.setInstr(instr);
				cout << "St 1 instr: " << st1.getInstrName() << endl;
				cout << "St 2 instr: " << st2.getInstrName() << endl;
				cout << string(24, '-') << endl;

				instr.setName("new name");
				cout << "Instr name: " << instr.getName() << endl;
				cout << string(24, '-') << endl;

				cout << "St 1 instr: " << st1.getInstrName() << endl;
				cout << "St 2 instr: " << st2.getInstrName() << endl;
				return 0;
			}
		} // namespace Ex5
	} // namespace Lec6

	namespace Lec8
	{
		namespace Ex1
		{
			void printArray(int* list, int size)
			{
				for (int i = 0; i < size; i++)
					cout << list[i] << " ";
			}

			int main()
			{
				int a[] = { 1,2,3 };
				printArray(a, 3);
				return 0;
			}
		} // namespace Ex1

		namespace Ex2
		{
			void reverse(int* list, int size)
			{
				int* left = list;
				int* right = list + size - 1;

				for (; left < right; ++left, --right)
				{
					int temp = *left;
					*left = *right;
					*right = temp;
				}
			}

			int main()
			{
				int myArray[5] =
				{ 1, 2, 3, 4, 5 };

				reverse(myArray, 5);

				// Print the reversed array
				for (int i = 0; i < 5; i++)
					cout << myArray[i] << " ";

				return 0;
			}
		} // namespace Ex2

		namespace Ex3
		{
			int main()
			{
				char continueInput = 'Y';

				while (continueInput == 'Y')
				{
					cout << "Enter the size of the array: ";
					int size;
					cin >> size;
					int* array = new int[size];

					cout << "Enter " << size << " integers:" << endl;
					int sum = 0;
					for (int i = 0; i < size; ++i)
					{
						cin >> array[i];
						sum += array[i];
					}

					cout << "You entered:" << endl;
					for (int i = 0; i < size; ++i)
						cout << array[i] << " ";
					cout << endl;
					cout << "The sum is: " << sum << endl;

					delete[] array;


					// Ask user to repeat or exit
					cout << "Do you want to enter another array? (Y/N): ";
					cin >> continueInput;
				}

				return 0;
			}

		} // namespace Ex3
	} // namespace Lec8

	namespace Lec9
	{
		namespace Ex1
		{
			void reverse_lastLec(int* list, int size)
			{
				int* left = list;
				int* right = list + size - 1;

				for (; left < right; ++left, --right)
				{
					int temp = *left;
					*left = *right;
					*right = temp;
				}
			}

			int* reverse(int* list, int size)
			{
				//int* result = list;
				//int result[size];
				//int result[1000];
				//int* result = new int[size];

				for (int i = 0; i < size; ++i)
					list[i] = list[size - 1 - i];
				return list;
			}

			int main()
			{
				int myArray[5] = { 1, 2, 3, 4, 5 };

				reverse_lastLec(myArray, 5);

				// Print the original array
				cout << "Original array: ";
				for (int i = 0; i < 5; i++)
					cout << myArray[i] << " ";
				cout << endl;

				// Print the reversed array

				return 0;
			}
		} // namespace Ex1

		namespace Ex2
		{
#include <iostream>
			using namespace std;

			class AudioBuffer
			{
			private:
				const int NUM_SAMPLES; // Number of samples
				float* samples = nullptr; // Pointer to array of samples

			public:
				AudioBuffer(int nSamples) : NUM_SAMPLES(nSamples)
				{
					if (!nSamples) return;

					samples = new float[nSamples];
					for (int i = 0; i < nSamples; ++i)
						samples[i] = 0.0f; // default values
				}

				~AudioBuffer()
				{
					if (this->samples)
						delete[] this->samples;
				}

				void setSample(int index, float value)
				{
					samples[index] = value;
				}
			};

			int main()
			{
				AudioBuffer buffer(5);

				// Set some sample values
				buffer.setSample(0, 0.1f);
				buffer.setSample(1, 0.5f);
				buffer.setSample(2, 0.9f);

				return 0; // Destructor is called
			}
		} // namespace Ex2

		namespace Ex3 // const pointer
		{
			//int main()
			//{
			//	double radius = 5, length = 4;
			//	const double MAX_RADIUS = 100;

			//	double* const ptr1 = &radius;
			//	cout << *ptr1 << endl;
			//	*ptr1 += 5;

			//	ptr1 = &length;
			//	cout << *ptr1 << endl;
			//	*ptr1 += 5;

			//	ptr1 = &MAX_RADIUS;
			//	cout << *ptr1 << endl;

			//	return 0;
			//}
		} // namespace Ex3

		namespace freeExample
		{
			int main()
			{
				return 0;
			}
		} // namespace freeExample

	} // namespace Lec9

	namespace Lec10
	{
		namespace Ex1
		{
			class GeometricObject
			{
			public:
				GeometricObject();
				GeometricObject(const string&, bool);
				string getColor() const;
				void setColor(const string&);
				bool isFilled() const;
				void setFilled(bool);
				string toString() const;

			private:
				string color;
				bool filled;
			}; // Must place semicolon here

			GeometricObject::GeometricObject()
				: color("white"), filled(false)
			{
			}

			GeometricObject::GeometricObject(const string& col, bool fil)
			{
				color = col;
				filled = fil;
			}

			string GeometricObject::getColor() const
			{
				return color;
			}

			void GeometricObject::setColor(const string& col)
			{
				color = col;
			}

			bool GeometricObject::isFilled() const
			{
				return filled;
			}

			void GeometricObject::setFilled(bool fil)
			{
				filled = fil;
			}

			string GeometricObject::toString() const
			{
				return "Geometric Object";
			}


			class Circle : public GeometricObject
			{
			public:
				Circle();
				Circle(double);
				Circle(double, const string&, bool);
				double getRadius() const;
				void setRadius(double);
				double getArea() const;
				double getPerimeter() const;
				double getDiameter() const;
				string toString() const;

			private:
				double radius;
			}; // Must place semicolon here

			// Construct a default circle object
			Circle::Circle()
			{
				radius = 1;
			}

			// Construct a circle object with specified radius
			Circle::Circle(double newRadius)
			{
				setRadius(newRadius);
			}

			// Construct a circle object with specified radius,
			//  color and filled values
			Circle::Circle(double newRadius, const string& col, bool fil)
			{



			}

			// Return the radius of this circle
			double Circle::getRadius() const
			{
				return radius;
			}

			// Return the diameter of this circle
			double Circle::getDiameter() const
			{
				return 2 * radius;
			}

			// Set a new radius
			void Circle::setRadius(double newRadius)
			{
				if (newRadius >= 0)
					radius = newRadius;
				else
					radius = 0;
			}
			// Return the area of this circle
			double Circle::getArea() const
			{
				return radius * radius * 3.14159;
			}

			// Return the perimeter of this circle
			double Circle::getPerimeter() const
			{
				return 2 * radius * 3.14159;
			}

			// Redefine the toString function
			string Circle::toString() const
			{
				return "Circle object";
			}
		} // namespace Ex1

		namespace Ex2
		{
			class BaseClass
			{
			public:
				BaseClass() // Constructor
				{
					cout << "BaseClass constructor.\n";
				}
				~BaseClass() // Destructor
				{
					cout << "BaseClass destructor.\n";
				}
			};
			class DerivedClass : public BaseClass
			{
			public:
				DerivedClass() // Constructor
				{
					cout << "DerivedClass constructor.\n";
				}
				~DerivedClass() // Destructor
				{
					cout << "DerivedClass destructor.\n";
				}
			};

			int main()
			{
				cout << "We will now define a DerivedClass object.\n";
				DerivedClass object;
				cout << "The program is now going to end.\n";

				return 0;
			}

		} // namespace

		namespace Ex3
		{
			class BaseClass
			{
			public:
				BaseClass() { cout << "1 "; }
				~BaseClass() { cout << "2 "; }
			};
			class DerivedClass : public BaseClass
			{
			public:
				DerivedClass() { cout << "3 "; }
				~DerivedClass() { cout << "4 "; }
			};
			DerivedClass* someFunc()
			{
				cout << "5 "; DerivedClass* ptr = new DerivedClass;
				cout << "6 "; return ptr;
			}
			int main()
			{
				cout << "7 "; DerivedClass* ptr = someFunc();
				cout << "8 "; delete ptr;
				return 0;
			}
		} // namespace Ex3

		namespace Ex4
		{
			class Mover
			{
			protected: int incr, coveredD;
			public:
				Mover() : incr(10), coveredD(0) {}
				void move() { coveredD += incr; }
				int getCoveredDistance() const { return coveredD; }
			};

			class FastRunner : public Mover
			{
			public: FastRunner() { incr = 30; }
			};
			class SlowWalker : public Mover
			{
			public: SlowWalker() { incr = 5; }
			};


			int main()
			{
				FastRunner runner;
				SlowWalker walker;

				runner.move();  // Moves by 30 units
				walker.move();  // Moves by 5 units

				cout << "Runner covered: " << runner.getCoveredDistance() << endl;
				cout << "Walker covered: " << walker.getCoveredDistance() << endl;

				return 0;
			}
		} // namespace Ex4

		namespace Ex5
		{
			class P
			{
			public: void print() { cout << "P "; }
			};

			class Q :public P { };

			class R :public Q { public: void print() { cout << "R "; } };

			void display(P& p) { p.print(); }

			int main(void)
			{
				P* p = new R;
				p->print();
				return 0;
			}

		} // namespace Ex5

		namespace Ex6
		{
			class GeomObj
			{
			public:
				string toString()
				{
					return "GeomObj";
				}
			};
			class Circle : public GeomObj
			{
			public:
				string toString()
				{
					return "Circle";
				}
			};
			void dispType(GeomObj* geo)
			{
				cout << geo->toString();
				cout << endl;
			}

			int main()
			{
				GeomObj* base = new GeomObj;
				dispType(base);

				Circle* derived = new Circle;
				dispType(derived);

				return 0;
			}
		} // namespace Ex6

		namespace Ex7
		{
			class Animal
			{
			public: virtual void Speak() { }
			};
			class Dog : public Animal { void Speak() { cout << "Woof!"; } };
			class Duck : public Animal { void Speak() { cout << "Quack!"; } };
			class Cat : public Animal { void Speak() { cout << "Meow!"; } };

			int main()
			{
				Animal* animals[3] =
				{
					new Dog(),
					new Duck(),
					new Cat()
				};

				for (int i = 0; i < 3; i++)
					animals[i]->Speak();
				return 0;
			}
		} // namespace Ex7

		// override / final
		namespace Ex8
		{
			class Base
			{
			public:
				void display()
				{
					cout << "Base" << endl;
				}
			};

			class Derived : public Base
			{
			public:
				void desplay()
				{
					cout << "Derived" << endl;
				}
			};

			int main()
			{
				Base* b = new Derived;
				b->display();
				return 0;
			}
		} // namespace Ex7

		namespace Ex9
		{
			class Base
			{
			public: int baseData = 5;
			};
			class Derived : public Base
			{
			public: long double extraData = 5;
			};
			void display(Base** arr, int size)
			{
				for (int i = 0; i < size; i++)
					cout << arr[i]->baseData << endl;
			}

			int main()
			{
				Base** arr = new Base * [3]; // Array of Derived objects, but pointer is of type Base
				arr[0] = new Derived;
				arr[1] = new Derived;
				arr[2] = new Derived;
				display(arr, 3);
				return 0;
			}

		} // namespace Ex8

		namespace freeExample
		{
			int main()
			{
				return 0;
			}
		} // namespace freeExample
	} // namespace L10

	namespace Lec11
	{
		namespace Ex1
		{
			class Base
			{
			public:
				void func() { cout << "Base fn" << endl; }
				virtual void vfunc() { cout << "Base virFn" << endl; }
			};

			class Derived : public Base
			{
			public:
				void func() { cout << "Derived fn" << endl; }
				void vfunc() override { cout << "Derived  virFn" << endl; }
			};

			int main()
			{
				Base* b = new Derived();
				b->func();
				b->vfunc();
				delete b;
				return 0;
			}
		} // namespace Ex1

		namespace Ex2
		{
			class Animal
			{
			public: virtual void speak() const { cout << "Sound." << endl; }
			};

			class Dog : public Animal
			{
			public: void speak() const override final { cout << "Woof!" << endl; }
			};

			class Cat : public Animal
			{
			public: void speak() const override { cout << "Meow!" << endl; }
			};

			class Duck : public Animal
			{
			public: void speak() const override;
			};

			void Duck::speak() const { cout << "Quack!" << endl; }


			//class BullDog : public Dog
			//{
			//public: void speak() const { cout << "Woof!" << endl; }
			//};

			int main()
			{
				Animal* animals[3] =
				{
					new Dog(),
					new Duck(),
					new Cat()
				};

				for (int i = 0; i < 3; i++)
					animals[i]->speak();

				return 0;
			}


		} // namespace Ex2

		namespace freeExample
		{
			int main()
			{
				return 0;
			}
		} // freeExample


	} // namespace Lec11

	namespace Lec12
	{
		namespace Ex1
		{
			class Person
			{
			protected:
				string name;
			public:
				Person(const string& name) : name(name) {}
				virtual ~Person() = default;

				void setName(const string& newName) { name = newName; }
				string getName() const { return name; }
			};

			class Employee
			{
			protected:
				int id;
			public:
				Employee(int id) : id(id) {}
				virtual ~Employee() = default;

				void setId(int newId) { id = newId; }
				int getId() const { return id; }
			};

			class Manager : public Person, public Employee
			{
			private:
				string department;
			public:
				Manager(const string& name, int id, const string& dept)
					: Person(name), Employee(id), department(dept) {}

				void setDepartment(const string& newDept) { department = newDept; }
				string getDepartment() const { return department; }
			};

			int main()
			{
				return 0;
			}
		} // namespace Ex1

		namespace Ex2
		{
			class B
			{
			public:
				B() { cout << "1. Base constructor" << endl; }
				B(const B&) { cout << "2. Base copy constructor" << endl; }
			};

			class D : public B
			{
			public:
				D() { cout << "3. Derived constructor" << endl; }
				//D(const D& d) { cout << "4. Derived copy constructor" << endl; }
				//D(const D& d): B(d) { cout << "4. Derived copy constructor" << endl; }
			};

			int main()
			{
				D d;
				cout << endl;
				cout << endl;
				cout << endl;
				D d2(d);
				return 0;
			}
		} // namespace Ex2

	} // namespace Lec12

	namespace Lec13
	{
		namespace Ex1
		{
			class GeometricObject
			{
			public:
				virtual double getArea() const = 0;
				virtual double getPerimeter() const = 0;
			};

			class Circle : public GeometricObject
			{
			private:
				double radius = 1;
			public:
				virtual double getArea() const override
				{
					return radius * radius * 3.14;
				}
				virtual double getPerimeter() const override
				{
					return 2 * 3.14 * radius;
				}
				Circle(double radius) : radius(radius) {}
				double getRadius() const { return radius; }
				double getDiameter() const { return 2 * radius; }
			};

			class Rectangle : public GeometricObject
			{
			private:
				double width = 1;
				double height = 1;
			public:
				virtual double getArea() const override
				{
					return height * width;
				}
				virtual double getPerimeter() const override
				{
					return 2 * (height + width);
				}
				Rectangle(double width, double height)
					: height(height), width(width)
				{}
				double getWidth() const { return width; }
				double getHeight() const { return height; }
			};

			void displayGeometricObject(const GeometricObject* g)
			{
				const Circle* ptrC = dynamic_cast<const Circle*>(g);
				const Rectangle* ptrR = dynamic_cast<const Rectangle*>(g);

				if (ptrC)
				{
					cout << "The radius is " << ptrC->getRadius() << endl;
					cout << "The diameter is " << ptrC->getDiameter() << endl;
				}
				if (ptrR != nullptr)
				{
					cout << "The width is " << ptrR->getWidth() << endl;
					cout << "The height is " << ptrR->getHeight() << endl;
				}
				if (g != NULL)
				{
					cout << "The area is " << g->getArea() << endl;
					cout << "The perimeter is " << g->getPerimeter() << endl;
				}

			}

			int main()
			{
				GeometricObject* geometricObjectList[] =
				{
					new Rectangle(3,4),
					new Rectangle(6,8),
					new Circle(5),
					new Circle(9)
				};

				for (int i = 0; i < 4; i++)
				{
					displayGeometricObject(geometricObjectList[i]);
					cout << string(20, '-') << endl;
				}

				return 0;
			}
		} // namespace Ex1

		namespace Ex2
		{
			class MyClass
			{
			public:
				int data = 10;
				void dangerousMethod()
				{
					doSomeOtherWorkThatNeedsBigAmuontOfMemory();
					delete this;
					doSomeOtherWorkThatNeedsBigAmuontOfMemory();
				}

				int anotherMethod()
				{
					doSomeOtherWorkThatNeedsBigAmuontOfMemory();
					cout << "This is unsafe if called after dangerousMethod!" << endl;
					doSomeOtherWorkThatNeedsBigAmuontOfMemory();
					return data;
				}
			};

			int main()
			{
				MyClass* myObject = new MyClass;
				myObject->dangerousMethod();
				cout << myObject->anotherMethod() << endl;

				delete myObject;

				MyClass myObject2;
				myObject2.dangerousMethod();
				cout << myObject2.anotherMethod() << endl;

				return 0;
			}
		} // namespace Ex2

		namespace Ex3
		{
			class Fraction
			{
			public:
				Fraction(int num, int denom);
				Fraction(int num);
				Fraction(const Fraction& other);
				Fraction& operator=(const Fraction& other);
				Fraction& operator=(const int& other);
				Fraction operator+(const Fraction& other) const;
				Fraction operator+(const int& other) const;
				friend Fraction operator+(const int& lhs, const Fraction& rhs);
				friend ostream& operator<<(ostream& cout, const Fraction& rhs);

				double convertToDecimal() const
				{
					return double(numerator) / denominator;
				}

				operator double() const { return (double)numerator / denominator; }

			private:
				int numerator = 0;
				int denominator = 1;
			};

			Fraction::Fraction(int num, int denom)
				: numerator(num), denominator(denom) {}

			Fraction::Fraction(int num) : Fraction(num, 1) {}

			Fraction::Fraction(const Fraction& other)
			{
				this->numerator = other.numerator;
				this->denominator = other.denominator;
			}

			Fraction& Fraction::operator=(const Fraction& other)
			{
				if (this != &other)
				{
					this->numerator = other.numerator;
					this->denominator = other.denominator;
				}
				return *this;
			}

			Fraction& Fraction::operator=(const int& other)
			{
				numerator = other;
				denominator = 1;
				return *this;
			}

			Fraction Fraction::operator+(const Fraction& other) const
			{
				int newNumerator = numerator * other.denominator
					+ other.numerator * denominator;
				int newDenominator = denominator * other.denominator;

				return Fraction(newNumerator, newDenominator);
			}

			Fraction Fraction::operator+(const int& other) const
			{
				int newNumerator = numerator
					+ other * denominator;
				int newDenominator = denominator;

				return Fraction(newNumerator, newDenominator);
			}

			Fraction operator+(const int& lhs, const Fraction& rhs)
			{
				int newNumerator = lhs * rhs.denominator
					+ rhs.numerator;
				int newDenominator = rhs.denominator;

				return Fraction(newNumerator, newDenominator);
			}

			ostream& operator<<(ostream& cout, const Fraction& rhs)
			{
				cout << rhs.numerator << " / " << rhs.denominator;
				return cout;
			}

			void displayFraction(const Fraction& f)
			{
				cout << f << endl;
			}

			int main()
			{
				Fraction f1(1, 2);
				cout << f1 << endl;

				Fraction f2(2, 3);
				cout << f2 << endl;

				Fraction f3(3, 4);
				cout << f3 << endl;

				f1 = f2 = f3;
				cout << f1 << endl;

				f1 = f2;
				cout << f1 << endl;

				f1 = 1;
				cout << f1 << endl;

				Fraction f4 = f2 + f3;
				cout << f4 << endl;

				Fraction f5 = f2 + 5;
				cout << f5 << endl;

				Fraction f6 = 10 + f2;
				cout << (double)f6 << endl;
				cout << f6 << endl;

				double d = f6;
				cout << d << endl;

				displayFraction(f6);
				displayFraction(2);

				return 0;
			}
		} // namespace Ex3

		namespace freeExPrep
		{
			class Fraction
			{
			public:
				Fraction(int num, int denom)
					: numerator(num), denominator(denom)
				{}

				Fraction& operator=(const Fraction& rhs)
				{
					numerator = rhs.numerator;
					denominator = rhs.denominator;
					return *this;
				}

				void displayFraction(Fraction f)
				{
					cout << f.numerator << " / " << f.denominator << endl;
				}

			private:
				int numerator = 0;
				int denominator = 1;
			};

			int main()
			{
				Fraction f1(1, 3);
				Fraction f2(2, 5);

				return 0;
			}
		}

		namespace freeEx
		{
			class Fraction
			{
			public:
				Fraction(int num, int denom)
					: numerator(num), denominator(denom)
				{}

				explicit Fraction(int num) : Fraction(num, 1) {}

				Fraction& operator=(const Fraction& rhs)
				{
					numerator = rhs.numerator;
					denominator = rhs.denominator;
					return *this;
				}

				Fraction operator+(const Fraction& other) const
				{
					int newNumerator = this->numerator * other.denominator
						+ this->denominator * other.numerator;
					int newDinomenator = this->denominator * other.denominator;

					return Fraction(newNumerator, newDinomenator);
				}

				Fraction operator+(const int& other) const
				{
					Fraction f(other, 1);
					return this->operator+(f);
				}

				friend Fraction operator+(const int& lhs, const Fraction& rhs);
				friend ostream& operator<<(ostream& cout, const Fraction& rhs);

				explicit operator double()
				{
					return (double)numerator / denominator;
				}

			private:
				int numerator = 0;
				int denominator = 1;
			};

			void displayFraction(Fraction f)
			{
				cout << f << endl;
			}

			Fraction operator+(const int& lhs, const Fraction& rhs)
			{
				int newNumerator = lhs * rhs.denominator + rhs.numerator;
				int newDinomenator = rhs.denominator;

				return Fraction(newNumerator, newDinomenator);
			}

			ostream& operator<<(ostream& cout, const Fraction& rhs)
			{
				cout << rhs.numerator << " / " << rhs.denominator;
				return cout;
			}

			int main()
			{
				Fraction f1(1, 2);
				Fraction f2(3, 4);
				Fraction f3 = (Fraction)2;

				f2 = f1 + f3;
				f2 = f1 + 4;
				f2 = 3 + f1;

				displayFraction(f2);
				displayFraction((Fraction)20);

				return 0;
			}
		}
	} // namespace Le13

}; // namespace past

namespace Lec14
{
	namespace Ex1
	{
		void processFile(const string& filename)
		{
			ifstream file;
			file.exceptions(ifstream::failbit | ifstream::badbit);

			try
			{
				cout << "Trying to open the file: " << filename << endl;
				file.open(filename);

				// Process the file
				cout << "Processing file..." << endl;
				// ... file processing logic ...

				file.close();
				cout << "File processed successfully." << endl;
			}
			catch (const ifstream::failure& e)
			{
				cout << "Error occurred: " << e.what() << endl;
				// Handle the file-related error, e.g., by logging it or informing the user
			}
		}

		int main()
		{
			processFile("example.txt");
			return 0;
		}

	}

	namespace Ex2a
	{
		const int SIZE = 10;

		int* readDataFromFile(const string& filename)
		{
			ifstream file(filename);
			int* data = new int[SIZE];
			int value;

			for (int i = 0; i < SIZE; i++)
			{
				file >> data[i];
			}

			return data;
		}

		double calcAvg(const int* data, const int size)
		{
			double sum = 0.0;
			for (int i = 0; i < size; i++)
			{
				sum += data[i];
			}
			return sum / size;
		}

		int main()
		{
			int size;
			int* data = readDataFromFile("input.txt");
			double average = calcAvg(data, SIZE);
			cout << "Average: " << average << endl;

			return 0;
		}
	} // namespace Ex2a

	namespace Ex2b
	{
		const int SIZE = 10;

		int* readDataFromFile(const string& filename)
		{
			ifstream file(filename);
			int* data = new int[SIZE];
			int value;

			if (!file)
			{
				throw string("Failed to open: " + filename);
			}

			for (int i = 0; i < SIZE; i++)
			{
				file >> data[i];
			}

			return data;
		}

		double calcAvg(const int* data, const int size)
		{
			double sum = 0.0;
			for (int i = 0; i < size; i++)
			{
				sum += data[i];
			}
			return sum / size;
		}

		int main()
		{
			try
			{
				int size;
				int* data = readDataFromFile("input.txt");
				double average = calcAvg(data, SIZE);
				cout << "Average: " << average << endl;
			}
			catch (const string& errorMessage)
			{
				cout << "Error: " << errorMessage << endl;
			}

			return 0;
		}
	} // namespace Ex2b

	namespace Ex3
	{
		void checkBookAvailability(int position, int catalogSize)
		{
			if (position < 0 || position >= catalogSize)
			{
				throw out_of_range("Invalid catalog position");
			}
		}

		int getBookIDAtIndex(int* bookIDs, int catalogSize, int position)
		{
			return bookIDs[position];
		}

		int main()
		{
			const int CATALOG_SIZE = 10;
			int bookIDs[CATALOG_SIZE] = { 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };
			int position;

			cout << "Enter the catalog position to query the book ID: ";
			cin >> position;

			//try
			//{
			int bookID = getBookIDAtIndex(bookIDs, CATALOG_SIZE, position);
			cout << "Book ID at position " << position << ": " << bookID << endl;
			//}
			//catch (const out_of_range& e)
			//{
			//	cerr << "Error: " << e.what() << endl;
			//	// Logic to handle invalid position, e.g., asking user to re-enter the position
			//}

			return 0;
		}
	}

	namespace Ex4
	{
		int F1(), F2(), F3();

		int main()
		{
			try
			{
				cout << F1() << endl;
			}
			catch (int e)
			{
				cout << "You are in the main function." << endl;
				cout << "Exception: " << e << endl;
			}
			catch (string e)
			{
				cout << "You are in the main function." << endl;
				cout << "Exception: " << e << endl;
			}

			return 0;
		}

		int F1()
		{
			F2();
			return 1;
		}

		int F2()
		{
			F3();
			return 2;
		}

		int F3()
		{
			throw string("Error in F3()");
			return 3;
		}
	} // namespace Ex4

	namespace Ex5
	{
		int F1(), F2(), F3();

		int main()
		{
			try
			{
				cout << F1() << endl;
			}
			catch (int e)
			{
				cout << "You are in the main function." << endl;
				cout << "Exception: " << e << endl;
			}
			catch (string e)
			{
				cout << "You are in the main function." << endl;
				cout << "Exception: " << e << endl;
			}

			return 0;
		}

		int F1()
		{
			try
			{
				F2();
			}
			catch (string e)
			{
				cout << "You are in F1()." << endl;
				cout << "Exception: " << e << endl;
				throw string("Error in F1()");
			}
			return 1;
		}

		int F2()
		{
			try
			{
				F3();
			}
			catch (string e)
			{
				cout << "You are in F2()." << endl;
				cout << "Exception: " << e << endl;
				throw;
			}
			return 2;
		}

		int F3()
		{
			throw string("Error in F3()");
			return 3;
		}
	} // namespace Ex5
}

int main()
{
	Lec14::Ex5::main();
	return 0;
}