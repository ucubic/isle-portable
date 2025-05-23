#ifndef MXCOLLECTION_H
#define MXCOLLECTION_H

#include "mxcore.h"

template <class T>
class MxCollection : public MxCore {
public:
	MxCollection()
	{
		m_count = 0;
		SetDestroy(Destroy);
	}

	virtual MxS8 Compare(T, T) { return 0; } // vtable+0x14

	~MxCollection() override {}

	static void Destroy(T) {}

	void SetDestroy(void (*p_customDestructor)(T)) { this->m_customDestructor = p_customDestructor; }

protected:
	MxU32 m_count;                 // 0x08
	void (*m_customDestructor)(T); // 0x0c
};

#endif // MXCOLLECTION_H
