#include <excpetion>
class Peg {
  public:
	Peg(int n); //creates a peg capable of holding n discs.
	Peg(const Peg &other); //deep copy constructor
	~Peg();  // This is a destructor.  If the tilde looks weird, that's Blackboard's fault.
	int removeTop(); //removes the top disc and returns it, or throws an exception if none.  O(1)
	void addToTop(int d);  //adds d to top of this peg, or throws an exception if invalid.  O(1)
  private:
	int maxSize;
	int size;
	int* data;
	
};
class Towers {
  public:
	Towers(int n); //creates the towers with n discs.
	Towers(const Towers &other); //deep copy constructor.
	~Towers(); // This is a destructor.  If the tilde looks weird, that's Blackboard's fault.
	//moves top disc from peg source to peg dest.  If invalid, throw an exception.  You may assume source and dest are between 0 and 2.  O(1)
	void Move(int source, int dest);
  private:
	Peg* pegs;
};
 
Peg::Peg(int n){
	maxSize = n;
	size = 0;
	data = new int[maxSize];
}
Peg::Peg(const Peg& other){
	maxSize = other.maxSize;
size = other.size;
	data = new int[maxSize];
	for(int i = 0 ; i < size ; i++){
		data[i] = other.data[i];
	}
}
Peg::~Peg(){ delete [] data;}
int Peg::removeTop(){
	if(size == 0) {throw exception; return 0;}
	else{ 
		size--;
		return data[size];
	}
}
void Peg::addToTop(int d){
	if(size == maxSize) { throw exception;}
	else{
		data[size] = d;
		size++; 
	}
}
Towers::Towers(int n){
	pegs = new Peg[3];
	for(int i = n-1 ; i >= 0 ; i--){
		pegs[0].addToTop(i);
	}
}
Towers::Towers(const Towers &other){
	pegs = new Peg[3];
	for(int i = 0 ; i < 3 ; i++){
		pegs[i] = other.pegs[i];
	}
}
Towers::~Towers(){
	for(int i = 0 ; i < 3 ; i++){
		delete pegs[i];
	}
	delete [] pegs;
}
void Towers::Move(int source, int dest){
	try{
		pegs[dest].addToTop(pegs[source].removeTop());
	} catch(Exception& e) {
		throw e;
	}
}
