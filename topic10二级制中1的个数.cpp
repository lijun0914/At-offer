#include <iostream>
using namespace std;
/*
	��򵥵�ʵ��
	����n=n&(n-1)����ʵ��������һλ1�Ĳ���
	���� 1 1 0 0 0 & 1 0 1 1 1=1 0 0 0 0 
*/
int numOfOne(int n){
	int count=0;
	while(n){
		count++;
		n=n&(n-1);
	}
	return count;
}
/*
	��ʵN�����������λ�������޵ģ�����ʱ��Ч��Ӧ����O��1����
	������һ���Ż�
	0x5 Ϊ 0101 �ⲽ����ʵ�ְ�ÿ��λ��1��� �洢��2λ�Ŀռ���
	0x3 Ϊ 0011 ÿ��λ��1-����λ
	�������� 
*/
int hamming(unsigned int n){
	//01010101 put count of 2 bits into those 2 bits
	n=(n&0x55555555)+(n>>1&0x55555555);
	n=(n&0x33333333)+(n>>2&0x33333333);
	n=(n&0x0F0F0F0F)+(n>>4&0x0F0F0F0F);
	n=(n&0x00FF00FF)+(n>>8&0x00FF00FF);
	n=(n&0xFFFFFFFF)+(n>>16&0xFFFFFFFF);
	return n;
}
/*
	��������Ƕ����溯���Ľ�һ���Ż�
	�����м���� 
*/
int hammingWeight(uint32_t n)
{
    n -= (n >> 1) & 0x55555555; //put count of each 2 bits into those 2 bits
    n = (n & 0x33333333) + (n >> 2 & 0x33333333); //put count of each 4 bits into those 4 bits
    n = (n + (n >> 4)) & 0x0F0F0F0F; //put count of each 8 bits into those 8 bits
    n += n >> 8; // put count of each 16 bits into those 8 bits
    n += n >> 16; // put count of each 32 bits into those 8 bits
    return n & 0xFF;
}
// This uses fewer arithmetic operations than any other known implementation on machines with fast multiplication.
// It uses 12 arithmetic operations, one of which is a multiply.
/*
	�����һ���Ż�
	����������ͳ�һ�� 
*/
int hammingWeight2(uint32_t n)
{
    n -= (n >> 1) & 0x55555555; // put count of each 2 bits into those 2 bits
    n = (n & 0x33333333) + (n >> 2 & 0x33333333); // put count of each 4 bits into those 4 bits
    n = (n + (n >> 4)) & 0x0F0F0F0F; // put count of each 8 bits into those 8 bits 
    return n * 0x01010101 >> 24; // returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24)
}
int main(){
	cout<<numOfOne(9)<<endl;
	cout<<numOfOne(255)<<endl;
	cout<<hamming(255)<<endl;
}