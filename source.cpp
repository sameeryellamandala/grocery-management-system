#include <iostream>
using namespace std;

class Validity{

public:

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

string toLower(const string& str) {
    string result = str;
    for (char& c : result) {
        c = toLower(c);
    }
    return result;
}
};

class staff {

  string proname[50];
  float SP[50];
  float CP[50];
  int quantity[50];
  int i;

  float Billamt = 0;
  float Billcpsum = 0;

public:
  staff()
  { // constructor
    string n[50];
    float s[50];
    float c[50];
    int q[50];

    for (int i = 1; i < 20; ++i)
    {
      proname[i] = n[i];
      SP[i] = s[i];
      CP[i] = c[i];
      quantity[i] = q[i];
    }

    proname[1] = "bread";
    CP[1] = 25;
    SP[1] = 40;
    quantity[1] = 100;

    proname[2] = "soap";
    CP[2] = 15;
    SP[2] = 25;
    quantity[2] = 100;

    proname[3] = "parle";
    CP[3] = 10;
    SP[3] = 15;
    quantity[3] = 100;

    proname[4] = "butter";
    CP[4] = 45;
    SP[4] = 60;
    quantity[4] = 100;

    proname[5] = "candy";
    CP[5] = 15;
    SP[5] = 20;
    quantity[5] = 10;

    proname[6] = "shampoo";
    CP[6] = 150;
    SP[6] = 200;
    quantity[6] = 100;

    proname[7] = "powder";
    CP[7] = 250;
    SP[7] = 300;
    quantity[7] = 100;

    proname[8] = "perfume";
    CP[8] = 350;
    SP[8] = 400;
    quantity[8] = 100;

    proname[9] = "bottles";
    CP[9] = 150;
    SP[9] = 200;
    quantity[9] = 100;

    proname[10] = "oil";
    CP[10] = 200;
    SP[10] = 250;
    quantity[10] = 100;

    i = 11;
  }

