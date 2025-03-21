#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
#include <unordered_set>
#include<fstream>

using namespace std;

void create();
void login();
void exit();

string name,address;
long long int phn;
vector<vector<string>> product_list = {{"Cold Drinks","Coke","Thums up","Mountain dew","Appy fizz","Pepsi"},{"Dairy","Mother dairy Curd","Aplus Yogurt","Mother Dairy milk","Amul butter","Amul cheese"},{"Chocolates","Amul Milk Chocolate","Bournville Dark Chocolate","Dairy Milk Silk","Kit-kat","5-star"},{"Munchies","kurkure","lays chips","picnic","fun-flips","nachos"},{"Bathing","shampoo","conditioner","soap","body wash","handwash"},{"Breakfast items","Bread","Flattened_rice","Oats","Upma","Pav"},{"Bathroom cleaner","Toilet_cleaner","Bathroom_freshner","Floor_wiper","Bath_mat","Toilet_paper"},{"crockeries","spoon","plates","mugs","glasses","glasses"},{"Men's Hygiene","shaving cream","men's facewash","razor","aftershave","trimmer"},{"essentials","Oil","Salt","Sugar","Tea","coffee","Spices_combined"},{"Kitchen","sponge","mope","vim-cleaner","scrubber","utensil-soap"},{"Sauces","ketchup","mayonies","spreads","ginger-garlic paste","vinegar"},{"Biscuits","marie-gold","50-50","bourbon","parle-g","hide&seek"},{"Men's care","hair gel","perfume","comb","sunscreen","face-cream"},{"Dessert","Ice-cream","GulabJamun","Rasgulla","Custard","Hotchocolate"}};


class DC
{
    public:
        string name,date;
        int cvv;
        long long int num;
        DC(){
            system("cls");
            cout<<"\n\n\n\t\t\tEnter name written on card : ";
            cin>>name;
            cout<<"\n\t\t\tEnter expiry date of the card : ";
            cin>>date;
            cout<<"\n\t\t\tEnter card number : ";
            cin>>num;
            cout<<"\n\t\t\tEnter cvv : ";
            cin>>cvv;

        }
};
class Item
{
public:
    string unique_id;
    string iname;
    int quantity;
    string category;
    double price;
    double discounted_price=0.0;
    double discPercent=0.0;
    bool thresholdCross = false;

};
class cartss : public Item
{
public:
    void ATC(vector<vector<Item>>);
    void select();
    void menu();
    void products();
    void abc();
    void cart_function(vector<Item>& cart_vector); // Update the function declaration
    void cod();
    void debit();
    void pay();
    void bill();
    void Remove();
    void displayCart(const vector<Item>& discountcart); // Function declaration

};

vector <Item> vec1;

