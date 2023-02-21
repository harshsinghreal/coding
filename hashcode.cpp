#include<bits/stdc++.h>
using namespace std;

int main() {
    int contributors, projects;
    cin >> contributors >> projects;
    vector<string> contributors_name;
    vector<string> projects_name;
    map<pair<string, int>, set<pair<string, int>>> contri;
    map<pair<string, vector<int>>, set<pair<string, int>>> proj;
     vector<int> utility;
    while (contributors--) {
        set<pair<string, int>> skills;
        string name;
        cin >> name;
        contributors_name.push_back(name);
        int no_of_skills;
        cin >> no_of_skills;
        while (no_of_skills--) {
            string skill_name;
            cin >> skill_name;
            int level;
            cin >> level;
            skills.insert({skill_name, level});
        }
        contri[{name, no_of_skills}] = skills;
    }

    while (projects--) {
        set<pair<string, int>> skills;
        string name;
        cin >> name;
        projects_name.push_back(name);
        int days;
        cin >> days;
        int score;
        cin >> score;
        int best_before;
        cin >> best_before;
        int no_of_roles;
        cin >> no_of_roles;
        vector<int> utility{days, score, best_before, no_of_roles};
        while (no_of_roles--) {
            string skill_name;
            cin >> skill_name;
            int level;
            cin >> level;
            skills.insert({skill_name, level});
        }
        proj[{name, utility}] = skills;
    }

    int executed = 0;
    cout<<endl<<endl<<endl;
    for (int i = 0; i < projects_name.size(); i++) {
        cout<<utility[0,0,0,0]<<endl;
    }
    
    return 0;
}