#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int testCases;
	
	cin >> testCases;
	
	while(testCases--) {
	    int totalNumbers, k;

        cin >> totalNumbers;
        
	    int numbers[totalNumbers];
	    
	    for(int i = 0; i < totalNumbers; i++) 
			cin >> numbers[i];
		
		cin >> k;

		sort(numbers, numbers+totalNumbers);

		cout << numbers[k-1] << endl;

		delete numbers;
	}
	
	return 0;
}