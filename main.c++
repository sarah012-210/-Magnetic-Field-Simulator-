#include <iostream>
#include <cmath>
#include <string>
using namespace std;
float pi = 3.141592654;
float M = 4 * pi * pow(10, -7);
int main()
{
    float I, R, Bf, BTi, BTj, BTk, BT, B, F, ceta1, ceta2, ceta, n, N, L, I1, I2, d;
    BTi = 0;
    BTj = 0;
    BTk = 0;
check:
    cout << "choose  what do you want to calculate \n"
         << "1-magnetic field \n"
         << "2-mutual force between two long parallel wires \n"
         << "3-current\n";
    int k;
    cin >> k;
    while (k != 1 && k != 2 && k != 3)
    {
        cout << "wrong choise, please try again and choose 1 or 2 or 3\n";
        cin >> k;
    }
choose:
    if (k == 1) // magnetic field
    {
        cout << " what is magnetic field due to :\n"
             << "1-wire \n"
             << "2-circular arc \n"
             << "3-solenoid\n"
             << "4-toroid\n";
        int x;
        cin >> x;
        {
            while (x != 1 && x != 2 && x != 3 && x != 4 && x != 5)
            {
                cout << "wrong choise , please try again and choose 1 or 2 or 3 or 4 \n";
                cin >> x;
            }

            if (x == 1) // wire
            {
                cout << "choose type of wire : \n"
                     << "1-finit wire \n"
                     << "2-long wire\n"
                     << "3-semi long wire\n";
                int c;
                cin >> c;
                while (c != 1 && c != 2 && c != 3)
                {
                    cout << "wrong choise , please try again and choose 1 or 2 or 3 \n";
                    cin >> c;
                }

                if (c == 1)
                {
                    cout << "Enter current, radius , ceta1 by degree  and ceta2 by degree respectively\n";
                    cin >> I >> R >> ceta1 >> ceta2;
                    B = M * I * fabs(cos(ceta1 * pi / 180) - cos(ceta2 * pi / 180)) / (4 * pi * R);
                    cout << "B= " << B << " tesla" << endl;
                }
                else if (c == 2)
                {
                    cout << "Enter current and radius repectively\n ";
                    cin >> I >> R;
                    B = M * I / (2 * pi * R);
                    cout << "B= " << B << " tesla" << endl;
                }
                else if (c == 3)
                {
                    cout << "Enter current , radius and ceta1 by degree respectively\n";
                    cin >> I >> R >> ceta1;
                    B = M * I * (cos(ceta1 * pi / 180) + 1) / (4 * pi * R);
                    cout << "B= " << B << " tesla" << endl;
                }
            }
            else if (x == 2) // arc
            {
                cout << "Enter current , radius and ceta by degree respectively\n";
                cin >> I >> R >> ceta;
                B = M * I * (ceta * pi / 180) / (4 * pi * R);
                cout << "B=" << B << " tesla" << endl;
            }
            else if (x == 3) // solenoid
            {
                cout << "Enter current and number of turns per unit length respectively\n";
                cin >> I >> n;
                B = M * n * I;
                cout << "B= " << B << " tesla" << endl;
            }
            else if (x == 4) // toroid
            {
                cout << "Enter current , number of turns and radius\n";
                cin >> I >> N >> R;
                B = M * N * I / (2 * pi * R);
                cout << "B= " << B << " tesla" << endl;
            }
        }
        cout << "Enter the direction of the field\n"
             << "1- +i\t" << "2- -i\t" << "3- +j\t" << "4- -j\t" << "5- +k\t" << "6- -k\n";
        int z;
        cin >> z;
        if (z == 1)
            cout << "B=" << B << "i tesla\n";
        else if (z == 2)
        {
            B = -B;
            cout << "B=" << B << "i tesla\n";
        }
        else if (z == 3)
            cout << "B=" << B << "j tesla\n";
        else if (z == 4)
        {
            B = -B;
            cout << "B=" << B << "j tesla\n";
        }
        else if (z == 5)
            cout << "B=" << B << "k tesla\n";
        else if (z == 6)
        {
            B = -B;
            cout << "B=" << B << "k tesla\n";
        }
        if (z == 1 || z == 2)
            BTi = BTi + B;
        if (z == 3 || z == 4)
            BTj = BTj + B;
        if (z == 5 || z == 6)
            BTk = BTk + B;
        BT = sqrt((BTi * BTi + BTj * BTj + BTk * BTk));
        cout << "BT=" << BTi << "i +" << BTj << "j +" << BTk << "k  " << "tesla\n"
             << "|BT|=" << BT << endl;
        cout << "Do you want to solve another magnetic field \n"
             << "1-yes\t" << "2-No\t";
        int q;
        cin >> q;
        if (q == 1)

            goto choose;

        else
            goto start;
    }
    if (k == 2) // mutual force
    {
        cout << "Enter current 1 , current 2 , length and distance between wirs , repectively\n";
        cin >> I1 >> I2 >> L >> d;
        F = M * I1 * I2 * L / (2 * pi * d);
        cout << "F=" << F << " newton" << endl;
    }
    if (k == 3) // current
    {
        cout << "choose for which do you want :\n"
             << "1-finit wire \n"
             << "2-long wire \n"
             << "3-semi long wire\n"
             << "4-circular arc\n"
             << "5-solenoid\n"
             << "6-toroid\n";
        int s;
        cin >> s;
        while (s != 1 && s != 2 && s != 3 && s != 4 && s != 5 && s != 6)
        {
            cout << "wrong choise , please try again and choose only from 1or 2 or 3 or 4 or 5 or 6 \n";
            cin >> s;
        }
        if (s == 1) // finit wire
        {
            cout << "Enter magnetic field, radius , ceta1 by degree and ceta2 by degree  respectively\n";
            cin >> B >> R >> ceta1 >> ceta2;
            I = 4 * pi * R * B / (M * (cos(ceta1 * pi / 180) - cos(ceta2 * pi / 180)));
            cout << "I=" << I << "ampere" << endl;
        }
        else if (s == 2)
        {
            cout << "Enter magnetic field and radius respectively\n";
            cin >> B >> R;
            I = 2 * pi * R * B / M;
            cout << "I=" << I << "ampere" << endl;
        }
        else if (s == 3)
        {
            cout << "Enter magnetic feild , radius and ceta1by degree respectively\n";
            cin >> B >> R >> ceta1;
            I = B * 4 * pi * R / (M * (cos(ceta1 * pi / 180) + 1));
            cout << "I=" << I << "ampere" << endl;
        }
        else if (s == 4)
        {
            cout << "Enter magnetic feild , radius and ceta by radian respectively\n";
            cin >> B >> R >> ceta;
            I = 4 * pi * R * B / (M * ceta);
            cout << "I= " << I << "ampere" << endl;
        }
        else if (s == 5)
        {
            cout << "Enter magnetic field and number of turns per unit length respectively\n";
            cin >> B >> n;
            I = B / (n * M);
            cout << "I= " << I << "ampere" << endl;
        }
        else if (s == 6)
        {
            cout << "Enter magnetic field , radius and number of turns respectively\n";
            cin >> B >> R >> N;
            I = 2 * pi * R * B / (M * N);
            cout << "I=" << I << "ampere" << endl;
        }
    }
start:
    cout << "Do you want to solve another question\n"
         << "1-no\t" << "2-yes\t";
    int t;
    cin >> t;
    if (t == 1)
        return 0;
    else
        goto check;
}