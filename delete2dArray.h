/** 
 * author: zzw5005
 * date: 2020/5/9 21:23
*/

#ifndef DATASTRUCTURESALGORITHMSANDAPPLICATIONINCPLUS_DELETE2DARRAY_H
#define DATASTRUCTURESALGORITHMSANDAPPLICATIONINCPLUS_DELETE2DARRAY_H

using namespace std;

/**
 * 删除二维数组
 * @tparam T
 * @param theArray
 * @param numberOfRows
 */
template<class T>
void delete2dArray(T ** &theArray, int numberOfRows){
    //- 删除二维数组空间
    for(int i = 0; i < numberOfRows; i++){
        delete[] theArray[i];
    }
    //- 删除行指针
    delete[] theArray;

    theArray = nullptr;
}

#endif //DATASTRUCTURESALGORITHMSANDAPPLICATIONINCPLUS_DELETE2DARRAY_H
