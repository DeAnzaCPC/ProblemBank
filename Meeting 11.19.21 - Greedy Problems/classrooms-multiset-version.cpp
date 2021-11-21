#include <set>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Does not work in python because python does not have a fast sorted data structure.
*/
struct Activity {
	int start, end;

	bool operator<(const Activity &other)const {
		return end < other.end;
	}

};


int main() {
	int num_activities, num_classrooms;
	cin >> num_activities >> num_classrooms;

	multiset<int> classrooms;
	vector<Activity> activities;
	for (int i = 0; i < num_activities; i++) {
		struct Activity a;
		cin >> a.start >> a.end;
		activities.push_back(a);
	}
	sort(activities.begin(), activities.end());
	int num_possible_act = 0;
	for (int i = 0; i < num_activities; i++) {
		auto it = classrooms.upper_bound(-activities[i].start);
		if (it == classrooms.end() && classrooms.size() < num_classrooms) {
			num_possible_act++;
			classrooms.insert(-activities[i].end);
			continue;
		}
		if (it != classrooms.end()) {
			classrooms.insert(-activities[i].end);
			num_possible_act++;
			classrooms.erase(it);
		}
		
	}
	cout << num_possible_act << endl;
	return 0;
}