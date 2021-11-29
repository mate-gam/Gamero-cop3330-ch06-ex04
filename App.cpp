#include <iostream>
#include <vector>
using namespace std;
class Name_value
{
    public:
        int value;
        string name;
};

ostream& operator<<(ostream &out, const Name_value &comp)
{
    return out;
}

int main()
{
    vector<Name_value*> values;
    string name;
    int value, numOfValues = 0;
    do
    {
        cout << "Please enter a name with Value: ";
        cin >> name >> value;
        int flag = 0;
        if (name == "NoName" && value == 0)
        {
            break;
        }
        for(int i = 0; i < values.size(); i++)
        {
            if (name == values[i]->name && value == values[i]->value)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            values.resize(numOfValues);
            values.push_back(new Name_value{value, name});
            numOfValues++;
        }
        else
        {
            cout << "Try again that name and value is used before \n";
        }
    } while (name != "NoName" || value != 0);
    
    for(int i = 0; i < values.size(); i++)
    {
        cout << values[i]->name << " ";
        cout << values[i]->value << "\n";
    }

    for (auto i : values) {
        delete i;
    }
}
