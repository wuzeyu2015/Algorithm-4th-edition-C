#ifndef INDEXHEAP_H
#define INDEXHEAP_H

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

template<typename Item>
class IndexMaxHeap{

private:
    Item *data;
    int *indexes;

    int count;
    int capacity;

    void shiftUp( int k ){

        while( k > 1 && data[indexes[k/2]] < data[indexes[k]] ){
            swap( indexes[k/2] , indexes[k] );
            k /= 2;
        }
    }

    void shiftDown( int k ){

        while( 2*k <= count ){
            int j = 2*k;
            if( j + 1 <= count && data[indexes[j+1]] > data[indexes[j]] )
                j += 1;

            if( data[indexes[k]] >= data[indexes[j]] )
                break;

            swap( indexes[k] , indexes[j] );
            k = j;
        }
    }

public:
    IndexMaxHeap(int capacity){

        data = new Item[capacity+1];
        indexes = new int[capacity+1];

        count = 0;
        this->capacity = capacity;
    }

    ~IndexMaxHeap(){
        delete[] data;
        delete[] indexes;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    // 传入的i对用户而言,是从0索引的
    void insert(int i, Item item){
        assert( count + 1 <= capacity );
        assert( i + 1 >= 1 && i + 1 <= capacity );

        i += 1;
        data[i] = item;
        indexes[count+1] = i;
        count++;

        shiftUp(count);
    }

    Item extractMax(){
        assert( count > 0 );

        Item ret = data[indexes[1]];
        swap( indexes[1] , indexes[count] );
        count--;
        shiftDown(1);
        return ret;
    }

    int extractMaxIndex(){
        assert( count > 0 );

        int ret = indexes[1] - 1;
        swap( indexes[1] , indexes[count] );
        count--;
        shiftDown(1);
        return ret;
    }

    Item getMax(){
        assert( count > 0 );
        return data[indexes[1]];
    }

    int getMaxIndex(){
        assert( count > 0 );
        return indexes[1]-1;
    }

    Item getItem( int i ){
        return data[i+1];
    }

    void change( int i , Item newItem ){

        i += 1;
        data[i] = newItem;

        // 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shiftUp(j), 再shiftDown(j)

        for( int j = 1 ; j <= count ; j ++ )
            if( indexes[j] == i ){
                shiftUp(j);
                shiftDown(j);
                return;
            }
    }

    // test reverse index
    bool testReverseIndex(){

        int *copyIndexes = new int[count+1];

        for( int i = 0 ; i <= count ; i ++ ){
            copyIndexes[i] = indexes[i];
        }

        copyIndexes[0] = 0;
        std::sort(copyIndexes, copyIndexes + count + 1);

        bool res = true;
        for( int i = 1 ; i <= count ; i ++ )
            if( copyIndexes[i-1] + 1 != copyIndexes[i] )
                res = res || false;

        delete[] copyIndexes;

        if( !res ){
            cout<<"Error 1"<<endl;
            return res;
        }

        return true;
    }
};
#endif //INDEXHEAP_H
