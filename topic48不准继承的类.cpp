/*
	��C++���һ�����ܱ��̳е��� 
*/
/*
	�����캯������Ϊ˽��
	ͨ����̬�������ض��ϵ�ʵ�� 
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
	��ʱ��֧��ģ����Ϊ��Ԫ 
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