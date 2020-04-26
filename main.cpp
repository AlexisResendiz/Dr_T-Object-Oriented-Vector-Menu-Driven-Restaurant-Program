//A Restaurant Project Class style Dr_T Dr. Tyson McMillan 

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream> // write to txt file
//#include <unistd.h> //for sleep command. line 302 explains why I stopped using this
using namespace std; 

//****************STRUCT STYLE***************/
struct MenuItem
{
  string name;
  double itemCost; 
  string desc; 
  char addLetter; 
  char removeLetter;
  int count; 
};

//*****************CLASS STYLE*****************/
class MenuItemList
{
  private:
    string name;
    double itemCost; 
    string desc; 
    char addLetter; 
    char removeLetter;
    int count;
  public:
    void setName(string n) { name = n; }
    void setItemCost(double it) { itemCost = it; }
    void setDesc(string d) { desc = d; }
    void setAddLetter(char aL) { addLetter = aL; }
    void setRemoveLetter(char rL) { removeLetter = rL; }
    void setCount(int c) { count = c; }
    string getName() const { return name; }
    double getItemCost() const { return itemCost; }
    string getDesc() const { return desc; }
    char getAddLetter() const { return addLetter; }
    char getRemoveLetter() const { return removeLetter; }
    int getCount() const { return count; }
};

//**********STRUCT STYLE***********/
//function definitions
void populateMenu(vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItem Item1; 
  MenuItem Item2;
  MenuItem Item3; 
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Burrito", "Tamales", "Shrimp", "Ramen", "Tacos", "Pizza"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].name = defaultMenuNames[i]; 
    entireMenu[i].addLetter = defaultAddLetters[i]; 
    entireMenu[i].removeLetter = defaultRemoveLetters[i]; 
    entireMenu[i].itemCost = (3.00 + i); //set a random starter cost for each item
    entireMenu[i].count = 0; //initialze all counts to 0
    entireMenu[i].desc = "delicious"; //set all default desc to "delicous"
  }


}

//**********CLASS STYLE***********/
void populateObjectMenu(vector<MenuItemList> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItemList Item1; //Item1 is an object
  MenuItemList Item2;
  MenuItemList Item3; 
  MenuItemList Item4;
  MenuItemList Item5;
  MenuItemList Item6;
  MenuItemList Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Burrito", "Tamales", "Shrimp", "Ramen", "Tacos", "Pizza"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].setName(defaultMenuNames[i]);
    entireMenu[i].setAddLetter(defaultAddLetters[i]);
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]);
    entireMenu[i].setItemCost(3.00 + i); //set a random starter cost for each item
    entireMenu[i].setCount(0); //initialze all counts to 0
    entireMenu[i].setDesc("delicious"); //set all default desc to "delicous"
  }


}


//*************STRUCT STYLE**************/
void showMenu(vector<MenuItem> &m)
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << "DrT's Effcient Menu" << endl; 
  cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << m[i].addLetter << ")" << setw(10) << m[i].name 
    << setw(5) << "$" << m[i].itemCost << setw(5) << "(" << m[i].removeLetter
    << ")" << setw(7) << m[i].count << setw(13) << m[i].desc 
    <<endl; 
  }

}

//*************CLASS STYLE**************/
void showObjectMenu(vector<MenuItemList> &m)
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << "DrT's Effcient Object Menu" << endl; 
  cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << m[i].getAddLetter() << ")" << setw(10) << m[i].getName()
    << setw(5) << "$" << m[i].getItemCost() << setw(5) << "(" << m[i].getRemoveLetter()
    << ")" << setw(7) << m[i].getCount() << setw(13) << m[i].getDesc()
    <<endl; 
  }

}


//*************STRUCT STYLE**************/
void acceptOrder(vector<MenuItem> &m)
{
  char option = '\0';// the user-selected menu item
  double subtotal = 0.0; 

  do
  {
    cout << "\nPlease choose an item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      if(option == m[i].addLetter)
      {
        cout << "\nMenu Item " << m[i].addLetter << " selected."; 
        m[i].count++; //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].name << endl;
        subtotal += m[i].itemCost; //increment the subtotal by the cost of the item 
        showMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].removeLetter)
      {
        cout << "\nRemove Item " << m[i].removeLetter << " selected."; 
        if(m[i].count > 0) //subtract if and only if the count is > 0
        {
          m[i].count--; //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].name << endl;
          subtotal -= m[i].itemCost; //decrement the subtotal by the cost of the item
          showMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].name << endl;
        }
      }
      else if(
                option != m[i].addLetter && 
                option != m[i].removeLetter &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
  cout << "\nThank you for placing your order." << endl;
  cout << "\n";

  //handle the tip process here
  //calculate total due + tax + tip
  //accept payment type
  //handle cash vs credit
  //handle on-screen receipt generation here
  //handle reciept generation here
}


