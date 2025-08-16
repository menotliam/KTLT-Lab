------------------------------------------------------------C-string----------------------------------------------
void reverse(char str[]) {
    // TODO
    char tempstr[1000];
    int length=strlen(str)-1;
    for(int i=0;i< strlen(str);i++){
        tempstr[i]=str[i];
    }
    for(int i=0;i<strlen(str);i++){
        str[i] = tempstr[length--];
        
    }
}


void recover(char signal[]) {
    // 
    int length=strlen(signal);
    for(int i=0; i<length;i++){
        if(signal[i]>='A' && signal[i]<='Z'){
            signal[i]=signal[i]+32;
        }
        else if(signal[i]>='a'&&signal[i]<='z'){
            signal[i]=signal[i]-32;
        }
    }
    
}

--------------------------------------------------------------string------------------------------------------
void cutString(string s, int index){
    // TO DO
    if(index < 0 || index >= s.length()) {
        // Index không hợp lệ, không in ra gì
        return;
    }
    
    // In ra chuỗi con từ vị trí index đến hết
    cout << s.substr(index) << endl;
    
}


void findAllIndex(string s1, string s2){
    // TO DO
    if(s1.find(s2[0])== string::npos){
        cout<<-1;
        return;
    }
  for(int i=0;i<s1.length();i++){
      if(s1[i]==s2[0]){
          if(i==s1.length()-1){
              cout<<i;
          }
          else  cout<<i<<" ";
      }
      
  }
  
}

----------------------------------------------------------Multi dementional-----------------------------------
int findMaxColumn(int arr[][1000], int row, int col) {
    int max=0;
    int max1=0;
    int maxcol=0;
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            max=max+arr[j][i];
        }
        if(max>max1){
            max1=max;
            maxcol=i;
        }
        max=0;
    }
    return maxcol;
}


int diagonalProduct(int arr[][1000], int row, int col) {
    int multi=1;
    for(int i=0;i<row;i++){
        multi=multi*arr[i][i];
    }
    return multi;
}

bool isSymmetric(int arr[][1000], int row, int col) {
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=arr[j][i]){
                return false;
            }
            
        }
    }
    return true;
}


int diagonalDiff(int arr[][1000], int row, int col, int x, int y) {
    // Kiểm tra tọa độ hợp lệ
    if(x < 0 || x >= row || y < 0 || y >= col) {
        return 0;
    }
    
    int diagonal1_sum = 0; // Đường chéo chính (từ trên trái xuống dưới phải)
    int diagonal2_sum = 0; // Đường chéo phụ (từ trên phải xuống dưới trái)
    
    // Tính tổng đường chéo chính đi qua (x,y)
    // Tìm điểm bắt đầu của đường chéo chính
    int start_row1 = x, start_col1 = y;
    while(start_row1 > 0 && start_col1 > 0) {
        start_row1--;
        start_col1--;
    }
    // Duyệt từ điểm bắt đầu đến hết đường chéo
    int i = start_row1, j = start_col1;
    while(i < row && j < col) {
        diagonal1_sum += arr[i][j];
        i++;
        j++;
    }
    
    // Tính tổng đường chéo phụ đi qua (x,y)
    // Tìm điểm bắt đầu của đường chéo phụ
    int start_row2 = x, start_col2 = y;
    while(start_row2 > 0 && start_col2 < col - 1) {
        start_row2--;
        start_col2++;
    }
    // Duyệt từ điểm bắt đầu đến hết đường chéo
    i = start_row2;
    j = start_col2;
    while(i < row && j >= 0) {
        diagonal2_sum += arr[i][j];
        i++;
        j--;
    }
    
    // Nếu ô (x,y) nằm trên cả hai đường chéo, trừ đi một lần để tránh tính trùng
    if(x == y || x + y == row - 1) {
        // Kiểm tra xem có phải ô chung của cả hai đường chéo không
        bool on_both_diagonals = false;
        
        // Kiểm tra có nằm trên đường chéo chính không
        bool on_main = true;
        int temp_i = x, temp_j = y;
        while(temp_i > 0 && temp_j > 0) {
            temp_i--;
            temp_j--;
        }
        if(temp_i != 0 || temp_j != 0) {
            on_main = false;
        }
        
        // Kiểm tra có nằm trên đường chéo phụ không  
        bool on_anti = true;
        temp_i = x;
        temp_j = y;
        while(temp_i > 0 && temp_j < col - 1) {
            temp_i--;
            temp_j++;
        }
        if(temp_i != 0 || temp_j != col - 1) {
            on_anti = false;
        }
        
        if(on_main && on_anti) {
            diagonal1_sum -= arr[x][y]; // Trừ đi một lần để tránh tính trùng
        }
    }
    
    return abs(diagonal1_sum - diagonal2_sum);
}

