using namespace std;

class IntArray {
public:
  IntArray(const IntArray &other);
  //other class functions are here, which you don’t need to worry about
private:
  int *myarray; //data
  int used; //number of elements in myarray
  int alloc; //number of allocated indices. Unused indices have garbage values.
};

IntArray::IntArray(const IntArray &other){
  this->used = other.used;
  this->alloc = other.alloc;
  this->myarray = new int[alloc];
  for(int i = 0 ; i < alloc ; i++){
    this->myarray[i] = other.myarray[i];
  }
}



class ArrayOfArrays {
public:
  ArrayOfArrays(const ArrayOfArrays &other);
  //other class functions are here, which you don’t need to worry about
private:
  IntArray **myarray; //an array of IntArray pointers.
  int used; //number of arrays in myarray
  int alloc; //number of allocated indices. Unused indices have garbage values.
};

ArrayOfArrays::ArrayOfArrays(const ArrayOfArrays &other){
  this->used = other.used;
  this->alloc = other.alloc;
  this->myarray = new IntArray*[alloc];
  for(int i = 0 ; i < used ; i++){
    this->myarray[i] = new IntArray(*(other.myarray[i]));
  }
}
