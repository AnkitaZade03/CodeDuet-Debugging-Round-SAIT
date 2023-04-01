// CodeDuet 2k23 Round 3

// You have a class named YoutubeChannel which contains Subscriberscount and Name of channel
// Also there is another class called MyChannels where you can add channels to your list and delete as well
// You need to make the required changes such that the different operations like printing , += ... works properly

// Following code contains both syntax and logical errors.

#include <iostream>
#include <string>
#include <list>
using namespace std;

class YoutubeChannel
{
public:
    int SubscribersCount;
    string Name;

    YoutubeChannel(string name, int subscribersCount)
    {
        Name = name;
        SubscribersCount = subscribersCount;
    }
};

void operator<<(ostream &COUT, YoutubeChannel &ytChannel)
{
    COUT << "Name: " << ytChannel.Name << endl;
    COUT << "Subcribers: " << ytChannel.SubscribersCount << endl;
};

class MyCollection
{
public:
    list<YoutubeChannel> myChannels;

    void operator+=(YoutubeChannel &channel)
    {
        this->myChannels.push_back(channel);
    }

    void operator-=(YoutubeChannel &channel)
    {
        this->myChannels.remove(channel);
    }
};

void operator<<(ostream &COUT, MyCollection &myCollection)
{
    for (YoutubeChannel ytchannel : myCollection.myChannels)
    {
        COUT << ytchannel << endl;
    }
}

int main()
{
    // Creating 2 channels named TechFusion and SAIT
    YoutubeChannel yt1 = new YoutubeChannel("TechFusion", 5000);
    YoutubeChannel yt2 = new YoutubeChannel("SAIT", 6000);

    cout << yt1 << yt2;
    cout << endl;

    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2;
    cout << myCollection;
    cout << endl;

    myCollection -= yt2;
    cout << myCollection;

    return 0;
}
