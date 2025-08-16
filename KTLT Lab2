---------------------------------------Recursion------------------------------------
int calculate_power(int n, int e) 
{ 
    /*  
     * STUDENT ANSWER
     */
     if(e==0) return 1;
     else if(e==1) return n;
     return n*calculate_power(n,e-1);
}


int gcdRecursion(int p, int q)
{
    // BEGIN YOUR IMPLEMENTATION [1]
    if (q == 0)
        return p;
    return gcdRecursion(q, p % q);
    // END YOUR IMPLEMENTATION [1]
}
int gcdIteration(int p, int q)
{
    // BEGIN YOUR IMPLEMENTATION [2]
    while (q != 0) {
        int temp = q;
        q = p % q;
        p = temp;
    }
    return p;
    // END YOUR IMPLEMENTATION [2]
}



int strLen(char* str)     
{ 
    /*  
     * STUDENT ANSWER
     */
     if (*str == '\0')
        return 0;
    return 1 + strLen(str + 1);
}


int recursiveSum(int arr[], int size) {
    // TODO
    
    if(size==1) return arr[0];
    else return arr[size-1]+recursiveSum(arr,size-1);
}


long int decimalToBinary(int decimal_number)
{
	/*
	* STUDENT ANSWER
	*/
	if(decimal_number==0) return 0;
	if(decimal_number==1) return 1;
	return decimalToBinary(decimal_number/2)*10 + decimal_number%2;
}


bool palindromeRecursion(string s)
{
    // BEGIN YOUR IMPLEMENTATION [1]
    if (s.size() <= 1) return true;


    if (s.front() != s.back()) return false;

    
    return palindromeRecursion(s.substr(1, s.size() - 2));

    // END YOUR IMPLEMENTATION [1]
}

int main()
{
    hiddenCheck();
    // BEGIN YOUR IMPLEMENTATION [2]
    // TODO
    string str;
    while(true){
        getline(cin, str);
        if(str[0]  == '*') break;
        else cout << (palindrome(str) ? "true " : "false ") << (palindromeRecursion(str) ? "true" : "false") << endl;
    }
    // END YOUR IMPLEMENTATION [2]
    return 0;
}


-----------------------------------------------------Pointer------------------------------------
int getValueAtIndex(int *ptr, int k)
{
    return *(ptr+k);
}


void swap(int *ptr1, int *ptr2)
{
 int temp= *ptr1;
  *ptr1=*ptr2;
  *ptr2=temp;
}