  //------------------------------
  void Add_Item() {
  Validity V;
    cout << "Adding Item " << endl;
    string addI;

    do {
    Again:
      cout << "Name of the item: ";
      cin >> proname[i];
      string k = proname[i];
      for (int m = 1; m < i; ++m)
        {
        if (k == proname[m])
         {
          cout << "Already existing item! Enter new one!" << endl;
          goto Again;
        }
      }
      cout << "Cost price: ";
      cin >> CP[i];
      cout << "Selling price: ";
      cin >> SP[i];
      cout << "Quantity: ";
      cin >> quantity[i];
      i++;

      again:
    cout<<"Add new item?(yes/no) ";
    cin>>addI;

    addI = V.toLower(addI);

    if(addI!="yes")
        {
            if(addI!="no")
            {
                cout<<"Invalid "<<endl; goto again;
    }
    }

    }while(addI=="yes");
}
  //-----------------------------------
  void Show_Item()
{
    cout << "Item\tCP\tSP\tQuantity" << endl;
    for (int j = 1; j < 50; j++)
        {
      if (!proname[j].empty())
        cout << proname[j] << "\t" << CP[j] << "\t" << SP[j] << "\t"
             << quantity[j] << endl;
    }
  }
  //--------------------------
  void red_item_quan()
  {
      Validity V;
      string red_item_quanchoice;
      string dltitem;
      int howmuch;
      int index=0;

      enter_dltagain:
      cout << "Enter Item to decrease quantity :";
      cin >> dltitem;

      dltitem = V.toLower(dltitem);

    for(int y = 1; y <= i; y++) {
        proname[y] = V.toLower(proname[y]);
    }

    bool GotName = false;
    for(int y = 1; y <= i; y++) {
        if(dltitem == proname[y]) {
            index = y;
            GotName = true;
            break;
        }
    }

    if(!GotName) {
        cout << "Invalid name!" << endl;
        goto enter_dltagain;
    }

      cout << "Enter Quantity of Items to delete :";
      cin >> howmuch;

       for (int j = 1; j < 50; j++)
        {
        if (!proname[j].empty())
            {
          if (dltitem == proname[j])
          {
            index = j;
            if(quantity[index] >= howmuch)
            {
            quantity[index] -= howmuch;
            cout<<endl;
            cout << "Successfully deleted " << howmuch << " items from " << proname[index] << endl;
            cout<<endl;
            break;
          }
          else
          {
              cout<<"There are no sufficient items to delete"<<endl;
              quantity[index] = 0;
              break;
          }
          }
        }
      }
      if(index==0)
      {
      cout<<"Item Not Matched "<<endl;
      cout<<"Enter again"<<endl;
      cout<<endl;
      goto  enter_dltagain;
      }

       again:
      cout<<"Reduce Quantity for other Item(yes/no): ";
      cin>>red_item_quanchoice;
    red_item_quanchoice = V.toLower(red_item_quanchoice);

    if(red_item_quanchoice!="yes")
        {
            if(red_item_quanchoice!="no")
        {
            cout<<"Invalid "<<endl;
            goto again;
            }
            }
  }
  //--------------------------
  void add_quan_initem() {
Validity V;
    string add_quan_initemchoice;
    string reqname;
    int index;
    int howmany;

    do {

    enter_start:
      cout << "Enter Item to increase quantity: ";
      cin >> reqname;

    reqname = V.toLower(reqname);

    for(int y = 1; y <= i; y++) {
        proname[y] = V.toLower(proname[y]);
    }

    bool GotName = false;
    for(int y = 1; y <= i; y++) {
        if(reqname == proname[y]) {
            index = y;
            GotName = true;
            break;
        }
    }

    if(!GotName) {
        cout << "Invalid name!" << endl;
        goto enter_start;
    }

      cout << "Enter Quantity of Items to add: ";
      cin >> howmany;

      for (int j = 1; j < 50; j++) {
        if (!proname[j].empty()) {
          if (reqname == proname[j]) {
            index = j;
            quantity[index] += howmany;
            cout << "Successfully added " << howmany << " items to " << proname[index] << endl;
            break;
          }
        }
      }
    again:
      cout<<"Increase Quantity for other Item(yes/no): ";
      cin>>add_quan_initemchoice;
     add_quan_initemchoice = V.toLower(add_quan_initemchoice);

    if(add_quan_initemchoice!="yes"){if(add_quan_initemchoice!="no")
        {cout<<"Invalid "<<endl; goto again;}}


    } while (add_quan_initemchoice == "yes");
  }
  //------------------------
  void billing()
  {
Validity V;

    string billpro;
    int q;
    string billch;

    do {
             int b=0;
bill:
      cout << "Enter Item to bill :";
      cin >> billpro;

      billpro = V.toLower(billpro);

    for(int y = 1; y <= i; y++) {
        proname[y] = V.toLower(proname[y]);
    }

    bool GotName = false;
    for(int y = 1; y <= i; y++) {
        if(billpro == proname[y]) {
            b = y;
            GotName = true;
            break;
        }
    }

    if(!GotName) {
        cout << "Invalid item!" << endl;
        goto bill;
    }

      cout << "Enter Quantity  to add of that item :";
      cin >> q;

  if(quantity[b]>q)
    {
      Billcpsum += (CP[b] * q);
      Billamt += (SP[b] * q);
      quantity[b] -= q;
again:
      cout<<"Add item to bill(yes/no) ";
      cin>>billch;

     billch = V.toLower(billch);

    if(billch!="yes")
    {
      if(billch!="no")
      {
        cout<<"Invalid "<<endl; goto again;
      }
    }

  }
  else
  {
    cout<<"Understock!"<<endl;
    goto bill;
  }

  }while(billch!="no");

  cout<<"Total Bill :"<<Billamt<<endl;
}
  //------------
  float Billamt_return()
{
  return Billamt;
}
  //---------------
  float BILLCPSUM()
{
  return Billcpsum;
}

};
//-------------------------------------

