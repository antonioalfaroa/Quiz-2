#include <iostream>

using namespace std;

class clockType{
  public:
    clockType(){
      hr = 0;min = 0;sec=0;
    }
clockType(int, int, int);
    void setTime(int hours, int minutes, int seconds);
    void getTime(int&, int&, int&) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType&) const;
  private:
    int hr;
    int min;
    int sec;
};

void clockType::setTime(int hours, int minutes, int seconds) {
  if (0 <= hours && hours < 24) hr = hours;
  else hr = 0;
  
  if (0 <= minutes && minutes < 60) min = minutes;
  else min = 0;
  
  if (0 <= seconds && seconds < 60) sec = seconds;
  else sec = 0;
}
void clockType::getTime(int& hours, int& minutes, int& seconds) const{
  hours = hr;
  minutes = min;
  seconds = sec;
}
void clockType::printTime() const{
  if (hr < 10)
    cout << "0";
    cout << hr << ":";
  if (min < 10)
    cout << "0";
    cout << min << ":";
  if (sec < 10)
    cout << "0";
    cout << sec;
}
void clockType::incrementHours(){
  hr++;
  if (hr > 23) hr = 0;
}
void clockType::incrementMinutes(){
  min++;
  if (min > 59){
    min = 0;
    incrementHours(); //increment hours
  }
}
void clockType::incrementSeconds(){
  sec++;
  if (sec > 59){
    sec = 0;
    incrementMinutes(); //increment minutes
  }
}
bool clockType::equalTime(const clockType& otherClock) const {
  return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}
clockType::clockType(int ho, int mi, int se){
  setTime(ho,mi,se);
}


class extClockType : public clockType{
private:
string timeZone;




public:
extClockType():clockType(){
  timeZone = "empty";
}
extClockType(int ho,int mi,int se,string timeZ) : clockType(ho,mi,se){
  
  timeZone = timeZ;
}
void printTime(){
  clockType::printTime();
  cout<<endl<<"Actual time zone : "<<" "<<timeZone<<endl;
}
void set_timeZone(string timeZ){
  timeZone = timeZ;
}
string get_timeZone(){
  return timeZone;
}


};

int main(){

  extClockType firstHour(12,34,45, "PT");
  extClockType secHour(04,52,11, "AT");
  cout<<"Time 1 : "<<endl;
  firstHour.printTime();
  cout<<endl<<"Time 2 : "<<endl;
  secHour.printTime();

  cout<<"Incrementing minutes : "<<endl;
  firstHour.incrementMinutes();
  secHour.incrementMinutes();
  cout<<"Time after minutes incremention : "<<endl;
  cout<<"Time 1 : "<<endl;
  firstHour.printTime();
   cout<<"Time 2 : "<<endl;
  secHour.printTime();

  cout<<"Incrementing seconds : "<<endl;
  firstHour.incrementSeconds();
  secHour.incrementSeconds();
  cout<<"Time after seconds incremention : "<<endl;
  cout<<"Time 1 : "<<endl;
  firstHour.printTime();
   cout<<"Time 2 : "<<endl;
  secHour.printTime();

  cout<<"Incrementing hours : "<<endl;
  firstHour.incrementHours();
  secHour.incrementHours();
  cout<<"Time after hours incremention : "<<endl;
  cout<<"Time 1 : "<<endl;
  firstHour.printTime();
   cout<<"Time 2 : "<<endl;
  secHour.printTime();
}