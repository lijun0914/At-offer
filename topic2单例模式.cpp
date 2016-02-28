/*
	设计一个类，我们只能生成该类的一个实例 
	即单例模式 
*/
#include<iostream>
using namespace std;
/*
	一般的单例模式没有考虑到线程安全。
	需要lock，unlock保证多线程安全，同时使用双重锁
	类似下面代码，减少锁的使用 
		if(x!=NULL){
			lock();
			if(x!=NULL)
			{
			}
			unlock();
		}
	实现上分为饿汉和懒汉模式，饿汉就是开始就初始化，并不等到需要构造的时候。
	懒汉在自己构建的时候才初始化变量。
		
	下面的实现为懒汉模式，只有在需要的时候才构建。
	同时局部静态变量的初始化保证了线程安全。
	避免了lock unlock带来的性能损失。 
	
	如果在饿汉基础上，想要使用new并自己管理内存回收，需要自己构建一个内部类。
	大致如下：
	class Singleton
{
public:
	static Singleton *GetInstance()
	{
		return m_Instance;
	}

	int GetTest()
	{
		return m_Test;
	}

private:
	Singleton(){ m_Test = 10; }
	static Singleton *m_Instance;
	int m_Test;

	// This is important
	class GC
	{
	public :
		~GC()
		{
			// We can destory all the resouce here, eg:db connector, file handle and so on
			if (m_Instance != NULL )
			{
				cout<< "Here is the test" <<endl;
				delete m_Instance;
				m_Instance = NULL ;
			}
		}
	};
	static GC gc;
};

Singleton *Singleton ::m_Instance = new Singleton();
Singleton ::GC Singleton ::gc; 
*/
class Single{
	public:
		static Single* newInsance(){
			static Single instance;
			return &instance;
		}
		int test(){
			return number;
		}
	private:
		Single(){ number=1; }
		//static Single* instance;
		int number;
			
};
//Single* Single::instance=new Single();
int main(){
	Single* s1=Single::newInsance();
	cout<<(s1->test())<<endl;
	
	s1=Single::newInsance();
	cout<<(s1->test())<<endl;
	return 0;
}