----------------------------------------------------I/O file----------------------------------
void calSum(string fileName)   {
    ifstream ifs(fileName);
    if (!ifs.is_open()) {
        cout << "Không thể mở file!" << endl;
        return;
    }
    
    string line;
    int sum = 0;
    
    // Đọc dòng đầu tiên từ file
    if (getline(ifs, line)) {
        string number = "";
        
        // Duyệt từng ký tự trong dòng
        for (int i = 0; i <= line.length(); i++) {
            // Nếu gặp khoảng trắng hoặc hết dòng
            if (i == line.length() || line[i] == ' ') {
                if (!number.empty()) {
                    try {
                        int num = stoi(number);
                        if (num >= 0) {  // Chỉ cộng các số không âm
                            sum += num;
                        }
                    } catch (const invalid_argument& e) {
                        // Bỏ qua nếu không phải số
                    }
                    number = "";  // Reset để đọc số tiếp theo
                }
            } else {
                number += line[i];  // Thêm ký tự vào số hiện tại
            }
        }
    }
    
    cout << sum << endl;
    ifs.close();
}

------------------------------------------------------Function------------------------------------

long calculateFactorial(int n) {
    if (n <= 1) {
        return 1;
    }
    long factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}
int main(int narg, char** argv)
{
    int N;
    cin >> N;
    long result;
    // call function calculateFactorial in here and assign value to the variable result
    result = calculateFactorial(N);

    cout << result << endl;
    return 0;
}



void sum2(int * array, int numEls, int &result)
{
    // TODO
    int sum=0;
    for(int i=0;i<numEls;i++){
        sum=sum+array[i];
    }
    result=sum;
}


bool completeNum(int N)
{
    // TODO
    int arr[1000];
    int arrcount=0;
    int sum=0;
    for(int i=1;i<N;i++){
        if(N % i==0){
            arr[arrcount]=i;
            arrcount++;
        }
    }
    for(int i=0;i<arrcount;i++){
        sum=sum+arr[i];
    }
    if(sum==N){
        return true;
    }
    else return false;
}

------------------------------------------------------Cstring----------------------------------------

int find(char str[], char substr[]) {
    // TODO
    int strlength=strlen(str);
    int substrlen=strlen(substr);
    if(substrlen==0) return 0;
    if(substrlen>strlength) return -1;
    for(int i=0;i<strlength;i++){
        bool found=true;
        for(int j=0;j<substrlen;j++){
            if(substr[j]!=str[i+j]){
                found=false;
                break;
            }
        }
        if(found) return i;
    }
    return -1;
}


void printFirstRepeatedWord(char str[]) {
    // TODO
    int strlength = strlen(str);
    char words[100][31];
    int wordCount = 0;
    int i = 0;
    
    while (i < strlength) {
        
        while (i < strlength && str[i] == ' ') {
            i++;
        }
        
        if (i >= strlength) break;
        
       
        int j = 0;
        while (i < strlength && str[i] != ' ' && str[i] != '\0') {
            words[wordCount][j] = str[i];
            i++;
            j++;
        }
        words[wordCount][j] = '\0';  
        
        for (int k = 0; k < wordCount; k++) {
            if (strcmp(words[k], words[wordCount]) == 0) {
                cout << words[wordCount] << endl;
                return;
            }
        }
        
        wordCount++;
    }
    

    cout << "No Repetition" << endl;
}



void process(const char str[], char outstr[]) {
    // TODO
    int len = strlen(str);
    int outIndex = 0;
    bool prevIsSpace = true; 
    
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
           
            if (!prevIsSpace) {
                outstr[outIndex] = ' ';
                outIndex++;
                prevIsSpace = true;
            }
        } else {
            
            outstr[outIndex] = str[i];
            outIndex++;
            prevIsSpace = false;
        }
    }
    
   
    if (outIndex > 0 && outstr[outIndex - 1] == ' ') {
        outIndex--;
    }
    
    
    outstr[outIndex] = '\0';
}

----------------------------------------------------------String------------------------------

void replaceString(string s, string s1, string s2){
    //TO DO
    size_t lastPos = s.rfind(s1);
    
    if (lastPos != string::npos) {
        s.replace(lastPos, s1.length(), s2);
    }
    
    cout << s << endl;
}