//*************CLASS STYLE**************/
void acceptObjectOrder(vector<MenuItemList> &m)
{
  char option = '\0';// the user-selected menu item
  double subtotal = 0.0;
  double change = 0.0;

  do
  {
    cout << "\nPlease choose an item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      if(option == m[i].getAddLetter())
      {
        cout << "\nMenu Item " << m[i].getAddLetter() << " selected."; 
        m[i].setCount(m[i].getCount()+1); //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].getName() << endl;
        subtotal += m[i].getItemCost(); //increment the subtotal by the cost of the item 
        showObjectMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].getRemoveLetter())
      {
        cout << "\nRemove Item " << m[i].getRemoveLetter() << " selected."; 
        if(m[i].getCount() > 0) //subtract if and only if the count is > 0
        {
          m[i].setCount(m[i].getCount()-1); //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].getName() << endl;
          subtotal -= m[i].getItemCost(); //decrement the subtotal by the cost of the item
          showObjectMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].getName() << endl;
        }
      }
      else if(
                option != m[i].getAddLetter() && 
                option != m[i].getRemoveLetter() &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            
    }
  }while(option != 'x' && option != 'X'); 
  cout << "\nThank you for placing your order." << endl;

  cout << "\nWould you like to tip? Y for yes, N for no. ";
  cin >> option;
  if(option == 'y' || option == 'Y')
  {
    double tip = (subtotal * .20);
    double tax = 0.0825 * subtotal;
    double finalTotal = tax + subtotal;
    cout << "\nThe tip wil be: $" << tip << endl;
    cout << "\nWould you like to pay cash or card. Q for CASH, V for CARD: ";;
    cin >> option;
      if(option == 'q' || option == 'Q')
      {
        cout << "\nGive me my money." << endl;
      }
      else if(option == 'v' || option == 'V')
      {
        cout << "\nPlease swipe your card.";
        //sleep(2); //pause 2 seconds. couldn't figure out how to make it work it kept freezing when I added it and wasn't continuing the program
        for(int z = 0; z < 13; z++)
        {
          cout << z;
        }
      }
    cout << "\nThe total due will be: $" << finalTotal + tip << endl;
    cout << "\nEnter the amount given: $";
    cin >> change;
    if(change < (finalTotal + tip))
    {
      do
      {
        cout << "\nPlease povide an appropriate amount. " << endl;
        cin >> change;
      }while(change < (finalTotal + tip));
    }
    cout << "\nThe change will be: $" << change - (finalTotal + tip) << endl;
    cout << "\nThank you for your visit. " << endl;
  }
  else if(option == 'n' || option == 'N')
  {
    double tax = 0.0825 * subtotal;
    double finalTotal = tax + subtotal;
    double pay = 0.0;

    cout << "\nWould you like to pay cash or card. Q for CASH, V for CARD: ";
    cin >> option;
      if(option == 'q' || option == 'Q')
      {
        cout << "\nGive me my money." << endl;
      }
      else if(option == 'v' || option == 'V')
      {
        cout << "\nPlease swipe your card." << endl;
        for(int z = 0; z < 13; z++)
        {
          cout << z;
        }
      }
      else
      {
        cout << "Please enter the letters that are being shown " << endl;
      }
    cout << "\nThe total due will be: $" << finalTotal << endl;
    cout << "\nEnter the amount given: $";
    cin >> change;
    if(change < finalTotal)
    {
      do
      {
        cout << "\nPlease povide an appropriate amount. " << endl;
        cin >> change;
      }while(change < finalTotal);
    }
    
    cout << "\nThe change will be: $" << change - finalTotal << endl;
    cout << "\nThank you for your visit. " << endl;

  }
  //handle the tip process here
  //calculate total due + tax + tip
  //accept payment type
  //handle cash vs credit
  //handle on-screen receipt generation here
  //handle reciept generation here
}

void printText(vector<MenuItemList> &m)
{
  fstream rec; //rec = receipt
  rec.open("receipt.txt",ios::out);

  rec << m[0].getName() << endl;
  rec << m[0].getItemCost() << endl;
  
  

  rec.close();

}

int main() 
{

//*******STRUCT STYLE********/
  vector<MenuItem> wholeMenu; 
  populateMenu(wholeMenu); //put some default values in the menu
  showMenu(wholeMenu); //print the current data of the menu on screen 
  acceptOrder(wholeMenu); 


//*******CLASS STYLE********/
vector<MenuItemList> objectMenu;
populateObjectMenu(objectMenu); //put some default values in the menu
showObjectMenu(objectMenu); //show the initial menu on screen
acceptObjectOrder(objectMenu);
//solve and call acceptObjectOrder void function here

printText(objectMenu);
  
  return 0; 
}