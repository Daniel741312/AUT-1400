#ifndef SHARED_PTR
#define SHARED_PTR
#include <memory>
using namespace std;

template <typename T>
class SharedPtr {
   public:
    SharedPtr(T* p) : _p(p) { p_count = new size_t{1}; }

    SharedPtr() {
        p_count = new size_t(0);  // points to nothing
                                  //_p is nullptr
    }

    SharedPtr(std::shared_ptr<T> sp) {
        p_count = new size_t{1};
        _p = new T{*sp.get()};
    }

    SharedPtr(SharedPtr& sp) {
        ++(*sp.p_count);
        p_count = sp.p_count;
        _p = sp._p;
    }

    SharedPtr& operator=(SharedPtr& sp) {
        if (&sp != this) {  // NOTE: Do NOT use 'sp != *this' as the condition
            this->~SharedPtr();
            ++(*sp.p_count);
            if (p_count == nullptr) {
                p_count = new size_t(*sp.p_count);
            }
            _p = sp._p;
        }
        return *this;
    }

    size_t use_count() const {
        if (p_count) {
            return *p_count;
        } else {
            return 0;
        }
    }

    T* get() const { return _p; }

    T& operator*() const { return *_p; }

    T* operator->() const { return &(this->operator*()); }

    void reset() {
        delete _p;
        _p = nullptr;
        *p_count = 0;
    }

    void reset(T* tp) {
        if (tp != _p) {
            delete _p;
            _p = tp;
            *p_count = 1;
        }
    }

    ~SharedPtr() {
        if (p_count == nullptr) {  //*p_count has been delete
            return;
        } else if (*p_count == 0) {  // points to nothing
            delete p_count;
            return;
        } else {
            (*p_count)--;
            if (*p_count == 0) {
                delete _p;
                _p = nullptr;
                delete p_count;
                p_count = nullptr;
            }
        }
    }

    /*
     * class conversion operator: operator type() const {body}
     */
    operator bool() const { return _p == nullptr; }

   private:
    size_t* p_count = nullptr;
    T* _p = nullptr;
};

#endif  // SHARED_PTR