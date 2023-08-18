#pragma once
#ifndef __MY_SINGLETON_TEMPLATE_H__
#define __MY_SINGLETON_TEMPLATE_H__


template<typename T>
class Singleton
{
protected:
	Singleton() = default;
public:
	static T& instance()
	{
		static T instance;//������T�Ĺ��캯����T�Ĺ��캯������˽�еģ�����ͨ����Ԫ�ķ�ʽ��ɵ���
		//����T������������T�����Լ�����ֻ��Singleton<T> ���Ϳ��Է���T�Ĺ��캯��
		return instance;
	}
private:
};

//����������ʵ��T���͵ĵ�������

#define PRIVATE_CONSTRUCTOR_AND_COPY(t)\
private:\
	t(const t&)=delete;\
	t& operator = (const t&)=delete;\
	t() = default;\
	friend class Singleton<t>;

#define PRIVATE_COPY(t)\
private:\
	t(const t&)=delete;\
	t& operator = (const t&)=delete;\
	friend class Singleton<t>;

#endif