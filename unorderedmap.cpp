#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	
    unordered_map<string, double> umap;

	// inserting values by using [] operator
	umap["GeeksforGeeks"] = 10;
	umap["Practice"] = 20;
	umap["Contribute"] = 30;
	cout<<umap["Practice"]<<endl;
	// Traversing an unordered map
	for (auto x : umap)
	cout << x.first << " " << x.second << endl;

    cout<<endl;
    auto x = umap.find("Practice");
    
    umap.insert(make_pair("you",67));
    umap.insert(x,{"we",22});
    // unordered_map<string, double>:: iterator itr;
    cout << "\nAll Elements : \n";
    for (auto itr = umap.begin(); itr != umap.end(); itr++)
    {
        
        cout << itr->first << " " << itr->second << endl;
     }


    //umap.erase("we");

     string key = "we";
    if (umap.find(key) == umap.end())
        cout << key << " not found\n";
    else
        cout << "Found " << key << endl;

}
