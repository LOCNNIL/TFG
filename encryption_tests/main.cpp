#include <bits/stdc++.h>
#include <fstream>
 
// encdec class with encrypt() and
// decrypt() member functions
class encdec {
    int key;
 
    // File name to be encrypt
    std::string file = "geeksforgeeks.txt";
    char c;
 
public:
    void encrypt();
    void decrypt();
};
 
// Definition of encryption function
void encdec::encrypt()
{
    // Key to be used for encryption
    std::cout << "key: ";
    std::cin >> key;
 
    // Input stream
    std::fstream fin, fout;
 
    // Open input file
    // ios::binary- reading file
    // character by character
    fin.open(file, std::fstream::in);
    fout.open("encrypt.txt", std::fstream::out);
 
    // Reading original file till
    // end of file
    while (fin >> std::noskipws >> c) {
        int temp = (c + key);
 
        // Write temp as char in
        // output file
        fout << (char)temp;
    }
 
    // Closing both files
    fin.close();
    fout.close();
}
 
// Definition of decryption function
void encdec::decrypt()
{
    std::cout << "key: ";
    std::cin >> key;
    std::fstream fin;
    std::fstream fout;
    fin.open("encrypt.txt", std::fstream::in);
    fout.open("decrypt.txt", std::fstream::out);
 
    while (fin >> std::noskipws >> c) {
 
        // Remove the key from the
        // character
        int temp = (c - key);
        fout << (char)temp;
    }
 
    fin.close();
    fout.close();
}
 
// Driver Code
int main()
{
    encdec enc;
    char c;
    std::cout << "\n";
    std::cout << "Enter Your Choice : -> \n";
    std::cout << "1. encrypt \n";
    std::cout << "2. decrypt \n";
    std::cin >> c;
    std::cin.ignore();
 
    switch (c) {
    case '1': {
        enc.encrypt();
        break;
    }
    case '2': {
        enc.decrypt();
        break;
    }
    }
}