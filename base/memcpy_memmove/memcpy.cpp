#include<iostream>
#include "assert.h"
// 1 2 3 4 5 x x x
// src   dst
// x x x 1 2 3 4 5
// dst   src

void *my_memmove(void *dst, const void *src, size_t n) {
    char *tmp_dst;
    char *tmp_src;
    tmp_dst = (char *) dst;
    tmp_src = (char *) src;
    if (tmp_src < tmp_dst && tmp_src + n > tmp_src) {//第一种情形
        tmp_dst += n - 1;
        tmp_src += n - 1;
        while (n--) {
            *tmp_dst-- = *tmp_src--;
        }
    } else {
        while (n--) {
            *tmp_dst++ = *tmp_src++;
        }
    }
    return dst;
}

//================================
void *memset(void *s, int c, unsigned int n) {
    assert(NULL != s);
    void *tmp = s;
    while (n-- > 0) {
        *(char *) tmp = char(c);
        tmp = (char *) tmp + 1;
    }
    return s;
}

void *memcpy(void *dst, const void *src, size_t n) {
    assert(NULL != dst && NULL != src);
    int i = 0;
    void *tmp = dst;
    while (i < n) {
        *((char *) tmp + i) = *((char *) src + i);
        i++;
    }
    return dst;
}

char *strcpy(char *dst, const char *src) {
    assert(NULL != dst && NULL != src);
    char *tmp = dst;
    while ((*tmp++ = *src++) != '\0');
    return dst;
}

char *strncpy(char *dst, const char *src, unsigned int n) {
    assert(NULL != dst && NULL != src);
    char *tmp = dst;
    while ((n-- > 0) && (*tmp++ = *src++) != '\0');
    while (n-- > 0) {
        *tmp++ = '\0';
    }
    return dst;
}

int strcmp(const char *str1, const char *str2) {
    assert(NULL != str1 && NULL != str2);
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

char *strcat(char *dst, const char *src) {
    assert(NULL != dst && NULL != src);
    char *tmp = dst;
    while (*tmp != '\0') {
        tmp++;
    }
    while ((*tmp++ = *src++) != '\0');
    return dst;
}

unsigned int strlen(const char *s) {
    assert(NULL != s);
    unsigned int len = 0;
    while (*s++ != '\0') {
        len++;
    }
    return len;
}
