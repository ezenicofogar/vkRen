// PROJECT
#include <vkr/Utils/FileManager.hpp>

// LIBRARIES

// STD
#include <fstream>

namespace vkr
{

	ReadFile::ReadFile(const char* _fn) : _raw{ nullptr }, _size{ 0U }
	{

		// OPEN FILE
		std::fstream file{};
		file.open(_fn, std::fstream::in | std::fstream::binary | std::fstream::ate);
		if (!file.is_open()) return;

		// GET SIZE
		_size = file.tellg();

		// ALLOCATE MEMORY
		_raw = new char[_size];

		// READ
		file.seekg(0);
		file.read(_raw, _size);

		// CLOSE
		file.close();
		
	}

	ReadFile::~ReadFile()
	{
		if (_raw)
			delete[] _raw;
	}

	ReadFile::ReadFile(const ReadFile& _o) : _raw{ nullptr }, _size{ _o._size }
	{
		if (!_size) return;

		// ALLOCATE MEMORY
		_raw = new char[_size];

		// COPY CONTENTS
		std::memcpy(_raw, _o._raw, _size);
	}

	const char* const ReadFile::getData() const
	{
		return _raw;
	}

	const size_t ReadFile::getSize() const
	{
		return _size;
	}

}
