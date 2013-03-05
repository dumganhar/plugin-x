#ifndef __SIMPLE_CLASS_H__
#define __SIMPLE_CLASS_H__

#include <string>
#include <stdint.h>

enum someThingEnumerated {
	kValue1 = 1,
	kValue2,
	kValue3,
	kValue4
};

class SimpleNativeClass;

class MyCallbackDelegate
{
public:
	virtual void onCallback(SimpleNativeClass* cls, int arg) = 0;
};

class SimpleNativeClass
{
protected:
	int m_someField;
	int m_someOtherField;
	char* m_anotherMoreComplexField;

public:
    SimpleNativeClass();
	SimpleNativeClass(int m) : m_someField(m) {};
	SimpleNativeClass(int m1, int m2) : m_someField(m1), m_someOtherField(m2) {};
	SimpleNativeClass(std::string m1, float m2 = 0.0f) : m_someField(1), m_someOtherField(2) {};
	~SimpleNativeClass();


	// these methods are simple, can be defined inline
	int getSomeField() {
		return m_someField;
	}
	int getSomeOtherField() {
		return m_someOtherField;
	}
	const char *getAnotherMoreComplexField() {
		return m_anotherMoreComplexField;
	}
	void setSomeField(int f) {
		m_someField = f;
	}

	void setSomeField(double d, float a, const char* f = "Hello Default Argument.", int ccc=1) {
		printf("%lf, %s\n",d, f);
	}

	void setSomeField() {

	}
	void setSomeOtherField(int f) {
		m_someOtherField = f;
	}

	virtual void virtualFoo()
	{
		fprintf(stderr, "%s\n", "parent foo");
	}
	void setAnotherMoreComplexField(const char *str);

	long long thisReturnsALongLong();

	static void func();
	static void func(int a);
	static void func(int a, float b);

	long long receivesLongLong(long long someId);
	std::string returnsAString();
	const char *returnsACString();

	int doSomeProcessing(std::string arg1, std::string arg2);

	static int static_func_overroad() {
		return 1;
	}

	static int static_func_overroad(int a) {
		return 2;
	}

	static int static_func_overroad(std::string a) {
		return 3;
	}

	static int static_func_overroad(int a, const char* b) {
		return 4;
	}

	static int static_func_overroad(bool a, int b) {
		return 5;
	}

	static int static_func(int a, std::string b = "hello") {
		printf("static_func: %d, %s\n", a, b.c_str());
		return 6;
	}

	int instance_func_overroad() {
		return 11;
	}

	// int instance_func_overroad(int a) {
	// 	return 12;
	// }

	int instance_func_overroad(std::string a) {
		return 13;
	}

	int instance_func_overroad(int a, const char* b = "Hi....") {
		printf("instance_func_overroad: %d, %s\n", a, b);
		return 14;
	}

	int instance_func_overroad(bool a, int b) {
		return 15;
	}

	int instance_func(int a, std::string b = "hello") {
		printf("instance_func: %d, %s\n", a, b.c_str());
		return 16;
	}
	// static int static_func() {
	// 	return 1;
	// }
	// void setDelegate(MyCallbackDelegate* pDelegate)
	// {
	// 	m_pDelegate = pDelegate;
	// }

// 	void invokeDelegate()
// 	{
// 		if (m_pDelegate) {
// 			m_pDelegate->onCallback(this, 1111222233);
// 		}
// 	}
// private:
// 	MyCallbackDelegate* m_pDelegate;
};

class SubClass : public SimpleNativeClass
{
public:
	virtual void virtualFoo()
	{
		fprintf(stderr, "%s\n", "sub foo");
	}

	void hello()
	{
		fprintf(stderr, "%s\n", "I'm hello");
	}
	std::string foo(int a)
	{
		return "abc";
	}
};

namespace SomeNamespace {
class AnotherClass {
protected:
	int justOneField;

public:
	int aPublicField;

	AnotherClass();
	virtual ~AnotherClass();

	// also simple methods, can be defined inline
	int getJustOneField() {
		return justOneField;
	}
	// wrong setter - won't work (needs ONLY one parameter in order to work)
	void setJustOneField() {
		justOneField = 999;
	}

	void doSomethingSimple();
};
};

#endif
