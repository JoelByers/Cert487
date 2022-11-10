#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Cert487.h"

using namespace std;

Cert487::Cert487(string fileName){
    ifstream fileIn;
    fileIn.open(fileName);
    string input;

    for(int i = 0; i < 15; i++){
        fileIn >> input;

        switch(i){
            case 0: version = stoi(input);
            break;
            case 1: serialNumber = stoi(input);
            break;
            case 2: signatureAlgorithmIdentity = input;
            break;
            case 3: signatureAlgorithmParameters = input;
            break;
            case 4: issuerName = input;
            break;
            case 5: validNotBefore = stoi(input);
            break;
            case 6: validNotAfter = stoi(input);
            break;
            case 7: subjectName = input;
            break;
            case 8: publicKeyAlgorithm = input;
            break;
            case 9: publicKeyParameters = input;
            break;
            case 10: publicKey = stoi(input);
            break;
            case 11: issuerUniqueIdentifier = input;
            break;
            case 12: extensions = input;
            break;
            case 13: signatureAlgorithm = input;
            break;
            case 14: signatureParameters = input;
            break;
            default: cerr << "Error: Invalid Certificate File\n";
        }
    }
}

void Cert487::printLine(string label, string data){
    cout << setw(30) << left << label << setw(1) << ": " << data << "\n";
}

void Cert487::print(){
    printLine("Version", to_string(version));
    printLine("serialNumber", to_string(serialNumber));
    printLine("signatureAlgorithmIdentity", signatureAlgorithmIdentity);
    printLine("signatureAlgorithmParameters", signatureAlgorithmParameters);
    printLine("issuerName", issuerName);
    printLine("validNotBefore", to_string(validNotBefore));
    printLine("validNotAfter", to_string(validNotAfter));
    printLine("subjectName", subjectName);
    printLine("publicKeyAlgorithm", publicKeyAlgorithm);
    printLine("publicKeyParameters", publicKeyParameters);
    printLine("publicKey", to_string(publicKey));
    printLine("issuerUniqueIdentifier", issuerUniqueIdentifier);
    printLine("extensions", extensions);
    printLine("signatureAlgorithm", signatureAlgorithm);
    printLine("signatureParameters", signatureParameters);
    printLine("signature", signature);
}