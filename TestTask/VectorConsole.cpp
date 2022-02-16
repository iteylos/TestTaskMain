#include "Vector.h"

int main() {

    Vector<int> vector;
    std::cout << vector.IsEmpty()  << "    Vector is empty!" << std::endl;
    vector.Push_Back(1);
    std::cout << vector.IsEmpty() << "    Vector is not empty!" << std::endl;
    vector.Push_Back(2);
    vector.Push_Back(3);
    vector.Push_Back(4);
    vector.Push_Back(5);
    std::cout << std::endl << "4th element of vector is:  " << vector[4] << std::endl;
    std::cout << "3rd element of vector is:  " << vector[3] << std::endl;
    std::cout << "2nd element of vector is:  " << vector[2] << std::endl;
    std::cout << "1st element of vector is:  " << vector[1] << std::endl;
    std::cout << "Null element of vector is: " << vector[0] << std::endl;
    std::cout << std::endl << "Contents of the vector: " << std::endl << vector << std::endl;
    std::cout << std::endl << "Vector capacity:  " << vector.Capacity() << std::endl;
    std::cout << "Vector size:  " << vector.Size() << std::endl << std::endl;
    vector.Reserve(32);
    vector.Erase(4);
    std::cout << "The fourth element of the vector has been deleted!";
    std::cout << std::endl << "Contents of the vector: " << std::endl << vector << std::endl;
    std::cout << std::endl << "Modified vector capacity:  " << vector.Capacity() << std::endl;
    std::cout << "Modified vector size:  " << vector.Size() << std::endl << std::endl;
    vector.Erase(1);
    std::cout << "The first element of the vector has been deleted!";
    std::cout << std::endl << "Contents of the vector: " << std::endl << vector << std::endl;
    std::cout << std::endl << "Modified vector capacity:  " << vector.Capacity() << std::endl;
    std::cout << "Modified vector size:  " << vector.Size() << std::endl;
    vector.Clean();
    std::cout << std::endl << "Vector has been cleared!";
    std::cout << std::endl << vector.IsEmpty() << "    Vector is empty!" << std::endl;
    vector.Push_Back(1);
    vector.Push_Back(2);
    vector.Push_Back(3);
    vector.Push_Back(4);
    vector.Push_Back(5);
    std::cout << std::endl << "Contents of the vector: " << std::endl << vector << std::endl;
    system("pause");
    return 0;
};