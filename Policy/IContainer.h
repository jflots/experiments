#pragma once

template <typename T>
class IContainer
{
public:
	virtual T* Ptr() = 0;
	virtual unsigned int Size() = 0;

	T* First() { return Ptr(); }
	T* Last() { return Ptr() + Size() - 1; }

};

template <typename T>
class ICallbackContainer
{
public:
	typedef T* (ICallbackContainer::*PtrCallback)();

	PtrCallback m_cbCallback = nullptr;
	
	virtual unsigned int Size() = 0;

	T* First() { return (*m_cbCallback)(); }
	T* Last() { return (*m_cbCallback()) + Size() - 1; }

};