// Developer: Benjamin Foreman
// Date: 4/12/2021
// Description: Description: Program that simlulates purchase of surfboards from a surf shop. Allows the user to select items to purchase, view
//              items selected, and view price totals of items selected.
// Update 4/13/2021: Added an XXX Small size of surfboard.

#include <iostream>
#include <iomanip>
using namespace std;

void showUsage()
{
    // simple print statement to display accepted inputs
    cout << "To show program usage \'S\'" << endl
        << "To purchase a surfboard press \'P\'" << endl
        << "To display current purchases press \'C\'" << endl
        << "To display total amount due press \'T\'" << endl
        << "To quit the program press \'Q\'" << endl << endl;
}

void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXSmall)
{
    // initialize variables then print prompt for user input
    int quantity = 0;
    char type;
    cout << "Please enter the quantity and type (S=small, M=medium, L=large, X=XXX-Small) of surfboard you would like to purchase: ";
    cin >> quantity >> type;
    // branching else if statement that adds quantity to totals based on type
    if (type == 's' || type == 'S')
    {
        iTotalSmall += quantity;
    }
    else if (type == 'x' || type == 'X')
    {
        iTotalXSmall += quantity;
    }
    else if (type == 'm' || type == 'M')
    {
        iTotalMedium += quantity;
    }
    else if (type == 'l' || type == 'L')
    {
        iTotalLarge += quantity;
    }
    cout << endl;
}

void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXSmall)
{
    // if statement chain that displays totals of surfboards selected for purchase if total is greater than 0
    if (iTotalSmall > 0)
    {
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    }
    if (iTotalXSmall > 0)
    {
        cout << "The total number of xxx-small surfboards is " << iTotalXSmall << endl;
    }
    if (iTotalMedium > 0)
    {
        cout << "The total number of medium surfboards is " << iTotalMedium << endl;
    }
    if (iTotalLarge > 0)
    {
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    }
    if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && iTotalXSmall == 0)
    {
        cout << "No purchases made yet." << endl;
    }
    cout << endl;
}

void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXSmall)
{
    // price constants
    const double BOARD_XSMALL = 50.00;
    const double BOARD_SMALL = 175.00;
    const double BOARD_MED = 190.00;
    const double BOARD_LARGE = 200.00;
    // total price variables
    double xSmallTotal = 0.00;
    double smallTotal = 0.00;
    double medTotal = 0.00;
    double largeTotal = 0.00;
    double grandTotal = 0.00;
    cout << setprecision(2) << fixed;

    // if statement chain that sets and displays cost of purchase of total is greater than 0
    if (iTotalSmall > 0)
    {
        smallTotal = iTotalSmall * BOARD_SMALL;
        cout << "The total number of small surfboards is " << iTotalSmall << "at a total of $" << smallTotal << endl;
    }
    if (iTotalXSmall > 0)
    {
        xSmallTotal = iTotalXSmall * BOARD_XSMALL;
        cout << "The total number of xxx-small surfboards is " << iTotalXSmall << "at a total of $" << xSmallTotal << endl;
    }
    if (iTotalMedium > 0)
    {
        medTotal = iTotalMedium * BOARD_MED;
        cout << "The total number of medium surfboards is " << iTotalMedium << "at a total of $" << medTotal << endl;
    }
    if (iTotalLarge > 0)
    {
        largeTotal = iTotalLarge * BOARD_LARGE;
        cout << "The total number of large surfboards is " << iTotalLarge << "at a total of $" << largeTotal << endl;
    }
    if (iTotalSmall > 0 || iTotalMedium > 0 || iTotalLarge > 0 || iTotalXSmall > 0)
    {
        grandTotal = smallTotal + medTotal + largeTotal + xSmallTotal;
        cout << "Amount due: $" << grandTotal << endl;
    }
    if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && iTotalXSmall == 0)
    {
        cout << "No purchases made yet." << endl;
    }

    cout << endl;
}


int main()
{


    // top banner
    cout << setfill('*')
        << setw(62) << '\n'
        << setw(56) << " Welcome to my Johnny Utah's PointBreak Surf Shop " << setw(6) << '\n'
        << setw(62) << '\n' << endl << endl;

    //first show usage to tell user how to use progam, has option to be called again in later for loop
    showUsage();

    //intialization of selection and total prices variables
    char selection;
    int iTotalXSmall = 0;
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;

    for (;;)
    {
        cout << "Please enter selection: ";
        cin >> selection;
        if (selection == 's' || selection == 'S')
        {
            showUsage();
        }
        else if (selection == 'p' || selection == 'P')
        {
            MakePurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXSmall);
        }
        else if (selection == 'c' || selection == 'C')
        {
            DisplayPurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXSmall);
        }
        else if (selection == 't' || selection == 'T')
        {
            DisplayTotal(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXSmall);
        }
        else if (selection == 'q' || selection == 'Q')
        {
            break;
        }
        else
        {
            cout << "Please enter valid selection" << endl << endl;
        }
    }

    cout << "Thank you" << endl;
    system("pause");
    return 0;
}

