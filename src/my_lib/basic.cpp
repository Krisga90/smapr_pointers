#include <memory>

#include "basic.h"

std::ostream &operator<<(std::ostream &out, const A &a) {
  out << a.value();
  return out;
}

std::ostream &operator<<(std::ostream &out, const A *a) {
  if (a) {
    out << a->value();
  } else {
    out << "empty pointer";
  }
  return out;
}

std::ostream &operator<<(std::ostream &out, const std::auto_ptr<A> &ptr) {
  if (ptr.get() != nullptr) {
    out << ptr->value();
  } else {
    out << "empty pointer";
  }
  return out;
}

std::ostream &operator<<(std::ostream &out, const std::shared_ptr<A> &ptr) {
  out << "shared\n";
  if (ptr.get() != nullptr) {
    out << ptr->value();
  } else {
    out << "empty pointer";
  }
  return out;
}

std::ostream &operator<<(std::ostream &out, const std::weak_ptr<A> &ptr) {
  out << "weak\n";
  if (auto shared = ptr.lock()) {
    out << shared->value();
  } else {
    out << "empty pointer";
  }
  return out;
}

std::ostream &operator<<(std::ostream &out, const std::unique_ptr<A> &ptr) {
  if (ptr.get() != nullptr) {
    out << ptr->value();
  } else {
    out << "empty pointer";
  }
  return out;
}

void funPointer() {
  std::cout << "normal pointer:\n";
  {
    A *normal_ptr = new A(7);

    std::cout << normal_ptr << "\n";
    delete normal_ptr;
    normal_ptr = nullptr;
    // empty pointer!!
    std::cout << *normal_ptr << "\n";
  }
  std::cout << "end normal pointer:\n\n";
}

void funAutoPointer() {
  std::cout << "auto_ptr:\n";
  {
    // Why auto pointer is a wrong  idea
    std::auto_ptr<A> ptr(new A(11));

    std::cout << ptr << "\n";

    {
      std::auto_ptr<A> ptr_2 = ptr;
      *ptr_2 += 2;
      std::cout << ptr_2 << "\n";
    }
    // empty pointer!!
    std::cout << ptr << "\n";
  }
  std::cout << "end auto_ptr:\n\n";
}

void funUniquePointer() {
  std::cout << "auto_ptr:\n";
  {
    // unique _pointer
    std::unique_ptr<A> ptr_u = std::make_unique<A>(11);

    std::cout << ptr_u << "\n";
    {
      std::unique_ptr<A> ptr_2_u = std::move(ptr_u);
      *ptr_2_u += 2;
      std::cout << ptr_2_u << "\n";
      ptr_u = std::move(ptr_2_u);
    }
    std::cout << ptr_u << "\n";
  }
  std::cout << "end auto_ptr:\n\n";
}

void sharedPointer() {
  std::cout << "shared_ptr:\n";
  {
    // shared _pointer
    // std::shared_ptr<int> ptr(new int(13));   //<-- not correct way to create
    // shared_ptr
    std::shared_ptr<A> ptr = std::make_shared<A>(13);

    std::cout << ptr << "\n";

    {
      std::shared_ptr<A> ptr_2 = ptr;
      *ptr_2 += 2;
      std::cout << ptr_2 << "\n";
    }
    std::cout << ptr << "\n";
  }
  std::cout << "end shared_ptr:\n\n";
}

void funWeakPointer() {
  std::cout << "shared_ptr:\n";
  {
    // shared _pointer
    // std::shared_ptr<int> ptr(new int(13));   //<-- not correct way to create
    // shared_ptr
    std::shared_ptr<A> ptr = std::make_shared<A>(13);

    std::cout << ptr << "\n";

    {
      std::weak_ptr<A> ptr_2 = ptr;
      // *ptr_2 +=2;
      std::cout << ptr_2 << "\n";
    }
    std::cout << ptr << "\n";
  }
  std::cout << "end shared_ptr:\n\n";
}