int main()
{
    string c;
    cout<<"\n(Sign in Page)"<<endl;
    cout<<"\n\n\t\t________________________________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\tWELCOME TO E-MARKET\n";
    cout<<"\t\t\t\t\t\t\t-Market For Quality Shopping"<<endl;
    cout<<"\t\t________________________________________________________________________"<<endl;
    cout<<"\n\n\t\t\t\t\t\tMENU"<<endl;
    cout<<"\n\t\tPRESS 1 TO CREATE ACCOUNT"<<endl;
    cout<<"\t\tPRESS 2 TO LOGIN"<<endl;
    cout<<" \t\tPRESS 3 TO EXIT"<<endl;
    cout<<"\n\t\tPlease enter your choice: ";
    cin>>c;
    cout<<endl;
    if(c=="1"){
        create();
    }
    else if (c=="2"){
        login();
    }
    else if (c=="3"){
        exit();
    }
    else{
        system("cls");
        main();
    }
}
void create()
{
    string id,pass;
    system("cls");
    cout<<"\n\t(NOTE:Kindly Avoid adding space between characters.)";
    cout<<"\n\n\tPlease Enter your email-id: ";
    cin>>id;
    cout<<"\n\tPlease Enter password: ";
    cin>>pass;

    ofstream f1("records.txt",ios::app);
    f1<<id<<' '<<pass<<endl;

    system("cls");
    cout<<"Account created succesfully!\n";
    main();
}
void login()
{
 int count;
 string id,pass,loginid,loginpass;
 system("cls");
 cout<<"\n\t(NOTE:Kindly Avoid adding space between characters.)";
 cout<<"\n\n\n\n\tPlease Enter your Name: ";
 cin>>name;
 cout<<"\n\tEnter your email-id: ";
 cin>>id;
 cout<<"\n\tEnter Password: ";
 cin>>pass;


 ifstream input("records.txt");

 while(input>>loginid>>loginpass)
 {
     if(loginid==id &&  loginpass==pass)
     {
         count=1;
         system("cls");
     }
 }
 input.close();
 if(count==1)
 {
     cout<<"\n\tLogin Successfull! :)"<<endl;;
     cout<<"\n\n\tWelcome "<<name<<" ";

 }
 else
    {
        cout<<"\n\tLogin Error!"<<endl;
        cout<<"\n\t (Kindly recheck your userid and password)\n";
        main();

    }
    cout << endl;
    cout << "\n\tEnter you Mobile Number : ";
    cin >> phn;
    cout << "\n\tEnter you Address : ";
    cin >> address;

    cartss C;
    C.menu();
}
void exit()
{
    system("cls");
    cout<<"\n\n\n\tThankyou! for visiting us :)!\n\n\n\n\n\n";
}
void cartss :: menu(){
    system("cls");
    string n;
    cout<<"\n\n\n\t\t\t--------------------------------------------------";
    cout<<"\n\t\t\t\t\tE-MARKET MAIN MENU"<<endl;
    cout<<"\t\t\t--------------------------------------------------"<<endl;
    cout<<"\n\n\t\t\t\t  |    (1) View Products          |"<<endl;
    cout<<"\t\t\t\t  |    (2) Select Products        |"<<endl;
    cout<<"\t\t\t\t  |    (3) View Cart              |"<<endl;
    cout<<"\t\t\t\t  |    (4) E-Bill                 |"<<endl;
    cout<<"\t\t\t\t  |    (5) Select Payment method  |"<<endl;
    cout<<"\t\t\t\t  |    (6) Exit                   |"<<endl;
    cout<<"\n\n\t\t\t Enter Your Choice : ";
    cin>>n;
    if (n=="1"){
        products();
    }
    else if (n=="2"){
        select();
    }
    else if (n=="3"){
        cart_function(vec1);
    }
    else if (n=="4"){
        bill();
    }
    else if (n=="5"){
        pay();
    }
    else if (n=="6"){
        system("cls");
        cout<<"Thank you! for visiting us :)!\n\n\n\n\n";
    }
    else{
        system("cls");
        menu();
    }
}

