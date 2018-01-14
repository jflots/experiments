#pragma once

#include "IContainer.h"

template <typename T>
class MultiContainer : public IContainer<T>
{

private:
	T* m_pData;
	unsigned int m_uiSize;

public:
	MultiContainer() : m_pData(nullptr), m_uiSize(0) {}

	virtual ~MultiContainer()
	{
		delete[] m_pData;
	}

	inline virtual T* Ptr() override { return m_pData; }

	inline virtual unsigned int Size() override { return m_uiSize; }

	void Allocate(unsigned int size) {
		m_pData = new T[size]; m_uiSize = size;
	}

};


//template <typename T>
//class MultiCallbackContainer : public ICallbackContainer<T>
//{
//private:
//	T* m_pData;
//	unsigned int m_uiSize;
//
//public:
//	MultiCallbackContainer() : m_pData(nullptr), m_uiSize(0) { m_cbCallback=&MultiCallbackContainer::Ptr;}
//
//	virtual ~MultiCallbackContainer()
//	{
//		delete[] m_pData;
//	}
//
//	 T* Ptr() { return m_pData; }
//
//	virtual unsigned int Size() override { return m_uiSize; }
//
//	void Allocate(unsigned int size) 
//	{
//		m_pData = new T[size]; m_uiSize = size;
//	}
//
//};

template <typename T>
class MultiContainerReal
{

private:
	T* m_pData;
	unsigned int m_uiSize;

public:
	MultiContainerReal() : m_pData(nullptr), m_uiSize(0) {}

	 ~MultiContainerReal()
	{
		delete[] m_pData;
	}

	 T* Ptr()  { return m_pData; }
	 
	 unsigned int Size() {return m_uiSize;}

	 T* First() { return Ptr(); }
	 T* Last() { return Ptr() + Size() - 1; }

	void Allocate(unsigned int size) {
		m_pData = new T[size]; m_uiSize = size;
	}

};
