#pragma once
struct DataType{
   int array[10];
   int elementnumber;
   int ElementCount();
};

int DataType::ElementCount(){
   return elementnumber;
}