int* zeros(int n) {
    // TODO
    
     if (n <= 0) {
        return nullptr;
    }
    
    int* arr = new(nothrow) int[n];
    if (arr == nullptr) {
        return nullptr;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    
    return arr;
    
}


void shallowCopy(int*& newArr, int*& arr) {
    // TODO
    newArr=arr;
}


int** deepCopy(int** matrix, int r, int c) {
    // TODO
     if (r <= 0 || c <= 0 || matrix == nullptr) {
        return nullptr;
    }
    
    int** newMatrix = new(nothrow) int*[r];
    if (newMatrix == nullptr) {
        return nullptr;
    }
    
    for (int i = 0; i < r; i++) {
        newMatrix[i] = new(nothrow) int[c];
        if (newMatrix[i] == nullptr) {
            for (int j = 0; j < i; j++) {
                delete[] newMatrix[j];
            }
            delete[] newMatrix;
            return nullptr;
        }
        
        for (int j = 0; j < c; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    
    return newMatrix;
}


void deleteMatrix(int**& matrix, int r) {
    // TODO;
    for(int i=0; i<r; i++){
        delete[] matrix[i];
    }
    matrix=nullptr;
}


void insertRow(int**& matrix, int r, int c, int* rowArr, int row) {
    // TODO
    if (matrix == nullptr || rowArr == nullptr || row < 0 || row > r) {
        return;
    }
    
    
    int** newMatrix = new(nothrow) int*[r + 1];
    if (newMatrix == nullptr) {
        return;
    }
    
    
    for (int i = 0; i < row; i++) {
        newMatrix[i] = matrix[i];
    }
    
   
    newMatrix[row] = new(nothrow) int[c];
    if (newMatrix[row] == nullptr) {
        delete[] newMatrix;
        return;
    }
    for (int j = 0; j < c; j++) {
        newMatrix[row][j] = rowArr[j];
    }
    
    
    for (int i = row; i < r; i++) {
        newMatrix[i + 1] = matrix[i];
    }
    
  
    delete[] matrix;
    matrix = newMatrix;
}


int calcSum(int *ptr, int n)
{
    int result=0;
    for(int i=0;i<n;i++){
        result =result+ *(ptr+i);
    }
    return result;
}

void add(int *ptr, int n, int k)
{
    ptr[n]=k;
}


int** readArray()
{
   //TODO
   int **matrix=new int*[10];
   for(int i=0;i<10;i++){
       matrix[i]=new int[10];
   }
   for(int i=0;i<10;i++){
       for(int j=0;j<10;j++){
           cin>>matrix[i][j];
           if(matrix[i][j]==0){
               for(int u=j+1;u<10;u++){
                   matrix[i][u]=0;
               }
               break;
           }
       }
   }
   return matrix;
}


void addElement(int*& arr, int n, int val, int index) {
    // TODO
    int *newarr=new int[n+1];
    for(int i=0;i<n;i++){
        newarr[i]=arr[i];
    }
    for(int i=index;i<n;i++){
        newarr[i+1]=arr[i];
    }
    newarr[index]=val;
    delete[] arr;
    arr=newarr;
}


int* flatten(int** matrix , int r, int c) {
    //TODO
   
    int *arr=new int[r*c];
    int count=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr[count]=matrix[i][j];
            count++;
        }
    }
    return arr;
    
}


char* concatStr(char* str1, char* str2) {
    // TODO
   if(str1==nullptr&& str2==nullptr) return nullptr;
   
   int strlength1=0;
   while(str1[strlength1]!='\0'){
       strlength1++;
   }
   int strlength2=0;
   while(str2[strlength2]!='\0'){
       strlength2++;
   }
   char* result= new char[strlength1+strlength2+1];
   int i=0;
   for( i=0;i<strlength1;i++){
       result[i]=str1[i];
   }
   
   for(int j=0;j<strlength2;j++){
       result[i+j]=str2[j];
   }
   result[strlength1+strlength2]='\0';
   return result;
}


int** transposeMatrix(int** matrix, int r, int c) {
    // TODO
    
    if (matrix == nullptr || r <= 0 || c <= 0) {
        return nullptr;
    }
    

    int** transposed = new int*[c];
    for (int i = 0; i < c; i++) {
        transposed[i] = new int[r];
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    return transposed;
}

------------------------------------------------------------Struct------------------------------------
struct SCP {
    // Student answer
    int id;                    
    int objClass;             
    string speConProcedures;   
    string description;        
    string* addendums;         
    int numAddendums; 
};

void addAddendum(SCP &obj, string addendum) {
    // Student answer
     string* newAddendums = new string[obj.numAddendums + 1];
    
    
    for (int i = 0; i < obj.numAddendums; i++) {
        newAddendums[i] = obj.addendums[i];
    }
    
    
    newAddendums[obj.numAddendums] = addendum;
    
    
    if (obj.addendums != nullptr) {
        delete[] obj.addendums;
    }
    
    obj.addendums = newAddendums;
    obj.numAddendums++;
}


SCP createSCP(int id, int objClass, string speConProcedures, string description, string* addendums, int numAddendums) {
    // Student answer
    SCP newSCP;
    newSCP.id=id;
    newSCP.objClass=objClass;
    newSCP.speConProcedures=speConProcedures;
    newSCP.description=description;
    newSCP.numAddendums=numAddendums;
     if (numAddendums > 0 && addendums != nullptr) {
        newSCP.addendums = new string[numAddendums];
        
        for (int i = 0; i < numAddendums; i++) {
            newSCP.addendums[i] = addendums[i];
        }
    } else {
        newSCP.addendums = nullptr;
    }
    
    return newSCP;
}


string convertToString(SCP obj) {
    // Student answer
    string result = "";
    result += "Item #: SCP-";
    if (obj.id < 10) {
        result += "00" + to_string(obj.id);
    } else if (obj.id < 100) {
        result += "0" + to_string(obj.id);
    } else {
        result += to_string(obj.id);
    }
    result += "\n";
    
    // Object Class
    result += "Object Class: ";
    if (obj.objClass == 0) {
        result += "Safe";
    } else if (obj.objClass == 1) {
        result += "Euclid";
    } else if (obj.objClass == 2) {
        result += "Keter";
    }
    result += "\n";
    
    result += "Special Containment Procedures: " + obj.speConProcedures + "\n";
    
    result += "Description: " + obj.description + "\n";
    
   
    for (int i = 0; i < obj.numAddendums; i++) {
        result += obj.addendums[i] + "\n";
    }
    
    return result;

}


SCP* cloneSCP(SCP* original) {
    
    if (original == nullptr) {
        return nullptr;
    }
    
    
    SCP* clone = new SCP;
    
    
    clone->id = original->id;
    clone->objClass = original->objClass;
    clone->speConProcedures = original->speConProcedures;
    clone->description = original->description;
    clone->numAddendums = original->numAddendums;
    
   
    if (original->numAddendums > 0 && original->addendums != nullptr) {
        
        clone->addendums = new string[original->numAddendums];
        
      
        for (int i = 0; i < original->numAddendums; i++) {
            clone->addendums[i] = original->addendums[i];
        }
    } else {
        
        clone->addendums = nullptr;
    }
    
    return clone;
}
