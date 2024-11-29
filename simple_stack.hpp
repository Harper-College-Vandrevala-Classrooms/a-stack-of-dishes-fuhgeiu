#include <iostream>


template <typename T>
class contdynamic {

    T* cd_data = nullptr;

    size_t  cd_size = 0;
    size_t cd_capacity = 0;

private:

    void allocate (size_t newCapacity) {

        T* newblock = (T*)::operator new (newCapacity* sizeof(T) * 1.5);
        for (size_t i = 0; i < cd_size; i++) {newblock[i] = std::move(cd_data[i]);}

        (T*)::operator delete (cd_data, cd_capacity * sizeof(T*));

        cd_data = newblock;
        cd_capacity = (newCapacity*1.5);
    }

    void allocate () {

        size_t newCapacity = 5;

        T* newblock = (T*)::operator new (newCapacity* sizeof(T) * 1.5);
        for (size_t i = 0; i < cd_size; i++) {newblock[i] = std::move(cd_data[i]);}

        (T*)::operator delete (cd_data, cd_capacity * sizeof(T*));

        cd_data = newblock;
        cd_capacity = (newCapacity*1.5);
    }


public:

    contdynamic() {allocate(2);}                   // default constructor allocate 2*1.5

    ~contdynamic() {                                        // destructor

        clear();                                              // call destructer for each element
        (T*)::operator delete(cd_data, cd_capacity * sizeof(T*));    // deallocates container arrray
    }

    void append(const T& element) {

        if (cd_size >= cd_capacity){                         // to increase available container space

            allocate(cd_size*3/2);
        }

        cd_data[cd_size] = element;                         // copy data to apped onto container and assign
        cd_size++;                                          // increment size
    }

    void append(const T&& element) {                         // to mvoe data must be rvalue to use move()

        if (cd_size >= cd_capacity){                         // to increase available container space

            allocate(cd_size*3/2);
        }

        cd_data[cd_size] = element;                         // copy data to apped onto container and assign
        cd_size++;                                          // increment size
    }

    void popback() {

        ~cd_data[cd_size-1];
        cd_size -= 1;
    }

    void clear() {                                                    // to clear each element

        for (size_t i = 0; i < cd_size; i++) { cd_data[i].~T(); }     // itterate over container, destruct each element
        cd_size = 0;
    }

    void print () {

        for (size_t i = 0; i < cd_size; i++) std::cout << cd_data[i];

    }

    const size_t length() const {return cd_size;}                                   // return size of container

    const size_t size() const {return cd_size * sizeof(T);}

    const T& operator[](size_t index) const { return cd_data[index % cd_size]; }   // return const ref to index

    T& operator[] (size_t index)  { return cd_data[index % cd_size]; }   // return refrence to data at index

};


template <typename C>
class stack : public contdynamic<C> {



public:

    void peek () {






    }

    void pushback () {



    }






};
