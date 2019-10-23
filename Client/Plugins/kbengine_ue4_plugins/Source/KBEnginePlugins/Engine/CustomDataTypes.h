/*
	Generated by KBEngine!
	Please do not modify this file!
	tools = kbcmd
*/

#pragma once
#include "KBECommon.h"
#include "KBETypes.h"
#include "MemoryStream.h"
#include "Bundle.h"
#include "DataTypes.h"
namespace KBEngine
{


class KBENGINEPLUGINS_API DATATYPE_AVATAR_DATA : DATATYPE_BASE
{
public:
	void createFromStreamEx(MemoryStream& stream, AVATAR_DATA& datas);
	void addToStreamEx(Bundle& stream, const AVATAR_DATA& v);
};


class KBENGINEPLUGINS_API DATATYPE_AVATAR_INFO : DATATYPE_BASE
{
public:
	void createFromStreamEx(MemoryStream& stream, AVATAR_INFO& datas);
	void addToStreamEx(Bundle& stream, const AVATAR_INFO& v);
};


class KBENGINEPLUGINS_API DATATYPE_AVATAR_INFO_LIST : DATATYPE_BASE
{
public:
	class KBENGINEPLUGINS_API DATATYPE__AVATAR_INFO_LIST_values_ArrayType_ChildArray : public DATATYPE_BASE
	{
	public:
		DATATYPE_AVATAR_INFO itemType;

		void createFromStreamEx(MemoryStream& stream, TArray<AVATAR_INFO>& datas)
		{
			uint32 size = stream.readUint32();
			while(size > 0)
			{
				--size;
				itemType.createFromStreamEx(stream, datas.EmplaceAt_GetRef(datas.Num()));
			};

		}

		void addToStreamEx(Bundle& stream, const TArray<AVATAR_INFO>& v)
		{
			stream.writeUint32((uint32)v.Num());
			for(int i=0; i<v.Num(); ++i)
			{
				itemType.addToStreamEx(stream, v[i]);
			};
		}
	};

	DATATYPE__AVATAR_INFO_LIST_values_ArrayType_ChildArray values_DataType;

	void createFromStreamEx(MemoryStream& stream, AVATAR_INFO_LIST& datas);
	void addToStreamEx(Bundle& stream, const AVATAR_INFO_LIST& v);
};


}