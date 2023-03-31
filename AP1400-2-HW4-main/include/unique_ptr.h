#ifndef UNIQUE_PTR
#define UNIQUE_PTR
#include <memory>

template <typename T>
class UniquePtr {
   public:
    UniquePtr() : _p(nullptr) {}
    UniquePtr(T* p) : _p(p) {}
    UniquePtr(std::unique_ptr<T> up) : _p(up.release()) {}

    UniquePtr(const UniquePtr& up) = delete;
    UniquePtr& operator=(const UniquePtr& up) = delete;

    T* get() const { return _p; }
    T& operator*() const { return *_p; }
    T* operator->() const { return &this->operator*(); }

    void reset() {
        delete _p;
        _p = nullptr;
    }

    void reset(T* p) {
        delete _p;
        _p = p;
    }

    T* release() {
        T* p = _p;
        _p = 0;
        return p;
    }
    /*
     * class conversion operator: operator type() const {body}
     */
    operator bool() const { return nullptr != _p; }

    ~UniquePtr() {
        delete _p;
        _p = nullptr;
    }

   private:
    T* _p = nullptr;
};

#endif  // UNIQUE_PTR