//Program for longest nap problem.
#include <bits/stdc++.h>
using namespace std;
const int TOTAL_MINUTES = 8 * 60;
int main()
{
 std::string junk;
 
 int N;
 
 int T = 1;
 
 vector<bool> timeAvailable(TOTAL_MINUTES + 2);
 timeAvailable[TOTAL_MINUTES + 1] = false;
 
 while (cin >> N)
 {
 for (int i = 0; i <= TOTAL_MINUTES; ++i)
 timeAvailable[i] = true;
 
 
 while (N--)
 {
 int startHr, startMin, endHr, endMin;
 int startTime, endTime;
 char startSeparator, endSeparator;
 
 cin >> startHr >> startSeparator >> startMin >> endHr >> endSeparator >> endMin;
 getline(cin, junk);
 startTime = (startHr - 10) * 60 + startMin;
 endTime = (endHr - 10) * 60 + endMin;
 
 for (int i = startTime; i < endTime; ++i)
 timeAvailable[i] = false;
 }
 
 int bestStartTime, bestLength = 0;
 
 for (int i = 0; i <= TOTAL_MINUTES; ++i)
 {
 if (timeAvailable[i])
 {
 int j = i + 1;
 
 while (timeAvailable[j])
 ++j;
 
 if (j == TOTAL_MINUTES + 1)
 --j;
 
 if (j - i > bestLength)
 {
 bestStartTime = i;
 bestLength = j - i;
 }
 
 i = j;
 }
 }
 
 if (bestLength >= 60)
 printf("Day #%d: the longest nap starts at %d:%02d and will last for %d hours and %d 
minutes.\n", 
 T++, bestStartTime / 60 + 10, bestStartTime % 60, bestLength / 60, bestLength % 60);
 else
 printf("Day #%d: the longest nap starts at %d:%02d and will last for %d minutes.\n", 
 T++, bestStartTime / 60 + 10, bestStartTime % 60, bestLength);
 }
}
//  Input:
// 4
// 10:00 12:00 Lectures
// 12:00 13:00 Lunch, like always.
// 13:00 15:00 Boring lectures...
// 15:30 17:45 Reading
// 4
// 10:00 12:00 Lectures
// 12:00 13:00 Lunch, just lunch.
// 13:00 15:00 Lectures, lectures... oh, no!
// 16:45 17:45 Reading (to be or not to be?)
// 4
// 10:00 12:00 Lectures, as everyday.
// 12:00 13:00 Lunch, again!!!
// 13:00 15:00 Lectures, more lectures!
// 15:30 17:15 Reading (I love reading, but should I schedule it?)
// 1
// 12:00 13:00 I love lunch! Have you ever noticed it? :)
//  Output :
// Day #1: the longest nap starts at 15:00 and will last for 30 minutes.
// Day #2: the longest nap starts at 15:00 and will last for 1 hours and 45 minutes.
// Day #3: the longest nap starts at 17:15 and will last for 45 minutes.
// Day #4: the longest nap starts at 13:00 and will last for 5 hours and 0 minutes.