#include <exception>

class SampleClass{
  public:
    SampleClass() : x(5) {}
    SampleClass(int y) : x(y) {}
    SampleClass(const SampleClass &other);
    virtual ~SampleClass();  //This is a destructor.  If the tilde looks weird, that's Blackboard's fault.
    SampleClass& operator=(const SampleClass &other);
    void foo();
  private:
    int x;
};

class PublicClass : public SampleClass {
  public:
    PublicClass(int y);
};

class ProtectedClass : protected SampleClass {
  protected:
    int z;
};

int main() {
  SampleClass *s1 = new ProtectedClass();
  PublicClass *p1 = new SampleClass();
  PublicClass p2;
  p2.foo();
  s1->foo();
  return 0;
}