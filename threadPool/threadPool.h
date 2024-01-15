#ifndef __THREAD_POOL_H_
#define __THREAD_POOL_H_

#include <pthread.h>

typedef struct task_t
{
    /* 回调函数 */
    void *(woker_Hander)(void *arg);
    /* 参数 */
    void *arg;
}task_t;

/* 线程池结构体 */
typedef struct threadpool_t
{
    /* 任务队列 */
    task_t * taskQueue;
    /* 队列容量 */
    int queueCapacity;
    /* 任务队列的任务数 */
    int queueSize;
    /* 任务队列的队头 */
    int queueFront;
    /* 任务队列的队尾 */
    int queueRear;

    /* 线程池中的线程 */
    pthread_t *threadIds;

    /* 最小的线程数 */
    int minThreads;
    /* 最大的线程数 */
    int maxThreads;
}threadpool_t;

/* 线程池的初始化 */
int threadInit(threadpool_t *pool, int minThreads, int maxThreads, int queueCapacity);

/* 线程池的销毁 */
int threadDetory(threadpool_t *pool);









#endif