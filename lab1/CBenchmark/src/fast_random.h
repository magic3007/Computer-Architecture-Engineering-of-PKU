#ifndef FAST_RANDOM

#define FAST_RANDOM


int fastRandom(){
    static int seed_ =  114514;
    return seed_*13+37;
}

#endif // !FAST_RANDOM