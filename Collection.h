// Chris Schultz
// COSC 2030
// HW 2: Collection Class to Store Objects
// 24 September 2017

#ifndef COLLECTION_H
#define COLLECTION_H

template <class O>
class Collection{
	// keeping the "actual size of the array" and "size of the values put in manually" separate
    int size;
    O * objArray;
	int arraySize;
public:
    // constructor - use an arbitrary number for the array size since it can be changed later
    Collection(){
        size = 0;
		arraySize = 3;
        objArray = new O[arraySize];
    }
   
	// destructor, pretty standard
	~Collection(){
        delete [] objArray;
    }

    // public member functions
	bool isEmpty() {
		if (size == 0) {
			cout << "The array is empty. " << endl;
			return true;
		}
		else {
			cout << "There are objects in the array. " << endl;
			return false;
		}
	}
	
	// deletes whatever was in objArray and creates new one
	// with same parameters as constructor
	void makeEmpty() {
		delete[] objArray;
		size = 0;
		arraySize = 3;
		objArray = new O[arraySize];
	}
	
	// if the array is full, it copies the array to one a size bigger so it can
	// insert at the end
	void insert(O entry) {
		if (size == arraySize) {
			arraySize = (arraySize + 1);
			O * temp = new O[arraySize];
			for (int i = 0; i < arraySize; i++) {
				temp[i] = objArray[i];
			}
			delete[] objArray;
			objArray = temp;
		}
		objArray[size] = entry;
		size++;
	}
   
	// if it finds an object that is the argument it changes value to 0
	// then shifts all furthur values 1 to the right, effectively deleting the entry
	void remove(O entry) {
		for (int i = 0; i < size; i++) {
			if (objArray[i] == entry) {
				objArray[i] = 0;
				for (int j = i; j < size; j++) {
					objArray[j] = objArray[j + 1];
				}
				size--;
			}
		}
	}
    
	// generates a random index value and then removes the object at that index
	// and shifts values 1 to the left as per remove() function
	void removeRandom() {
		int r = rand() % size;
		objArray[r] = 0;
		for (int i = r; i < size; i++) {
			objArray[i] = objArray[i + 1];
		}
		size--;
	}
   
	// returns false if it finds a matching object
	// returns true if it cannot find one
	bool notContained(O entry) {
		for (int i = 0; i < size; i++) {
			if (objArray[i] == entry) {
				return false;
			}
		}
		cout << "No matching object. " << endl;
		return true;
	}
	
	// print function, prints out one at a time
	void print() {
		for (int i = 0; i < size; i++) {
			cout << objArray[i] << ",";
		}
		cout << endl;
	}
};

#endif
