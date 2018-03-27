//
// Created by pakakrzy on 27.03.18.
//

#include "MemoryChunk.h"

using namespace memorychunk;


MemoryChunk::MemoryChunk(size_t param)
{
    pointer = new int8_t[param];
    size = param;
}

MemoryChunk::MemoryChunk(const MemoryChunk & other)
{
    delete[] pointer;
    pointer = new int8_t[other.ChunkSize()];
    *pointer= *other.pointer;
    size = other.ChunkSize();
}

MemoryChunk::MemoryChunk(MemoryChunk & other) {
    delete[] pointer;
    pointer = new int8_t[other.ChunkSize()];
    *pointer =*other.pointer;
    size = other.ChunkSize();
    other.size = 0;
    other.pointer = nullptr;
}

MemoryChunk& MemoryChunk ::operator=(const MemoryChunk & other)
{
    delete[] pointer;
    pointer = new int8_t[other.ChunkSize()];
    *pointer= *other.pointer;
    size = other.ChunkSize();
}

MemoryChunk& MemoryChunk::operator=(MemoryChunk & other)
{
    delete[] pointer;
    pointer = new int8_t[other.ChunkSize()];
    *pointer =*other.pointer;
    size = other.ChunkSize();
    other.size = 0;
    other.pointer = nullptr;
}

MemoryChunk::~MemoryChunk()
{
    delete[] pointer;
}



int8_t* MemoryChunk::MemoryAt(size_t offset) const
{
    if(offset >= this->size)
        return nullptr;
    return this->pointer+offset;

}


size_t MemoryChunk::ChunkSize() const
{
    return size;
}