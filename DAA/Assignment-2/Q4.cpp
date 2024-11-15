#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelector(vector<Activity>& activities) {
    int n = activities.size();
    
    // Sort activities based on finish time
    sort(activities.begin(), activities.end(), compare);
    
    cout << "Selected activities: ";
    int i = 0;
    cout << "(" << activities[i].start << ", " << activities[i].finish << ") ";
    
    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            cout << "(" << activities[j].start << ", " << activities[j].finish << ") ";
            i = j;
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    
    vector<Activity> activities(n);
    cout << "Enter start and finish time of each activity: \n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
    }
    
    activitySelector(activities);
    
    return 0;
}
