---------------------------------------------------------------------RECURSION----------------------------------------------------------------
int findOccurrences(int nums[], int size, int element) {
    if (size == 0) 
        return 0;

    
    return (nums[size - 1] == element) 
           + findOccurrences(nums, size - 1, element);
    
}

-----------------------------------------------------------
int countWaysHelper(int x, int maxBase) {
    if (x == 0) return 1;      
    if (x < 0 || maxBase == 0) return 0; 

    
    int include = countWaysHelper(x - maxBase * maxBase, maxBase - 1);

   
    int skip = countWaysHelper(x, maxBase - 1);

    return include + skip;
}

int countWaySumOfSquare(int x) {
    if(x==0) return 0;
    int maxBase = (int) sqrt(x);
    return countWaysHelper(x, maxBase);
}

--------------------------------------------------------POINTER_BASIC-------------------------------------------------------
int findMax(int *ptr, int n)
{
    int max = -100;
    for(int i=0; i<n; i++){
        if(*(ptr+i) > max) max = *(ptr+i);
    }
    return max;
}

-------------------------------------------------
void reverse(int *ptr, int n) {
    for(int i=0; i<n/2; i++){
        int temp = *(ptr+i);
        *(ptr+i) = *(ptr+n-1-i);
        *(ptr+n-1-i) = temp;
    }
}
  
--------------------------------------------------
bool isSymmetry(int *head, int *tail)
{
    int i=(tail - head + 1) / 2;
    for(int j=0; j<i; j++){
        if(*(head+j) != *(tail-j)) return false;
    }
    return true;
}

-------------------------------------------------------------POINTER_2---------------------------------------------------------------
int** insertCol(int**& matrix, int r, int c, int* colArr, int col) {
    for (int i = 0; i < r; i++) {
        int* newRow = new int[c + 1];
        
        
        for (int j = 0; j < c; j++) {
            newRow[j] = matrix[i][j];
        }

        delete[] matrix[i]; 
        matrix[i] = newRow;
    }

    
    for (int i = 0; i < r; i++) {
        for (int j = c; j > col; j--) { 
            matrix[i][j] = matrix[i][j - 1];
        }
        matrix[i][col] = colArr[i]; 
    }

    return matrix;
}

----------------------------------------------------------------------
bool deleteRow(int**& matrix, int r, int c, int row) {
    if (r <= 0 || row < 0 || row >= r || matrix == nullptr) {
        return false; 
    }

    
    delete[] matrix[row];

    
    for (int i = row; i < r - 1; i++) {
        matrix[i] = matrix[i + 1];
    }

    
    if (r - 1 == 0) {
        delete[] matrix;
        matrix = nullptr;
        return true;
    }

    
    int** newMatrix = new int*[r - 1];
    for (int i = 0; i < r - 1; i++) {
        newMatrix[i] = matrix[i];
    }

   
    delete[] matrix;
    matrix = newMatrix;

    return true;
}

-------------------------------------------------------------------
bool deleteCol(int**& matrix, int r, int c, int col) {
    if (r <= 0 || c <= 0 || col < 0 || col >= c || matrix == nullptr) {
        return false; 
    }

   
    for (int i = 0; i < r; i++) {
        
        for (int j = col; j < c - 1; j++) {
            matrix[i][j] = matrix[i][j + 1];
        }

        
        if (c - 1 == 0) {
            delete[] matrix;
            matrix = nullptr;
            return true;
        }
        int* newRow = new int[c - 1];
        for (int j = 0; j < c - 1; j++) {
            newRow[j] = matrix[i][j];
        }

        delete[] matrix[i];   
        matrix[i] = newRow;   
    }

    return true;
}

-------------------------------------------------------------STRUCT----------------------------------------------------------
int compareObjectClass(const SCP &objA, const SCP &objB) {
    if(objA.objClass > objB.objClass) return 1;
    else if(objA.objClass < objB.objClass) return -1;
    else return 0;
}

------------------------------------------------------------
SCP** sortDatabase(SCP** arr, int n) {
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if( i!=j && arr[i]->id > arr[j]->id){
                SCP *temp = new SCP;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                //delete temp;
            }
        }
    }
    return arr;
}
