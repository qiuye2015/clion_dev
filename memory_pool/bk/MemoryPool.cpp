//
// Created by jianpeng10 on 2021/12/27 0027.
//

#include <malloc.h>
#include <stdio.h>
#include "MemoryPool.h"

//内存对齐长度
#define MEMPOOL_ALIGNMENT 4


MemoryPool *memory_pool_create(unsigned int init_size, unsigned int grow_size, unsigned int size) {
    MemoryPool *mp;
    mp = (MemoryPool *) malloc(sizeof(MemoryPool));
    mp->first_block = nullptr;
    mp->init_size = init_size;
    mp->grow_size = grow_size;

    if (size < sizeof(unsigned int))
        mp->obj_size = sizeof(unsigned int);
    // 内存对齐, 取整到大于size的最大的MEMPOOL_ALIGNMENT的倍数
    mp->obj_size = (size + (MEMPOOL_ALIGNMENT - 1)) & ~(MEMPOOL_ALIGNMENT - 1);

    return mp;
}


void free_memory_pool(MemoryPool *mp) {
    MemoryBlock *mb = mp->first_block;

    if (mb != nullptr) {
        while (mb->next != nullptr) {
            MemoryBlock *delete_block = mb;
            mb = mb->next;
            free(delete_block);
        }
        free(mb);
    }
    free(mp);
}


void *memory_alloc(MemoryPool *mp) {
    unsigned int i;
    unsigned int length;

    if (mp->first_block == nullptr) {
        MemoryBlock *mb;
        length = (mp->init_size) * (mp->obj_size) + sizeof(MemoryBlock);
        mb = (MemoryBlock *) malloc(length);
        if (mb == nullptr) {
            perror("memory allocate failed!\n");
            return nullptr;
        }

        /* init the first block */
        mb->next = nullptr;
        mb->free_size = mp->init_size - 1;
        mb->first_free = 1;
        mb->size = mp->init_size * mp->obj_size;

        mp->first_block = mb;

        char *data = mb->a_data;

        /* set the mark */
        for (i = 1; i < mp->init_size; ++i) {
            *(unsigned long *) data = i;
            data += mp->obj_size;
        }

        return (void *) mb->a_data;
    }

    MemoryBlock *pm_block = mp->first_block;

    while ((pm_block != nullptr) && (pm_block->free_size == 0)) {
        pm_block = pm_block->next;
    }

    if (pm_block != nullptr) {
        char *pfree = pm_block->a_data + pm_block->first_free * mp->obj_size;

        pm_block->first_free = *((unsigned long *) pfree);
        pm_block->free_size--;

        return (void *) pfree;
    } else {
        if (mp->grow_size == 0)
            return nullptr;

        MemoryBlock *new_block = (MemoryBlock *) malloc((mp->grow_size) * (mp->obj_size) + sizeof(MemoryBlock));

        if (new_block == nullptr)
            return nullptr;

        char *data = new_block->a_data;

        for (i = 1; i < mp->grow_size; ++i) {
            *(unsigned long *) data = i;
            data += mp->obj_size;
        }

        new_block->size = mp->grow_size * mp->obj_size;
        new_block->free_size = mp->grow_size - 1;
        new_block->first_free = 1;
        new_block->next = mp->first_block;
        mp->first_block = new_block;

        return (void *) new_block->a_data;
    }
}


void *memory_free(MemoryPool *mp, void *pfree) {
    if (mp->first_block == nullptr) {
        return nullptr;
    }

    MemoryBlock *pm_block = mp->first_block;
    MemoryBlock *pm_pre_block = mp->first_block;

    /* research the MemoryBlock which the pfree in */
    while (pm_block &&(
            (unsigned int) pfree < (unsigned int) pm_block->a_data ||
            (unsigned int) pfree > ((unsigned int) pm_block->a_data + pm_block->size)
            )
            ) {
        //pm_pre_block = pm_block;
        pm_block = pm_block->next;

        if (pm_block == nullptr) {
            return pfree;
        }
    }

    unsigned int offset = pfree - (void *) pm_block->a_data;

    if ((offset & (mp->obj_size - 1)) > 0) {
        return pfree;
    }

    pm_block->free_size++;
    *((unsigned int *) pfree) = pm_block->first_free;

    pm_block->first_free = (unsigned int) (offset / mp->obj_size);

    return nullptr;
}