void cartss :: products(){
    //Get this data extracted using file handling concept rather than coding it.
  int option;
  system("cls");
  cout<<"\n\t\t\t\t\t\tPRODUCT LIST";
  cout<<"\n\t\t\t\t\t____________________________";


    for(int i=0;i<product_list.size();i++){
        cout << "\n\n\n\t\t" << "[" << product_list[i][0] << "]";
        for(int j=1;j<product_list[i].size();j++){
            cout << "\n\t\t" << j << "."<<product_list[i][j];
        }
    }
    cout <<endl<<endl;


  cout<<"\n\t\t____________________________________________";
  cout<<"\n\n\t\tPress 1 to go to Main Menu : ";
  cin>>option;
  switch(option){
    case 1:
        system("cls");
        menu();
        break;
    default:
        products();
  }
}
void cartss :: select(){

    Item CD1;
    CD1.unique_id = "CD1";
    CD1.iname = "Coke";
    CD1.category = "Cold_Drinks";
    CD1.price = 40;
    CD1.quantity = 0;

    Item CD2;
    CD2.unique_id = "CD2";
    CD2.iname = "Thums_Up";
    CD2.category = "Cold_Drinks";
    CD2.price = 40;
    CD2.quantity = 0;

    Item CD3;
    CD3.unique_id = "CD3";
    CD3.iname = "Mountain_Dew";
    CD3.category = "Cold_Drinks";
    CD3.price = 60;
    CD3.quantity = 0;

    Item CD4;
    CD4.unique_id = "CD4";
    CD4.iname = "Appy_Fizz";
    CD4.category = "Cold_Drinks";
    CD4.price = 60;
    CD4.quantity = 0;

    Item CD5;
    CD5.unique_id = "CD5";
    CD5.iname = "Pepsi";
    CD5.category = "Cold_Drinks";
    CD5.price = 40;
    CD5.quantity = 0;

    //2.DAIRY_PRODUCTS
    Item DP1;
    DP1.unique_id = "DP1";
    DP1.iname = "Amul_Curd[1kg]";
    DP1.category = "Dairy_Products";
    DP1.price = 72;
    DP1.quantity = 0;

    Item DP2;
    DP2.unique_id = "DP2";
    DP2.iname = "Amul_Paneer[200gm]";
    DP2.category = "Dairy_Products";
    DP2.price = 86;
    DP2.quantity = 0;

    Item DP3;
    DP3.unique_id = "DP3";
    DP3.iname = "Amul_FullCream_Milk[1Litre]";
    DP3.category = "Dairy_Products";
    DP3.price = 33;
    DP3.quantity = 0;

    Item DP4;
    DP4.unique_id = "DP4";
    DP4.iname = "Amul_Butter[100gm]";
    DP4.category = "Dairy_Products";
    DP4.price = 45;
    DP4.quantity = 0;

    Item DP5;
    DP5.unique_id = "DP5";
    DP5.iname = "Patanjali_Ghee[1Litre]";
    DP5.category = "Dairy_Products";
    DP5.price = 560;
    DP5.quantity = 0;

    Item CH1;
    CH1.unique_id = "CH1";
    CH1.iname = "Amul_milk_chocolate";
    CH1.category = "Chocolates";
    CH1.price = 40;
    CH1.quantity = 0;

    Item CH2;
    CH2.unique_id = "CH2";
    CH2.iname = "Dairy_milk_silk";
    CH2.category = "Chocolates";
    CH2.price = 120;
    CH2.quantity = 0;

    Item CH3;
    CH3.unique_id = "CH3";
    CH3.iname = "Kit-kat";
    CH3.category = "Chocolates";
    CH3.price = 60;
    CH3.quantity = 0;

    Item CH4;
    CH4.unique_id = "CH4";
    CH4.iname = "Bournville_dark_chocolate";
    CH4.category = "Chocolates";
    CH4.price = 80;
    CH4.quantity = 0;

    Item CH5;
    CH5.unique_id = "CH5";
    CH5.iname = "5-star";
    CH5.category = "Chocolates";
    CH5.price = 25;
    CH5.quantity = 0;

    Item MC1;
    MC1.unique_id = "MC1";
    MC1.iname = "Kurkure";
    MC1.category = "Munchies";
    MC1.price = 20;
    MC1.quantity = 0;

    Item MC2;
    MC2.unique_id = "MC2";
    MC2.iname = "Lays";
    MC2.category = "Munchies";
    MC2.price = 20;
    MC2.quantity = 0;

    Item MC3;
    MC3.unique_id = "MC3";
    MC3.iname = "Mad-angles";
    MC3.category = "Munchies";
    MC3.price = 20;
    MC3.quantity = 0;

    Item MC4;
    MC4.unique_id = "MC4";
    MC4.iname = "Fun-flips";
    MC4.category = "Munchies";
    MC4.price = 30;
    MC4.quantity = 0;

    Item MC5;
    MC5.unique_id = "MC5";
    MC5.iname = "Nachos";
    MC5.category = "Munchies";
    MC5.price = 40;
    MC5.quantity = 0;

    Item BG1;
    BG1.unique_id = "BG1";
    BG1.iname = "Shampoo";
    BG1.category = "Bathing";
    BG1.price = 125;
    BG1.quantity = 0;

    Item BG2;
    BG2.unique_id = "BG2";
    BG2.iname = "Conditioner";
    BG2.category = "Bathing";
    BG2.price = 175;
    BG2.quantity = 0;

    Item BG3;
    BG3.unique_id = "BG3";
    BG3.iname = "Bathing_soap";
    BG3.category = "Bathing";
    BG3.price = 45;
    BG3.quantity = 0;

    Item BG4;
    BG4.unique_id = "BG4";
    BG4.iname = "Bodywash";
    BG4.category = "Bathing";
    BG4.price = 220;
    BG4.quantity = 0;

    Item BG5;
    BG5.unique_id = "BG5";
    BG5.iname = "Handwash";
    BG5.category = "Bathing";
    BG5.price = 130;
    BG5.quantity = 0;

    Item BI1;
    BI1.unique_id = "BI1";
    BI1.iname = "Brown_Bread";
    BI1.category = "Breakfast";
    BI1.price = 45;
    BI1.quantity = 0;

    Item BI2;
    BI2.unique_id = "BI2";
    BI2.iname = "Flattened_rice[100gm]";
    BI2.category = "Breakfast";
    BI2.price = 50;
    BI2.quantity = 0;

    Item BI3;
    BI3.unique_id = "BI3";
    BI3.iname = "Oats[100gm]";
    BI3.category = "Breakfast";
    BI3.price = 60;
    BI3.quantity = 0;

    Item BI4;
    BI4.unique_id = "BI4";
    BI4.iname = "Upma[100gm]";
    BI4.category = "Breakfast";
    BI4.price = 50;
    BI4.quantity = 0;

    Item BI5;
    BI5.unique_id = "BI5";
    BI5.iname = "Pav[12 peices]";
    BI5.category = "Breakfast";
    BI5.price = 60;
    BI5.quantity = 0;

    Item BC1;
    BC1.unique_id = "BC1";
    BC1.iname = "Toilet_cleaner";
    BC1.category = "Bathroom_cleaner";
    BC1.price = 140;
    BC1.quantity = 0;

    Item BC2;
    BC2.unique_id = "BC2";
    BC2.iname = "Bathroom_freshener";
    BC2.category = "Bathroom_cleaner";
    BC2.price = 60;
    BC2.quantity = 0;

    Item BC3;
    BC3.unique_id = "BC3";
    BC3.iname = "Floor_wiper";
    BC3.category = "Bathroom_cleaner";
    BC3.price = 300;
    BC3.quantity = 0;

    Item BC4;
    BC4.unique_id = "BC4";
    BC4.iname = "Bath_mat";
    BC4.category = "Bathroom_cleaner";
    BC4.price = 500;
    BC4.quantity = 0;

    Item BC5;
    BC5.unique_id = "BC5";
    BC5.iname = "Toilet_paper";
    BC5.category = "Bathroom cleaner";
    BC5.price = 50;
    BC5.quantity = 0;

    Item CK1;
    CK1.unique_id = "CK1";
    CK1.iname = "Spoon[6pcs]";
    CK1.category = "Crockeries";
    CK1.price = 180;
    CK1.quantity = 0;

    Item CK2;
    CK2.unique_id = "CK1";
    CK2.iname = "Plates[4pcs]";
    CK2.category = "Crockeries";
    CK2.price = 400;
    CK2.quantity = 0;

    Item CK3;
    CK3.unique_id = "CK3";
    CK3.iname = "Mug";
    CK3.category = "Crockeries";
    CK3.price = 60;
    CK3.quantity = 0;

    Item CK4;
    CK4.unique_id = "CK1";
    CK4.iname = "Glasses[5pcs]";
    CK4.category = "Crockeries";
    CK4.price = 350;
    CK4.quantity = 0;

    Item CK5;
    CK5.unique_id = "CK5";
    CK5.iname = "Bowl";
    CK5.category = "Crockeries";
    CK5.price = 150;
    CK5.quantity = 0;

    Item MH1;
    MH1.unique_id = "MH1";
    MH1.iname = "Shaving_Cream";
    MH1.category = "Men's_Hygiene";
    MH1.price = 70;
    MH1.quantity = 0;

    Item MH2;
    MH2.unique_id = "MH2";
    MH2.iname = "Men's_Facewash";
    MH2.category = "Men's_Hygiene";
    MH2.price = 150;
    MH2.quantity = 0;

    Item MH3;
    MH3.unique_id = "MH3";
    MH3.iname = "Razor";
    MH3.category = "Men's_Hygiene";
    MH3.price = 50;
    MH3.quantity = 0;

    Item MH4;
    MH4.unique_id = "MH4";
    MH4.iname = "After_shave";
    MH4.category = "Men's_Hygiene";
    MH4.price = 100;
    MH4.quantity = 0;

    Item MH5;
    MH5.unique_id = "MH5";
    MH5.iname = "Trimmer";
    MH5.category = "Men's_Hygiene";
    MH5.price = 750;
    MH5.quantity = 0;

    vector<vector<Item>> products = {{CD1,CD2,CD3,CD4,CD5},{DP1,DP2,DP3,DP4,DP5},{CH1,CH2,CH3,CH4,CH5},{MC1,MC2,MC3,MC4,MC5},{BG1,BG2,BG3,BG4,BG5},{BI1,BI2,BI3,BI4,BI5},{BC1,BC2,BC3,BC4,BC5},{CK1,CK2,CK3,CK4,CK5},{MH1,MH2,MH3,MH4,MH5}};

    system("cls");


  cout<<"\n\t\t\t\t\t\tPRODUCT LIST";
  cout<<"\n\t\t\t\t\t____________________________";


  for(int i =0;i<products.size();i++){
    cout<<"\n\n\n\t\t" << "[" << products[i][0].category << "]";
    for(int j=0;j<products[i].size();j++){
        cout << "\n\t\t" << j+1+5*i << "." << products[i][j].iname << "(" << products[i][j].unique_id << ")" <<"  Rs." <<  products[i][j].price;
    }
  }

    ATC(products);


}
bool compareByPriceAscending(const Item& a, const Item& b) {
    return a.price < b.price;
}

