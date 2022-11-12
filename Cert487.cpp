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
    string parsedInput[2] = {"", ""};

    while(!fileIn.eof()){
        fileIn >> input;
        parseCertLine(input, parsedInput);

        if(parsedInput[0].compare("version") == 0){
            version = stoi(parsedInput[1]);
        }
        else if(parsedInput[0].compare("serialNumber") == 0){
            serialNumber = stoi(parsedInput[1]);
        }
        else if(parsedInput[0].compare("signatureAlgorithmIdentity") == 0){
            signatureAlgorithmIdentity = parsedInput[1];
        }
        else if(parsedInput[0].compare("signatureAlgorithmParameters") == 0){
            signatureAlgorithmParameters = parsedInput[1];
        }
        else if(parsedInput[0].compare("issuerName") == 0){
            issuerName = parsedInput[1];
        }
        else if(parsedInput[0].compare("validNotBefore") == 0){
            validNotBefore = stoi(parsedInput[1]);
        }
        else if(parsedInput[0].compare("validNotAfter") == 0){
            validNotAfter = stoi(parsedInput[1]);
        }
        else if(parsedInput[0].compare("subjectName") == 0){
            subjectName = parsedInput[1];
        }
        else if(parsedInput[0].compare("publicKeyAlgorithm") == 0){
            publicKeyAlgorithm = parsedInput[1];
        }
        else if(parsedInput[0].compare("publicKeyParameters") == 0){
            publicKeyParameters = parsedInput[1];
        }
        else if(parsedInput[0].compare("publicKey") == 0){
            publicKey = stoi(parsedInput[1]);
        }  
        else if(parsedInput[0].compare("issuerUniqueIdentifier") == 0){
            issuerUniqueIdentifier = parsedInput[1];
        }      
        else if(parsedInput[0].compare("extensions") == 0){
            extensions = parsedInput[1];
        }   
        else if(parsedInput[0].compare("signatureAlgorithm") == 0){
            signatureAlgorithm = parsedInput[1];
        }   
        else if(parsedInput[0].compare("signatureParameters") == 0){
            signatureParameters = parsedInput[1];
        }
        else{
            cerr << "Invalid Certificate Field \"" << parsedInput[0] << "\"\n";
        }        
    }

    fileIn.close();
}

void Cert487::parseCertLine(string input, string output[2]){
    output[0] = input.substr(0, input.find("="));
    output[1] = input.substr(input.find("=") + 1, input.length() - 1);
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

void Cert487::writeLineToFile(ofstream &fileOut, string label, string data){
    fileOut << label << "=" << data << "\n";
}

void Cert487::writeToFile(string fileName){
    ofstream fileOut;
    fileOut.open(fileName);
    
    writeLineToFile(fileOut, "Version", to_string(version));
    writeLineToFile(fileOut, "serialNumber", to_string(serialNumber));
    writeLineToFile(fileOut, "signatureAlgorithmIdentity", signatureAlgorithmIdentity);
    writeLineToFile(fileOut, "signatureAlgorithmParameters", signatureAlgorithmParameters);
    writeLineToFile(fileOut, "issuerName", issuerName);
    writeLineToFile(fileOut, "validNotBefore", to_string(validNotBefore));
    writeLineToFile(fileOut, "validNotAfter", to_string(validNotAfter));
    writeLineToFile(fileOut, "subjectName", subjectName);
    writeLineToFile(fileOut, "publicKeyAlgorithm", publicKeyAlgorithm);
    writeLineToFile(fileOut, "publicKeyParameters", publicKeyParameters);
    writeLineToFile(fileOut, "publicKey", to_string(publicKey));
    writeLineToFile(fileOut, "issuerUniqueIdentifier", issuerUniqueIdentifier);
    writeLineToFile(fileOut, "extensions", extensions);
    writeLineToFile(fileOut, "signatureAlgorithm", signatureAlgorithm);
    writeLineToFile(fileOut, "signatureParameters", signatureParameters);
    writeLineToFile(fileOut, "signature", signature);

    fileOut.close();
}