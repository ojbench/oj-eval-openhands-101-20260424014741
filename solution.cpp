
#include <iostream>
using namespace std;

int main() {
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    
    // Convert current time to total seconds
    long long current_seconds = f * b * a + e * a + d;
    
    // Total seconds in one day
    long long day_seconds = c * b * a;
    
    // We need to find the smallest t > 0 such that:
    // (current_seconds + t) % (b*a) == (current_seconds + t) % a == (current_seconds + t) % (b*a*c)
    // But since hour hand only moves once per day, we need:
    // hour_value = minute_value = second_value
    
    // Let's simulate time forward until we find a match
    for (long long t = 1; t <= day_seconds; t++) {
        long long total = current_seconds + t;
        if (total >= day_seconds) {
            total -= day_seconds; // wrap around
        }
        
        long long seconds = total % a;
        long long minutes = (total / a) % b;
        long long hours = (total / (a * b)) % c;
        
        if (hours == minutes && minutes == seconds) {
            cout << t << endl;
            return 0;
        }
    }
    
    // If no solution found within one day, output day_seconds (next day)
    cout << day_seconds << endl;
    return 0;
}
