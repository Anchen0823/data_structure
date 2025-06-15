#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <immintrin.h>

#define IDENT 0
#define OP +
#define data_t int

typedef struct{
    size_t len;
    data_t *data;
} vec;

void combine(vec *v, data_t *dest)
{
    // 高性能 AVX2 版本，8 个 int 一组，双累加器，最后水平归约
    size_t n = v->len;
    data_t *data = v->data;
    size_t i = 0;

    // 两个累加寄存器，减少依赖链
    __m256i sum0 = _mm256_setzero_si256();
    __m256i sum1 = _mm256_setzero_si256();

    // 主循环：每次处理 16 个元素
    for (; i + 16 <= n; i += 16) {
        __m256i v0 = _mm256_loadu_si256((__m256i*)(data + i));
        __m256i v1 = _mm256_loadu_si256((__m256i*)(data + i + 8));
        sum0 = _mm256_add_epi32(sum0, v0);
        sum1 = _mm256_add_epi32(sum1, v1);
    }
    // 处理剩下的 8 个元素
    for (; i + 8 <= n; i += 8) {
        __m256i v0 = _mm256_loadu_si256((__m256i*)(data + i));
        sum0 = _mm256_add_epi32(sum0, v0);
    }

    // 将两个向量累加合并
    sum0 = _mm256_add_epi32(sum0, sum1);

    // 水平归约到标量
    data_t tmp[8];
    _mm256_storeu_si256((__m256i*)tmp, sum0);
    data_t total = tmp[0] + tmp[1] + tmp[2] + tmp[3] + tmp[4] + tmp[5] + tmp[6] + tmp[7];

    // 处理剩余元素
    for (; i < n; ++i) {
        total += data[i];
    }

    *dest = total;
}
