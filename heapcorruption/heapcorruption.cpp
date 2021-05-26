#include<iostream>
#include<cstring>
using namespace std;
class MyString{
	char *ptr;
public:
	int size()const{
		return strlen(ptr);
	}
	MyString(){
		ptr=new char[1];
		ptr[0]='\0';
	}
	MyString(const char *p){
		ptr=new char[strlen(p)+1];
		strcpy(ptr,p);
	}
	MyString(const MyString &str){
		ptr=new char[str.size()+1];
		strcpy(ptr,str.ptr);
	}
	~MyString(){
		delete []ptr;
	}
	friend ostream& operator<<(ostream& out, const MyString& str);
	friend MyString operator+(const MyString& s1, const MyString& s2);
	friend int operator==(const MyString& s1, const MyString& s2);
	friend int operator!=(const MyString& s1, const MyString& s2);
	friend int operator<(const MyString& s1, const MyString& s2);
	friend int operator<=(const MyString& s1, const MyString& s2);
	friend int operator>(const MyString& s1, const MyString& s2);
	friend int operator>=(const MyString& s1, const MyString& s2);
	MyString& operator=(const MyString& s);
	MyString& operator+=(const MyString& s);
	char operator[](int i);
};
ostream& operator<<(ostream& out, const MyString& str) {
	cout << str.ptr ;
return out;
}
MyString operator+(const MyString& s1, const MyString& s2) {
	return MyString(strcat(s1.ptr, s2.ptr));
}
int operator==(const MyString& s1, const MyString& s2) {
	if (s1.ptr == s2.ptr)
		return 1;
	else
		return 0;
}
int operator!=(const MyString& s1, const MyString& s2) {
	if (s1.ptr == s2.ptr)
		return 0;
	else
		return 1;
}
int operator<(const MyString& s1, const MyString& s2) {
	if (strcmp(s1.ptr, s2.ptr) < 0)
		return 1;
	else
		return 0;
}

int operator<=(const MyString& s1, const MyString& s2) {
	if (strcmp(s1.ptr, s2.ptr) <= 0)
		return 1;
	else
		return 0;


}
int operator>(const MyString& s1, const MyString& s2) {
	if (strcmp(s1.ptr, s2.ptr) > 0)
		return 1;
	else
		return 0;


}
int operator>=(const MyString& s1, const MyString& s2) {
	if (strcmp(s1.ptr, s2.ptr) >= 0)
		return 1;
	else
		return 0;

}
MyString& MyString::operator=(const MyString& s) {
	ptr = s.ptr;
	return *this;
}
MyString& MyString:: operator+=(const MyString& s) {
	ptr = strcat(ptr, s.ptr);
	return (*this);
}
char MyString::operator[](int i) {
	return ptr[i];
}

int main() 
{
	MyString s1("Hello"), s2("World"), s3("China");
	MyString s4 = s1 + s2;
	cout << s4 << endl;
	s4 += s3;
	cout << s4;
	cout << endl;
	return 0;
}