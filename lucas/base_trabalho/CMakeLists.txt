cmake_minimum_required(VERSION 3.13)
project(base_trabalho)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(datasets)
include_directories(ordenacao)

add_executable(base_trabalho
        datasets/preprocessado/2019-05-02.csv
        datasets/preprocessado/bgg-13m-reviews.csv
        datasets/preprocessado/games_detailed_info.csv
        datasets/preprocessador.py
        ordenacao/BubbleSort.h
        ordenacao/HeapSort.h
        ordenacao/InsertionSort.h
        ordenacao/MergeSort.h
        ordenacao/QuickSort.h
        ordenacao/SelectionSort.h
        GameInfo.h
        LeitorBase.h
        LeitorGameInfo.h
        LeitorUserReviews.h
        LeitorUsersRated.h
        Log.h
        main.cpp
        UserReview.h
        UsersRated.h hashing/hashmap.h ordenacao/QuickSortInsertion.h ordenacao/RadixSort.h)