bool compareByPriceDescending(const Item& a, const Item& b) {
    return a.price > b.price;
}

void merge(vector<Item> &items, int left, int mid, int right, bool(*compare)(const Item&, const Item&)){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Item> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = items[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = items[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
            items[k++] = L[i++];
        } else {
            items[k++] = R[j++];
        }
    }

    while (i < n1) {
        items[k++] = L[i++];
    }
    while (j < n2) {
        items[k++] = R[j++];
    }

}

void mergeSort(vector<Item> &items, int left, int right, bool(*compare)(const Item&, const Item&)){
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(items, left, mid, compare);
        mergeSort(items, mid + 1, right, compare);
        merge(items, left, mid, right, compare);
    }
}

void cartss :: ATC(vector<vector<Item>> products){

    string p;
    string n;
    string cat;

    cout<<"\n\n\n\t\t______________________________________________________";
     cout<<"\n\n\t\t(Enter '0' to go to MAIN MENU)";
     cout << "\n\n\t\t 1. To arrange the products in order of increasing price";
     cout << "\n\n\t\t 2. To arrange the products in order of decreasing price";
     cout << "\n\n\t\t 3. To get a particular category";
     cout << "\n\n\t\t 4. To add an item to cart";
     cout << "\n\n\t\t Enter you choice : ";
    cin >> n;
        if(n == "1"){
            for (auto &vec : products) {
                mergeSort(vec, 0, vec.size() - 1, compareByPriceAscending);
            }
            cout<<"\n\t\t\t\t\t\tPRODUCT LIST";
            cout<<"\n\t\t\t\t\t____________________________";


            for(int i =0;i<products.size();i++){
                cout<<"\n\n\n\t\t" << "[" << products[i][0].category << "]";
                for(int j=0;j<products[i].size();j++){
                    cout << "\n\t\t" << j+1+5*i << "." << products[i][j].iname << "(" << products[i][j].unique_id << ")" <<"  Rs." <<  products[i][j].price;
                }
            }
            ATC(products);
        }
        else if( n == "2" ){
            for (auto &vec : products) {
                mergeSort(vec, 0, vec.size() - 1, compareByPriceDescending);
            }

            cout<<"\n\t\t\t\t\t\tPRODUCT LIST";
            cout<<"\n\t\t\t\t\t____________________________";


            for(int i =0;i<products.size();i++){
                cout<<"\n\n\n\t\t" << "[" << products[i][0].category << "]";
                for(int j=0;j<products[i].size();j++){
                    cout << "\n\t\t" << j+1+5*i << "." << products[i][j].iname << "(" << products[i][j].unique_id << ")" <<"  Rs." <<  products[i][j].price;
                }
            }
            ATC(products);

        }
        else if( n == "3" ) {
            cout << "\n\n\t Enter category : ";
            cin >> cat;
            for(int i =0;i<products.size();i++){
                if(products[i][0].category == cat){
                    cout<<"\n\n\n\t\t" << "[" << products[i][0].category << "]";
                    for(int j=0;j<products[i].size();j++){
                        cout << "\n\t\t" << j+1+5*i << "." << products[i][j].iname << "(" << products[i][j].unique_id << ")" <<"  Rs." <<  products[i][j].price;
                    }
                }
            }
            ATC(products);
        }
        else if( n == "4" ){
            int quan;
            cout<<"\n\n\t\tEnter product number you want to add to cart : ";
            cin >> p;
            cout << "\n\t\tEnter the quantity : ";
            cin >> quan;
            if (p=="1"){
                Item ob1 = products[0][0];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="2"){
                Item ob1 = products[0][1];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="3"){
                Item ob1 = products[0][2];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="4"){
                Item ob1 = products[0][3];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="5"){
                Item ob1 = products[0][4];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="6"){
                Item ob1 = products[1][0];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="7"){
                Item ob1 = products[1][1];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="8"){
                Item ob1 = products[1][2];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="9"){
                Item ob1 = products[1][3];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="10"){
                Item ob1 = products[1][4];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="11"){
                Item ob1 = products[2][0];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="12"){
                Item ob1 = products[2][1];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="13"){
                Item ob1 = products[2][2];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="14"){
                Item ob1 = products[2][3];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="15"){
                Item ob1 = products[2][4];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="16"){
                Item ob1 = products[3][0];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="17"){
                Item ob1 = products[3][1];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="18"){
                Item ob1 = products[3][2];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="19"){
                Item ob1 = products[3][3];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="20"){
                Item ob1 = products[3][4];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="21"){
                Item ob1 = products[4][0];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="22"){
                Item ob1 = products[4][1];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="23"){
                Item ob1 = products[4][2];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="24"){
                Item ob1 = products[4][3];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="25"){
                Item ob1 = products[4][4];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="26"){
                Item ob1 = products[5][0];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="27"){
                Item ob1 = products[5][1];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="28"){
                Item ob1 = products[5][2];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="29"){
                Item ob1 = products[5][3];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="30"){
                Item ob1 = products[5][4];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="31"){
                Item ob1 = products[6][0];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="32"){
                Item ob1 = products[6][1];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="33"){
                Item ob1 = products[6][2];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="34"){
                Item ob1 = products[6][3];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="35"){
                Item ob1 = products[6][4];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="36"){
                Item ob1 = products[7][0];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="37"){
                Item ob1 = products[7][1];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="38"){
                Item ob1 = products[7][2];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="39"){
                Item ob1 = products[7][3];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="40"){
                Item ob1 = products[7][4];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="41"){
                Item ob1 = products[8][0];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="42"){
                Item ob1 = products[8][1];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="43"){
                Item ob1 = products[8][2];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="44"){
                Item ob1 = products[8][3];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else if (p=="45"){
                Item ob1 = products[8][4];
                ob1.quantity = quan;
                vec1.push_back(ob1);
            }
            else{
                cout << "No such product";
                select();
            }
            abc();
        }
        else if( n == "0" ){
                menu();
        }
        else{
            select();
        }
}
void cartss :: abc(){
    string n;
    system("cls");

    cout<<"\n\n\n\n\t\t\t1.To Continue Shopping";
    cout<<"\n\n\t\t\t2.To view Cart";
    cout<<"\n\n\t\t\t3.To checkout";
    cout<<"\n\n\t\t\t4.Go to MAIN MENU";
    cout<<"\n\n\t\t\t________________________________________";
    cout<<"\n\n\n\n\t\t\tEnter Your Choice:";
    cin >> n;
    if (n=="1"){
        select();
    }
    else if (n=="2"){
        cart_function(vec1);
    }
    else if (n=="3"){
        bill();
    }
    else if (n=="4"){
        menu();
    }
    else {
        abc();
    }
}


bool compareByDiscount(const Item& item1, const Item& item2){
    return item1.discPercent > item2.discPercent;
}

void applyDiscount(Item& item, double discount){
    if (item.thresholdCross == true){
        item.discounted_price = item.price-(item.price * discount);
    }
    else{
        item.discounted_price=item.price;
    }

}

void applyDiscounts(vector<Item> &discountcart){
    for (Item& item : discountcart)
    {
        if (item.category == "Cold_Drinks" && item.quantity >= 3){
            item.discPercent = 0.15;
            item.thresholdCross = true;
        }
        else if(item.category == "Dairy_Products" && item.quantity>=2){
            item.discPercent = 0.02;
            item.thresholdCross = true;
        }
        else if(item.category == "Chocolates" && item.quantity>=5){
            item.discPercent = 0.1;
            item.thresholdCross = true;
        }
        else if(item.category == "Munchies" && item.quantity>=5){
            item.discPercent = 0.1;
            item.thresholdCross = true;
        }
        else if(item.category == "Bathing" && item.quantity>=4){
            item.discPercent = 0.08;
            item.thresholdCross = true;
        }
        else if(item.category == "Breakfast" && item.quantity>=3){
            item.discPercent = 0.2;
            item.thresholdCross = true;
        }
        else if(item.category == "Bathroom cleaner" && item.quantity>=2){
            item.discPercent = 0.05;
            item.thresholdCross = true;
        }
        else if(item.category == "Crockeries" && item.quantity>=6){
            item.discPercent = 0.1;
            item.thresholdCross = true;
        }
        else if(item.category == "Men's_Hygiene" && item.quantity>=2){
            item.discPercent = 0.2;
            item.thresholdCross = true;
        }
        else{
            item.discPercent = 0.0 ;
        }
    }

    sort(discountcart.begin(), discountcart.end(), compareByDiscount);

    double discount = discountcart[0].discPercent;

    for (Item& item : discountcart){
        applyDiscount(item,discount);
    }

}

void cartss::cart_function(vector<Item>& cart_vector)
{

    system("cls");
    cout<<"\n\t\t\t\t\t____________________________________";
    cout<<"\n\n\t\t\t\t\t\t\t[CART]";
    cout<<"\n\t\t\t\t\t____________________________________";
    cout<<"_"<< endl << endl;
    float T=0;
    float DisCountedPrice = 0.0;

    applyDiscounts(cart_vector);

    for (int i=0;i<vec1.size();i++){
        cout << "\n\t\t\t"<<i+1<<"->";
        cout << "\n\t\t\t Code : "<<vec1[i].unique_id;
        cout << "\n\t\t\t Product Name : "<<vec1[i].iname;
        cout << "\n\t\t\t Price : "<<vec1[i].price;
        cout << "\n\t\t\t Discounted Price : "<<vec1[i].discounted_price;
        cout << "\n\t\t\t Quantity : "<<vec1[i].quantity;
        T+=vec1[i].price*vec1[i].quantity;
        DisCountedPrice += vec1[i].discounted_price*vec1[i].quantity;

    }


    string n;
    cout<<"\n\n\t\t\t______________________________________________________";
    cout <<"\n\n\n\t\t\t*Total Amount : "<< T;
    cout <<"\n\n\n\t\t\t*Amount Payable : "<<DisCountedPrice << endl;
    cout <<"\n\n\n\t\t\t*Savings : "<<T-DisCountedPrice << endl;
    cout<<"\n\n\t\t\t1.To Continue Shopping";
    cout<<"\n\n\t\t\t2.To Remove Item";
    cout<<"\n\n\t\t\t3.To checkout";
    cout<<"\n\n\t\t\t4.Go to MAIN MENU";
    cout<<"\n\n\t\t\tPress :";
    cin >> n;

    if (n=="1"){
        select();
    }
    else if (n=="3"){
        bill();
    }
    else if (n=="2"){
        Remove();
    }
    else if (n=="4"){
        menu();
    }
    else{
        cart_function(vec1);
    }
}

void cartss :: bill(){

    float T=0;
    float DisCountedPrice = 0.0;

    applyDiscounts(vec1);

    for (int i=0;i<vec1.size();i++){
        cout << "\n\t\t\t"<<i+1<<"->";
        cout << "\n\t\t\t Code : "<<vec1[i].unique_id;
        cout << "\n\t\t\t Product Name : "<<vec1[i].iname;
        cout << "\n\t\t\t Price : "<<vec1[i].price;
        cout << "\n\t\t\t Discounted Price : "<<vec1[i].discounted_price;
        cout << "\n\t\t\t Quantity : "<<vec1[i].quantity;
        T+=vec1[i].price*vec1[i].quantity;
        DisCountedPrice += vec1[i].discounted_price*vec1[i].quantity;

    }

    string n;
    system("cls");
    cout<<"\n\t\t\t\t\t\tElectronic-Reciept";
    cout<<"\n\t\t\t\t\t_________________________________";
    cout << "\n\n\n\t\t\tCustomer Name : "<<name;
    cout << "\n\n\t\t\tCustomer Mobile Number : "<<phn;
    cout << "\n\n\t\t\tCustomer Address : "<<address;
    cout<<"\n\n\t\t\t------------------------------------";
    cout << "\n\n\t\t\tTotal Amount : "<<T;
    cout << "\n\n\t\t\tDiscount : "<<T-DisCountedPrice;
    cout << "\n\n\t\t\tGST : 18%";
    cout << "\n\n\t\t\tTotal Amount Payable : "<<(DisCountedPrice)+(DisCountedPrice*0.18);

    ofstream f2("Bill.txt",ios::app);
    f2<<"Customer Name: "<<name<<endl<<"Customer Mobile Number: "<<phn<<endl<<"Customer Address: "<<address<<endl<<"Total Amount Payable: "<<(DisCountedPrice)+(DisCountedPrice*0.18);

    cout<<"\n\t\t\t____________________________________";
    cout << "\n\n\t\t\tPress 1 to make Payment";
    cout << "\n\t\t\tPress 2 to Go to MAIN MENU";
    cout << "\n\t\t\tEnter your Choice:";
    cin >> n;

    if (n=="1"){
        pay();
    }
    else if (n=="2"){
        menu();
    }
    else{
        bill();
    }
}

void cartss :: pay(){
    string n;
    system("cls");
     cout<<"\n\t\t\t\t\tPAYMENT";
    cout<<"\n\t\t\t\t_________________________";

    cout<<"\n\n\n\n\t\t\t1) Cash On Delivery";
    cout<<"\n\n\t\t\t2) Pay Using Debit Card ";
    cout<<"\n\n\t\t\t3) Exit";
    cout<<"\n\n\n\t\t\tSelect Payment option:";
    cin >> n;
    if (n=="1"){
        cod();
    }
    else if (n=="2"){
            debit();
    }
    else if (n=="3"){
        system("cls");
        cout<<"Thankyou! for visiting us :)!\n\n\n\n\n";
    }
    else {
        pay();
    }
}

void cartss :: cod(){
    system("cls");
    cout<<"\n\n\n\t\t\tPayment Mode selected successfully!"<<endl<<endl;
    cout <<"\n\t\t\tYour order will be delivered at- "<<address<< "   ASAP:)"<<endl;
    cout << endl<<endl<<endl<<endl;
}

void cartss :: debit(){
    DC d;
    int n;
    cout<<"\n\t\t\tYour Payment is successfull!";
    cout << endl<<endl<<endl<<endl;
}

void cartss :: Remove(){
    string rem;
    cout << "\t\t\tEnter the code of Removable : ";
    cin >> rem;
    vector <Item> temp;
    for(int i=(vec1.size()-1);i>=0;i--){
        if (vec1[i].unique_id != rem){
            temp.push_back(vec1[i]);
            vec1.pop_back();
        }
        else{
            vec1.pop_back();
        }
    }
    for(int i=(temp.size()-1);i>=0;i--){
        vec1.push_back(temp[i]);
        temp.pop_back();
    }
    cart_function(vec1);
}
