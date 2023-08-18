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
		static T instance;//调用了T的构造函数，T的构造函数又是私有的，所以通过友元的方式达成调用
		//对于T类型来讲除了T类型自己以外只有Singleton<T> 类型可以访问T的构造函数
		return instance;
	}
private:
};

//定义代码段来实现T类型的单例特性

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