class Manager : public staff {

  string staffN[20]; // name
  int staffId[20];   // id
  char staffG[20];   // gender
  char staffS[20];   // shift M or E
  float In_staff[20];
  int leaves[20];

  int p;

  float Inc_from_bill = 0;
  float Profit = 0;
  float Netexpenditureamt = 500000;
  float Totalsalaries;

public:
  Manager()
  { // constructor
    string sN[20];
    int sId[20];
    char sG[20];
    char sS[20];
    float iS[20] = {0};
    int sL[20] = {0};
    for (int i = 1; i < 20; ++i)
      {
      staffN[i] = sN[i];
      staffId[i] = sId[i];
      staffG[i] = sG[i];
      staffS[i] = sS[i];
      In_staff[i] = iS[i];
      leaves[i] = sL[i];
    }

    staffN[1] = "alice";
    staffId[1] = 1;
    staffG[1] = 'F';
    staffS[1] = 'E';
    In_staff[1] = 3000;
    leaves[1] = 5;

    staffN[2] = "nick";
    staffId[2] = 2;
    staffG[2] = 'M';
    staffS[2] = 'M';
    In_staff[2] = 3000;
    leaves[2] = 5;

    staffN[3] = "joe";
    staffId[3] = 3;
    staffG[3] = 'M';
    staffS[3] = 'M';
    In_staff[3] = 3000;
    leaves[3] = 5;

    staffN[4] = "noah";
    staffId[4] = 4;
    staffG[4] = 'F';
    staffS[4] = 'M';
    In_staff[4] = 3000;
    leaves[4] = 5;

    staffN[5] = "tom";
    staffId[5] = 5;
    staffG[5] = 'M';
    staffS[5] = 'M';
    In_staff[5] = 3000;
    leaves[5] = 5;

    staffN[6] = "jerry";
    staffId[6] = 6;
    staffG[6] = 'M';
    staffS[6] = 'E';
    In_staff[6] = 3000;
    leaves[6] = 5;

    staffN[7] = "sam";
    staffId[7] = 7;
    staffG[7] = 'M';
    staffS[7] = 'E';
    In_staff[7] = 3000;
    leaves[7] = 5;

    staffN[8] = "sofia";
    staffId[8] = 8;
    staffG[8] = 'F';
    staffS[8] = 'M';
    In_staff[8] = 3000;
    leaves[8] = 5;

    staffN[9] = "jenny";
    staffId[9] = 9;
    staffG[9] = 'F';
    staffS[9] = 'E';
    In_staff[9] = 3000;
    leaves[9] = 5;

    staffN[10] = "harry";
    staffId[10] = 10;
    staffG[10] = 'M';
    staffS[10] = 'E';
    In_staff[10] = 3000;
    leaves[10] = 5;

    for (int n = 1; n <= 10; n++)
    {
      In_staff[n] -= ((In_staff[n] / 30) * leaves[n]);
    }

    p = 11;
  }
  //-------------------

