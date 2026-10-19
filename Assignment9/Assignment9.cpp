#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream& operator<<(ostream& out, const vector<int>& table) {
    for (auto& e : table)
        out << e << " ";
    return out;
}

bool greaterThan(int value){
	return value > 15;
}

bool isOdd(int value){
    return ((value % 2) != 0);
}

bool closeEnough(int a, int b){
    return abs(a-b) <= 2;
}

int main() {
    vector<int> v1 = { 3, 3, 12, 14, 17, 25, 30 };
    cout << "v1: " << v1 << endl;

    vector<int> v2 = { 2, 3, 12, 14, 24 };   // 2, 3, 12, 14, 24
    cout << "v2: " << v2 << endl;

    vector<int> dest(v1.size());
        // A
	auto pos = find_if(v1.begin(), v1.end(), greaterThan);
	if(pos != v1.end()){
		cout << "Det forste element storre enn 15 er paa indeks " << (pos - v1.begin());
	} else {
		cout << "Det er ingen elementer storre enn 15";
	}
        // B
    if(equal(v1.begin(), (v1.begin()+5), v2.begin(), closeEnough)){
        cout << "\nDe er like";
    } else{
        cout << "\nDe er ikke like";
    }

     if(equal(v1.begin(), (v1.begin()+4), v2.begin(), closeEnough)){
        cout << "\nDe er like";
    } else{
        cout << "\nDe er ikke like";
    }


        //  C
    replace_copy_if(v1.begin(), v1.end(), dest.begin(),
            [] (int n) {return n % 2 != 0;}, 100
        );
    
    cout << "\n" << dest;
}