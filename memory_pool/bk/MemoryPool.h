//
// Created by jianpeng10 on 2021/12/27 0027.
//

#ifndef CLION_DEV_MEMORYPOOL_H
#define CLION_DEV_MEMORYPOOL_H

struct MemoryBlock {
    unsigned int size;       // 为MemoryBlock下内存块的个数
    unsigned int free_size;  // 为MemoryBlock下空闲内存块的个数
    unsigned int first_free; // 为MemoryBlock中第一个空闲块的索引

    struct MemoryBlock *next;// 指向下一个MemoryBlock
    char a_data[0];          // 是一个柔性数组: 数组大小待定的数组
    // C语言中结构体的最后一个元素可以是大小未知的数组，也就是所谓的0长度，所以我们可以用结构体来创建柔性数组
    // 它的主要用途是为了满足需要变长度的结构体，为了解决使用数组时内存的冗余和数组的越界问题。
};

struct MemoryPool {
    unsigned int obj_size;  // 为内存池分配的固定内存块的大小
    unsigned int init_size; // 初始化内存池时候创建的内存块的个数
    unsigned int grow_size; // 当初始化内存块使用完后，再次申请内存块时候的个数

    MemoryBlock *first_block; // 指向第一个MemoryBlock
};

//创建一个MemoryPool，并对其进行初始化，下面是参数说明：
//init_size 表示第一个MemoryBlock中创建块的个数
//grow_size 表示当MemoryPool中没有空闲块可用，则创建一个新的MemoryBlock时其块的个数
//size 为块的大小(即每次分配相同大小的固定size)
MemoryPool *memory_pool_create(unsigned int init_size,
                               unsigned int grow_size,
                               unsigned int size);

//释放内存池
void free_memory_pool(MemoryPool *mp);

//从mp中申请一块内存返回
//mp 为MemoryPool类型指针，即内存池的头
//如果内存分配失败，则返回NULL
void *memory_alloc(MemoryPool *mp);

//释放内存
//mp 为MemoryPool类型指针，即内存池的头
//pfree 为要释放的内存

void *memory_free(MemoryPool *mp, void *pfree);

#endif //CLION_DEV_MEMORYPOOL_H