  void Takeleaveemp() {
    Validity V;
    string stafname;
    int u;

TakeL:
    cout << "Enter name of staff: ";
    cin >> stafname;

    stafname = V.toLower(stafname);

    for(int y = 1; y <= p; y++) {
        staffN[y] = V.toLower(staffN[y]);
    }

    bool GotName = false;
    for(int y = 1; y <= p; y++) {
        if(stafname == staffN[y]) {
            u = y;
            GotName = true;
            break;
        }
    }

    if(!GotName) {
        cout << "Invalid name!" << endl;
        goto TakeL;
    }

    int stafid;
Again:

    int l;
    string leavechoice;

    do{

    cout << "Enter your ID: ";
    cin >> stafid;
 //int l;
    if(stafid > 0) {
        if(stafid == staffId[u])
            {
           // int l;
            if(u <= 10)
                {
                cout << "Enter number of leaves: ";
                cin >> leaves[u];
                l = leaves[u];
                leaves[u] += 5;
                cout << "Successfully allotted "<<endl;
            }
             else if(u > 10)
                {
                cout << "Enter number of leaves: ";
                cin >> leaves[u];
                l = leaves[u];
                cout << "Successfully allotted "<<endl;
            }

            In_staff[u] = In_staff[u] - (l * 100);
        }
         else
        {
            cout << "Enter correct ID!" << endl;
            goto Again;
        }
    }
    else
        {
        cout << "Enter correct ID!" << endl;
        goto Again;
    }
    cout<<"Do you want to take leave again (yes/no):";
    cin>>leavechoice;

    }while(leavechoice!= "no");
}

//--------------------

  void Add_Staff()
{
    string add_Staff;
    do {
      cout << "Enter name of staff: ";
      cin >> staffN[p];

    Again:
      cout << "Enter ID to allot: ";
      cin >> staffId[p];
      int k1 = staffId[p];
      for (int m = 1; m < p; ++m) {
        if (k1 == staffId[m] || k1 > 20 || k1 < 0) {
          cout << "Already existing ID/Not Valid ID!" << endl;
          goto Again;
        }
      }

    Again1:
      cout << "Enter gender(M/F): ";
      cin >> staffG[p];
      char k2 = staffG[p];
      if (k2 != 'M' && k2 != 'F' && k2!='m' && k2!='f') {
        cout << "Enter correct gender!" << endl;
        goto Again1;
      }

    Again2:
      cout << "Enter shift(M/E): ";
      cin >> staffS[p];
      char k3 = staffS[p];
      if (k3 != 'M' && k3 != 'E' && k3!='m' && k3!='e') {
        cout << "Enter correct shift!" << endl;
        goto Again2;
      }
      cout << "Enter salary: ";
      cin >> In_staff[p];

      p++;

      cout << "Add new staff?(yes/no): ";
      cin >> add_Staff;

    } while (add_Staff == "yes");
  }
  //-------------------
  void Show_Employee()
{
    cout << "ID\tName\tGender\tShift\tLeaves\tSalary(After deduction)" << endl;
    for (int j = 1; j < 20; j++)
        {
      if (!staffN[j].empty())
        cout << staffId[j] << "\t" << staffN[j] << "\t" << staffG[j] << "\t"
             << staffS[j] << "\t" << leaves[j] << "\t" << In_staff[j] << endl;
    }
  }

  //------------------
  void Netexpenditure()
{
int sum=0;
    Inc_from_bill = Billamt_return();
    Profit = Inc_from_bill - BILLCPSUM();
    cout << "Profit from sales :" << Profit << endl;

    for (int e = 1; e < p; e++)
      {
      sum += In_staff[e];
      }
    Totalsalaries=sum;
    Netexpenditureamt += (Profit - Totalsalaries);
    cout << "Net Income  :" << Netexpenditureamt << endl;
    Netexpenditureamt=500000;
  }
};


