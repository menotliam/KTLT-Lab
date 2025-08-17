template <class T>
class ColoredCell : public Cell<T> {
private:
    Color color;
public:
    void setColor(Color c) { color = c; }
    Color getColor() { return color; }

    // get trả về con trỏ
    T* get() {
        if (color == White) return nullptr;
        return &(this->infor);
    }
};

--------------------------------------------------
void ClockType::incrementSeconds() {
        sec++;
        if (sec == 60) {
            sec = 0;
            incrementMinutes();  // tăng phút khi giây tràn
        }
    }

    void ClockType::incrementMinutes() {
        min++;
        if (min == 60) {
            min = 0;
            incrementHours();   // tăng giờ khi phút tràn
        }
    }

    void ClockType::incrementHours() {
        hr++;
        if (hr == 24) {
            hr = 0;             // quay về 0 khi giờ = 24
        }
    }

---------------------------------------------------------------------------
bool ClockType::equalTime(const ClockType& other) const {
    return (hr == other.hr && min == other.min && sec == other.sec);
}

-----------------------------------------------------------------------------
Book::Book(const char* s) {
        // cấp phát động bộ nhớ để lưu name
        name = new char[strlen(s) + 1]; 
        strcpy(name, s); // sao chép chuỗi
    }

Book::~Book() {
    delete[] name; // giải phóng bộ nhớ
}

-----------------------------------------------------------------------------
// Constructor
    template <typename T>
    Array<T>::Array(int size, T initValue) {
        this->size = size;
        p = new T[size];
        for (int i = 0; i < size; i++) {
            p[i] = initValue;
        }
    }

    // Destructor
    template <typename T>
    Array<T>::~Array() {
        delete[] p;
    }

-------------------------------------------------------------------------------------
// Copy constructor
template<typename T>
    Array<T>::Array(const Array<T> & other) {
        cout << "Call copy constructor" << endl;
        size = other.size;
        p = new T[size];
        for (int i = 0; i < size; i++) {
            p[i] = other.p[i];
        }
    }

    // Copy assignment operator
    template<typename T>
  
    Array<T> & Array<T>::operator=(const Array<T> & other) {
        cout << "Call assignment operator" << endl;

        if (this == &other) return *this; // tránh tự gán

        delete[] p; // giải phóng bộ nhớ cũ

        size = other.size;
        p = new T[size];
        for (int i = 0; i < size; i++) {
            p[i] = other.p[i];
        }
        return *this;
    }

------------------------------------------------------------------------------------
class Integer {
private:
    int val;

public:
    // Constructor từ int
    void print();
    Integer(int x) : val(x) {}

    // Constructor từ con trỏ Integer
    Integer(Integer* other) {
        if (other != nullptr) {
            val = other->val;
        } else {
            val = 0;
        }
    }

    // Toán tử + : Integer + Integer
    Integer operator+(const Integer& other) const {
        return Integer(val + other.val);
    }

    // Toán tử + : Integer + int
    Integer operator+(int x) const {
        return Integer(val + x);
    }

    // Toán tử + : int + Integer (friend)
    friend Integer operator+(int x, const Integer& obj) {
        return Integer(x + obj.val);
    }
};
