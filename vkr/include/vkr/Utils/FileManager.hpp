#pragma once
#include <vkr/API.hpp>

namespace vkr
{

	class VKR_API ReadFile
	{
		char* _raw;
		size_t _size;
	public:
		// BASE
		ReadFile(const char* _filename);
		~ReadFile();

		// COPY
		ReadFile(const ReadFile&);
		ReadFile& operator=(const ReadFile&) = delete;

		// MOVE
		ReadFile(ReadFile&&) = default;
		ReadFile& operator=(ReadFile&&) = default;

		// FUNCTIONS
		const char* const getData() const;
		const size_t getSize() const;
	};

}
