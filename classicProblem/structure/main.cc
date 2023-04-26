#include <iostream>
using namespace std;
class Triangle
{
	public:
		Triangle(int a,int b,int c)          //有参构造           
		{
			this->a=a;
			this->b=b;
			this->c=c;
			cout<<"有参构造"<<endl;
		}
		Triangle(Triangle &obj)                 //拷贝构造
		{
			a=obj.a;                 //通过目标对象对每个成员变量赋值
			b=obj.b;
			c=obj.c;
			cout<<"拷贝构造"<<endl;
		} 
		void getValue()                   //成员函数
		{
			cout<<"a="<<a<<endl;
			cout<<"b="<<b<<endl;
			cout<<"c="<<c<<endl;
		}
 
		private:
			int a;
			int b;
			int c;
};
int main()
{
	Triangle A(3,4,5);                    //A调用了有参构造
	Triangle B(A);                        //B调用了拷贝构造
	B.getValue();
}
