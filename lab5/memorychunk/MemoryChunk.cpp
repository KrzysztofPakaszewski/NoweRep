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
    pointer = new int8_t[other.ChunkSize()];
    for(int a = 0;a< other.ChunkSize();a++)
    {
        pointer[a] = other.pointer[a];
    }
    size = other.ChunkSize();
}

MemoryChunk::MemoryChunk(MemoryChunk && other) {
    pointer =other.pointer;
    size = other.ChunkSize();
    other.size = 0;
    other.pointer= nullptr;
}

MemoryChunk& MemoryChunk ::operator=(const MemoryChunk & other)
{
    if(this == &other)
        return *this;
    delete[] pointer;
    pointer = new int8_t[other.ChunkSize()];
    for(int a = 0;a< other.ChunkSize();a++)
    {
        pointer[a] = other.pointer[a];
    }
    size = other.ChunkSize();
}

MemoryChunk& MemoryChunk::operator=(MemoryChunk && other)
{
    if(this == &other)
        return *this;
    delete[] pointer;
    pointer =other.pointer;
    size = other.ChunkSize();
    other.size = 0;
    other.pointer= nullptr;
}

MemoryChunk::~MemoryChunk()
{
    delete[] pointer;
}



int8_t* MemoryChunk::MemoryAt(size_t offset) const
{
    if(pointer == nullptr)
        return nullptr;
    if(offset >= this->size || offset<0)
        return nullptr;
    return &this->pointer[offset];

}


size_t MemoryChunk::ChunkSize() const
{
    return size;
}