int main() {

  staff s;
  Manager m;
  cout <<"Welcome to Grocery Store" << endl;
 cout<<endl;
  int person_select;

  do {
    Login_page:
    cout << "Login as" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Staff" << endl;
    cout << "3. Exit" << endl;
    cout<<endl;

    cout << "Enter choice: ";
    cin >> person_select;


    if (cin.fail())
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            goto Login_page;
        }



    switch (person_select) {
      case 1:
        { // Admin login
        string UN;
        int pass;
        cout << "Enter Admin username: ";
        cin >> UN;
        cout << "Enter password: ";
        cin >> pass;

        if (UN == "grocery" && pass == 1234)
        {
          cout<<endl;
          cout << "You Entered correct Credentials " << endl;
          cout << "Successfully Logged in as Admin " << endl;
          cout<<endl;

          Manager_menu:
          cout << "1. Manage Employees" << endl;
          cout << "2. Net Expenditure" << endl;
          cout << "3. Back To Main Login page" << endl;
          cout<<endl;

          int manager_choice;
          cout << "Enter choice: ";
          cin >> manager_choice;


          switch (manager_choice){
            case 1:
              { // Manage Employees
               cout<<endl;
              cout << "1. Add Staff" << endl;
              cout << "2. Show Employee" << endl;
              cout << "3. Back To Manager Menu" << endl;
              cout<<endl;

              int manwork_choice;
              cout << "Enter choice: ";
              cin >> manwork_choice;


              switch(manwork_choice){
                case 1:
                  {
                  m.Add_Staff();
                  cout<<endl;
                  break;
                  }

                case 2:
                  {
                  m.Show_Employee();
                  cout<<endl;
                  break;
                  }
                case 3:
                  {
                  cout << "Returning to Manager Menu" << endl;
                  cout<<endl;
                  goto Manager_menu;
                 // break;
                  }
                default:
                  cout << "Invalid choice" << endl;
                  cout<<endl;
              }
              goto Manager_menu;
             // break;
            }
            case 2:
              { // Net Expenditure
              m.Netexpenditure();
              cout<<endl;
              goto Manager_menu;
            //  break;
            }
            case 3:
              { // Back To Main Login page
              cout << "Returning to Main Login page" << endl;
                cout<<endl;
              goto Login_page;
            //  break;
            }
            default:
              cout << "Invalid choice" << endl;
          }
        }
        else
        {
          cout << "Invalid credentials" << endl;
          cout << "Try Again" << endl;
          cout<<endl;
          goto Login_page;
        }
      }
      case 2:
        { // Staff login
        Staff_menu:
        cout << "1. Scan Goods " << endl;
        cout << "2. Billing" << endl;
        cout << "3. Take leave" << endl;
        cout << "4. Back To Main Login page" << endl;
          cout<<endl;

        int staffwork_choice;
        cout << "Enter choice: ";
        cin >> staffwork_choice;

        switch(staffwork_choice){
          case 1:
            { // Scan Goods
                scan_options:
            cout << "1. Add New Item " << endl;
            cout << "2. Increase Quantity of Existing Item" << endl;
            cout << "3. Decrease Quantity of Existing Item" << endl;
            cout << "4. Show the stock"<<endl;
            cout << "5. Back To Staff Menu" << endl;
              cout<<endl;

            int scangoods_choice;
            cout << "Enter choice: ";
            cin >> scangoods_choice;


            switch(scangoods_choice) {
              case 1:
                {
                m.Add_Item();
                cout<<endl;
                break;
                }
              case 2:
                {
                m.add_quan_initem();
                cout<<endl;
                break;
                }
                case 3:
                {
                m.red_item_quan();
                cout<<endl;
                break;
                }
                 case 4:
                {
                m.Show_Item();
                cout<<endl;
                break;
                }
              case 5:
                {
                cout << "Returning To Staff Menu" << endl;
                goto Staff_menu;
           //     break;
                }
              default:
                cout << "Invalid choice" << endl;

            }
            goto scan_options;
            //break;
          }
          case 2:
            { // Billing
            m.billing();
             cout<<endl;
            break;
          }
          case 3:
            { // Take leave
            m.Takeleaveemp();
             cout<<endl;
            break;
          }
          case 4:
            { // Back To Main Login page
            cout << "Back To Main Logic Page" << endl;
              cout<<endl;
            goto Login_page;
          //  break;
          }
          default:
            cout << "Invalid choice" << endl;
          cout<<endl;
        }
          goto Staff_menu;
      //  break;
      }
      case 3:
        { // Exit
        cout << "Exiting Program" << endl;
        break;
      }
      default:
        cout << "Invalid choice" << endl;
    }

  } while (person_select != 3);

return 0;
}