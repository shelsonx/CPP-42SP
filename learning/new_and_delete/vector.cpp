class Vector
{
    float x, y, z;
};

int main()
{
    //allocate on the stack
    int value = 5;
    int array[5];
    Vector vector;

    //allocate on the heap
    int* hvalue = new int;
    *hvalue = 5;
    int* harray = new int[5];
    Vector* hvector = new Vector();

    //need to delete() all the new allocation
    delete hvalue;
    delete[] harray;
    delete hvector;
}