#pragma once

namespace SOGL
{
	enum class DataType
	{
		Byte,
		UnsignedByte,
		Short,
		UnsignedShort,
		Int,
		UnsignedInt,
		Fixed,
		HalfFloat,
		Float,
		Double
	};

	unsigned remap(const DataType& type);
};