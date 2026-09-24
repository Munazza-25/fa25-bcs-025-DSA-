#include <iostream>
using namespace std;

const int CAPACITY = 20;
struct ArrayList
{
    int data[CAPACITY];
    int size = 0;
};
bool insertEnd(ArrayList &list, int value)
{
    if (list.size >= CAPACITY) {
        return false;
    }
    list.data[list.size] = value;
    list.size++;
    return true;
}
bool insertAtBeginning(ArrayList &list, int value)
{
    if (list.size >= CAPACITY) {
    	
        return false;
    }
    for (int i = list.size; i > 0; i--) {
    	
        list.data[i] = list.data[i - 1];
        
    }
    list.data[0] = value;
    list.size++;
    return true;
}
bool deleteAtPosition(ArrayList &list, int position)
{
    if (position < 0 || position >= list.size)   {
    	
        return false;
    }
    
    for (int i = position; i < list.size - 1; i++)  {
    	
        list.data[i] = list.data[i + 1];
    }
    list.size--;

    return true;
}
void displayList(ArrayList &list) {
	
    for (int i = 0; i < list.size; i++)  {
        cout << list.data[i] << " ";
    }

    cout << endl;
}
int main()
{
    ArrayList list;
    
    int *ptr = list.data;
    int *minPtr = list.data;
    int *maxPtr = list.data;
    int *medianPtr = list.data;
    int *closestPtr = list.data;
    int sum = 0;
    int closestPosition;
    double generalAverage;
    double specialAverage;
    double averageDifference;
    double finalScore;

    insertEnd(list, 18);
    insertEnd(list, 7);
    insertEnd(list, 45);
    insertEnd(list, 11);
    insertEnd(list, 36);
    insertEnd(list, 25);   
    insertEnd(list, 21);
    insertEnd(list, 13);
    insertEnd(list, 29);
    cout << "Initial ArrayList: ";
    displayList(list);
    ptr = list.data;
    minPtr = list.data;
    maxPtr = list.data;

    sum = 0;
    for (int i = 0; i < list.size; i++)
    {
        sum = sum + *ptr;
        if (*ptr < *minPtr)
        {
            minPtr = ptr;
        }
        if (*ptr > *maxPtr)
        {
            maxPtr = ptr;
        }
        ptr++;
    }
    cout << "Minimum Value: " << *minPtr << endl;
    cout << "Maximum Value: " << *maxPtr << endl;

    int temp[CAPACITY];
    for (int i = 0; i < list.size; i++)
    {
        temp[i] = list.data[i];
    }
    for (int i = 0; i < list.size - 1; i++)
    {
        for (int j = 0; j < list.size - i - 1; j++)
        {
            if (temp[j] > temp[j + 1])
            {
                int x = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = x;
            }
        }
    }
    int medianValue = temp[list.size / 2];

    medianPtr = list.data;
    for (int i = 0; i < list.size; i++)
    {
        if (*medianPtr == medianValue)
        {
            break;
        }
        medianPtr++;
    }
    cout << "Median Value: " << *medianPtr << endl;
    cout << "Sum: " << sum << endl;
    generalAverage = (double)sum / list.size;
    specialAverage =
        (*minPtr + *medianPtr + *maxPtr) / 3.0;


    ptr = list.data;
    closestPtr = list.data;
    double difference;
    double smallestDifference;

    difference = *ptr - specialAverage;
    if (difference < 0)
    {
        difference = -difference;
    }
    smallestDifference = difference;
    for (int i = 0; i < list.size; i++)
    {
        difference = *ptr - specialAverage;
        if (difference < 0)
        {
            difference = -difference;
        }
        if (difference < smallestDifference)
        {
            smallestDifference = difference;
            closestPtr = ptr;
        }
        ptr++;
    }
    
    closestPosition = closestPtr - list.data;
    
    cout << "General Average: " << generalAverage << endl;
    cout << "Special Average: " << specialAverage << endl;
    cout << "Closest Value: " << *closestPtr << endl;
    cout << "Position of Closest Value: " << closestPosition << endl;

    averageDifference =  generalAverage - specialAverage;
    
    if (averageDifference < 0) {
    	
        averageDifference = -averageDifference;
    }
    
    double difference1;
    
    double difference2;
    
    difference1 =  *closestPtr - generalAverage;
    if (difference1 < 0){
        difference1 = -difference1;
    }
    difference2 =*closestPtr - specialAverage;
        
    if (difference2 < 0)  {
        difference2 = -difference2;
    }
    
    finalScore = difference1 + difference2 +averageDifference;
    cout << "Difference Between Averages: "     << averageDifference << endl;
    cout << "Final Score: " << finalScore << endl;

    closestPosition = closestPtr - list.data;
    
    deleteAtPosition(list, closestPosition);
    
    cout << "ArrayList After Deletion: ";
    displayList(list);
    
    int roundedSpecialAverage;
    
    if (specialAverage - (int)specialAverage >= 0.5){
    	
        roundedSpecialAverage =(int)specialAverage + 1;
        
    }
    else    {
    	
        roundedSpecialAverage =(int)specialAverage;
        
    }
    
    insertAtBeginning(list, roundedSpecialAverage);
    
    cout << "Final ArrayList After Insertion: ";
    
    displayList(list);
    
    return 0;
}

