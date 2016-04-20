/*
	用C++设计一个不能被继承的类 
*/
/*
	讲构造函数设置为私有
	通过静态函数返回堆上的实例 
*/
class sealClass1{
	public:
		static sealClass1* getInstance(){
			return new sealClass1();
		}
		static void deleteInstance(sealClass1* pInstance){
			delete pInstance;
		}
	private:
		sealClass1(){}
		~sealClass1(){}
};
/*
	暂时不支持模板作为友元 
*/
template <typename T> class makeSeal{
	friend T;
private:
	makeSeal(){}
	~makeSeal()	{}
};
class sealClass2:virtual public makeSeal<sealClass2>{
	public:
		sealClass2(){	
		}
		~sealClass2(){	
		}
};
class Try:public sealClass2{
	public:
		Try(){
			
		}	;
	
};
int main(){
	sealClass2 a;
//	Try b();
}