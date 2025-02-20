#include <iostream>
using namespace std;

class Time
{
public:
    int hours, minutes, seconds;
    void settime(int h, int m, int s);
    void showtime();
    Time add(Time);
    Time diff(Time);
    void normalize();
};
void Time ::normalize()
{
    if (seconds >= 60)
    {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (minutes >= 60)
    {
        hours += minutes / 60;
        minutes %= 60;
    }
}
void Time ::settime(int h, int m, int s)
{
    hours = h;
    minutes = m;
    seconds = s;
}

void Time ::showtime()
{
    cout << "Time is:" << endl;
    cout << hours << ":" << minutes << ":" << seconds << endl;
}
Time Time::add(Time t2)
{
    Time t;
    t.hours = hours + t2.hours;
    t.minutes = minutes + t2.minutes;
    t.seconds = seconds + t2.seconds;
    t.normalize();
    return t;
}
Time Time ::diff(Time t2)
{
    Time res;
    if (seconds < t2.seconds)
    {
        res.seconds = seconds + 60 - t2.seconds;
        minutes--;
    }
    else
    {
        res.seconds = seconds - t2.seconds;
    }
    if (minutes < t2.minutes)
    {
        res.minutes = minutes + 60 - t2.minutes;
        hours--;
    }
    else
    {
        res.minutes = minutes - t2.minutes;
    }
    res.hours = hours - t2.hours;
    if (res.hours < 0)
    {
        res.hours = res.hours;
    }
    return res;
}
int main()
{
    Time t1, t2, t3;
    int h1, m1, s1;
    int h2, m2, s2;

    cout << "Enter Hours:Min:sec" << endl;
    cin >> h1 >> m1 >> s1;

    cout << "Enter Hours:Min:sec" << endl;
    cin >> h2 >> m2 >> s2;
    // Set time for t1 and t2
    t1.settime(h1, m1, s1);
    t2.settime(h2, m2, s2);

    // Add t1 and t2
    t3 = t1.add(t2);

    // Display the times
    cout << "t1: ";
    t1.showtime();

    cout << "t2: ";
    t2.showtime();

    cout << "Sum of t1 and t2: ";
    t3.showtime();

    t3 = t1.diff(t2);

    cout << "sub of t1 and t2 : ";
    t3.showtime();

    return 0;
}