void deleteWord(string s, string s1){
    //TO DO
     size_t pos = 0;
    
   
    while ((pos = s.find(s1, pos)) != string::npos) {
        s.erase(pos, s1.length());
    }
    cout << s << endl;
}

------------------------------------------------------------Multi-dimensional Array---------------------------
int ascendingRows(int arr[][1000], int row, int col) {
int HNcount=0;
bool HN=true;
for(int i=0;i< row;i++){
    for(int j=0;j<col-1;j++){
        if(arr[i][j]>arr[i][j+1]){
            HN=false;
            break;
        }
           HN=true;
    }
    if(HN){
        HNcount++;
    }
}
return HNcount;
}



bool iselement(int a){
    int count1=0;
    for(int i=1;i<=a;i++){
        if(a%i==0){
            count1++;
        }
    }
    if(count1==2) return true;
    else return false;
}
int primeColumns(int arr[][1000], int row, int col) {
    int sum = 0;
    int count=0;
   for(int i=0;i<col;i++){
       for(int j=0;j<row;j++){
           sum=sum+arr[j][i];
       }
       if(iselement(sum)){
           count++;
       }
       sum=0;
   }
   return count;
}

--------------------------------------------------------File IO----------------------------------

void uppercase(string output)   {
    // TODO
    string s;
    getline(cin, s);  
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';  
        }
    }
    
    ofstream ofs(output);
    if(ofs.is_open()) {
        ofs << s;
        ofs.close();
    }
}



void process(string fileName)   {
    ifstream ifs(fileName);
    if (!ifs.is_open()) {
        return;
    }
    
    int N, M;
    ifs >> N >> M;  
    
    if (N <= 0 || M <= 0) {
        ifs.close();
        return;
    }
    
    double globalMax = -1e9;  
    
    for (int i = 0; i < N; i++) {
        double rowMax = -1e9; 
        
        for (int j = 0; j < M; j++) {
            double num;
            ifs >> num;
            
            if (ifs.fail()) {
                ifs.close();
                return;
            }
            
            if (num > rowMax) {
                rowMax = num;
            }
            
            if (num > globalMax) {
                globalMax = num;
            }
        }
        
        cout << rowMax;
        if (i < N - 1) {
            cout << " ";  
        }
    }
    
    cout << " " << globalMax << endl;
    
    ifs.close();
}

-----------------------------------------------------------Function------------------------------

bool isPalindrome(const char* str) {
    string s=str;
    int len=s.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;  
        }
    }
    
    return true; 
}


bool iselement(int n){
    int count=0;
    if(n==1000) return false;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==2) return 1;
    else return 0;
}
bool isSpecialNumber(int n) {
    // Write your code 
    // Kiểm tra n có phải số nguyên tố không
    bool isele = iselement(n);
    bool issumelement = false;
    
    // Tính tổng các chữ số của n
    int sum = 0;
    int temp = n;
    while(temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    
    // Kiểm tra tổng các chữ số có phải số nguyên tố không
    issumelement = iselement(sum);
    
    // Số đặc biệt khi cả n và tổng các chữ số đều là số nguyên tố
    return (isele && issumelement);
}


void encrypt(char* text, int shift) {
    // Write your code 
    if (text == nullptr) return;  
    string s=text;
    
    int len = s.length();
 
    shift = shift % 26;
    if (shift < 0) shift += 26;
    
    for(int i = 0; i < len; i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        }
        else if(text[i] >= 'A' && text[i] <= 'Z') {

            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        }
       
    }
}

void decrypt(char* text, int shift) {
     
    if (text == nullptr) return;  
    string s=text;
    int len = s.length();
    
    shift = shift % 26;
    if (shift < 0) shift += 26;
    
    for(int i = 0; i < len; i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            
            text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';
        }
        else if(text[i] >= 'A' && text[i] <= 'Z') {
            
            text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';
        }
       
    }
}


bool checkElementsUniqueness(int* arr, int n) {
    // Write your code 
    int inside=1;
    for(int i=0;i<n;i++){
        int temp=arr[i];
        for(int j=inside;j<n;j++){
            if(temp==arr[j]) return false;
        }
        inside++;
    }
    return 1;
}



long int decimalToBinary(int decimal_number)
{
	/*
	* STUDENT ANSWER
	*/
	
	if (decimal_number == 0) {
		return 0;
	}
	if (decimal_number == 1) {
		return 1;
	}
	
	
	return (decimal_number % 2) + 10 * decimalToBinary(decimal_number / 2);
}
