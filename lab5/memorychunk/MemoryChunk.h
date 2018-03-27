//
// Created by pakakrzy on 27.03.18.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <algorithm>
#include <cstdint>
using namespace std;

namespace memorychunk {
    class MemoryChunk {
    public:

        MemoryChunk(size_t param);

        MemoryChunk(const MemoryChunk & other);

        MemoryChunk(MemoryChunk && other);

        MemoryChunk &operator=(const MemoryChunk & other);

        MemoryChunk &operator=(MemoryChunk && other);

        ~MemoryChunk();



        int8_t* MemoryAt(size_t offset) const;


        size_t ChunkSize() const;

    private:
        int8_t* pointer;
        size_t size;
    };
}


#endif //JIMP_EXERCISES_MEMORYCHUNK_H
